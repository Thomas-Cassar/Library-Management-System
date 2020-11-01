#include "LMS.h"
#include <conio.h>
#include <ctime>
#include <string.h>

LMS::LMS()
{
	//Initial Date of LMS
	LMSDate = "01/01/01";

	counter = 0;

	//Open files
	//Students
	StudentFile.open("student.txt");
	//Books
	BookFile.open("book.txt");
	//Check successful
	if (StudentFile.fail())
	{
		std::cerr << "Could not open student file";
		exit(1);
	}
	if (BookFile.fail())
	{
		std::cerr << "Could not open book file";
		exit(1);
	}

	//Read from files and store in vectors
	//Book copy reading
	BookCopy booktemp;
	while (BookFile >> booktemp)
	{
		CopyList.push_back(booktemp);
	}

//Student reading
	Student stutemp;
	while (StudentFile >> stutemp)
	{	
		std::vector<BookCopy> tempbooklist;
	
		for (int i = 0; i < CopyList.size(); i++)
		{
			if (CopyList[i].getReaderName() == stutemp.GetUser())
				tempbooklist.push_back(CopyList[i]);
		}
		stutemp.SetBorrowedBooks(tempbooklist);
		StudentList.push_back(stutemp);
	}

}

LMS::~LMS()
{
	//Close all files on class destruction
	StudentFile.close();
	BookFile.close();
}



Student LMS::LogIn()
{


	std::string tempusr = "", temppswd = "";
	char c;

	std::cout << "Enter user name:" << std::endl;
	std::cin >> tempusr;
	std::cout << "Enter password:" << std::endl;

	while (((c = _getch()) != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{
			temppswd = temppswd.substr(0, temppswd.length() - 1);
			std::cout  << '\b';
			std::cout << ' ';
			std::cout << '\b';
		}
		else {
			temppswd += c;
			std::cout << "*";
		}
	}
	std::cout << std::endl;

	//Loop through all students
	for (auto& i : StudentList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())
			{
				return i;
			}
			else
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}

	//Loop through all teachers



	std::cout << "User not found" << std::endl;
	exit(0);
}

void LMS::PrintCommands()
{
	    std::cout << "Enter a command from the list below:" << std::endl;
		std::cout << "\t1. Get Recommended Books" << std::endl;
		std::cout << "\t2. Borrow Books" << std::endl;
		std::cout << "\t3. Return Books" << std::endl;
		std::cout << "\t4. Check Current Date" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
}

std::vector<BookCopy>* LMS::returnBookCopy()
{
	return &CopyList;
}


void LMS::incCounter()
{
	counter++;
}

std::string LMS::getDate()
{
	return LMSDate;
}

void LMS::setCounter(int counter)
{
	this->counter = counter;
}

int LMS::getCounter()
{
	return counter;
}

void LMS::setDate(std::string date)
{
	LMSDate = date;
}

void LMS::updateFiles()
{
	BookFile.close();
	StudentFile.close();

	//Open files
	//Students
	StudentFile.open("student.txt", std::ofstream::out | std::ofstream::trunc);
	//Books
	BookFile.open("book.txt",std::ofstream::out | std::ofstream::trunc);
	//Check successful
	if (StudentFile.fail())
	{
		std::cerr << "Could not open student file";
		exit(1);
	}
	if (BookFile.fail())
	{
		std::cerr << "Could not open book file";
		exit(1);
	}

	int i;
	for (i=0; i<StudentList.size();i++)
	{
		StudentFile << StudentList[i];
	}

	for (i = 0; i < CopyList.size(); i++)
	{
		BookFile << CopyList[i];
	}
}

std::string LMS::incrementDate(std::string Date)
{
	std::string defaultDate = "01/01/00";
	int i = 0;
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + (Date[7] - '0')) % 4 == 0)
	{
		if (Date[3] == '2' && Date[4] == '9')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return Date;
	}
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + Date[7] - '0') % 4 != 0)
	{
		if (Date[3] == '2' && Date[4] == '8')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return Date;
	}
	if ((Date[1] == '4' || Date[1] == '6' || Date[1] == '9' || (Date[0] == '1' && Date[1] == '1')))
	{
		if (Date[3] == '3' && Date[4] == '0')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
	}
	else
	{
		if (Date[3] == '3' && Date[4] == '1')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[0] == '1' && Date[1] == '2')
			{
				for (i = 0; i < 6; i++)
				{
					Date[i] = defaultDate[i];
				}
				if (Date[6] == '9' && Date[7] == '9')
				{
					Date = defaultDate;
				}
				else
				{
					if (Date[7] == '9')
					{
						Date[7] = '0';
						Date[6]++;
					}
					else
					{
						Date[7]++;
					}
				}
			}
			else
			{
				if (Date[1] == '9')
				{
					Date[0] = '1';
					Date[1] = '0';
				}
				else
					Date[1]++;
			}
		}
		else
		{
			if (Date[4] == '9')
			{

				Date[4] = '0';
				Date[3]++;

			}
			else
				Date[4]++;
		}
	}
	return Date;
}

void LMS::recommend(Student& s1)
{
	std::vector <BookCopy> category;
	std::vector <BookCopy> temp = CopyList;

	for (int i = 0; i < s1.GetBorrowedBooks().size(); i++)
	{
		category.push_back(s1.GetBorrowedBooks()[i]);
	}
	int count = 0;
	int maxcount = 0, position = 0;
	for (int i = 0; i < category.size(); i++)
	{
		for (int j = i+1; j < category.size();j++)
			if (category[i].getCategory() == category[j].getCategory() && category[j].getCategory() != "")
			{
				category[j].setCategory("");
		    }
	}
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (temp[i].getTitle() == temp[j].getTitle() && temp[j].getCategory() != "")
			{
				temp[j].setTitle("");
			}
		}
	}
	std::cout << "Some Books You May Like: " << std::endl;
	for (int j = 0; j < category.size();j++)
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getTitle() != "" && (category[j].getCategory() == CopyList[i].getCategory()) && (temp[i].getReaderName() == "NULL") && (category[j].getTitle() != temp[i].getTitle()))
		{
			std::cout << temp[i].getTitle() << " by " << temp[i].getAuthor() << std::endl;
			count++;
		}
	}
	if (count == 0 && s1.GetBorrowedBooks().size() == 0)
	{
		std::cout << "Please borrow a book so that we can get an idea of what you like!" << std::endl;
	}
	else if (count == 0 && s1.GetBorrowedBooks().size() != 0)
	{
		std::cout << "There are no books that match the categories of the books you have borrowed!" << std::endl;
	}
}
