#include "LMS.h"
#include <conio.h>
#include <ctime>
#include <string.h>

LMS::LMS()
{
	//Initial Date of LMS
	Date = "01/01/01";

	counter = 0;

	//Open files
	//Students
	StudentFile.open("StudentsData.txt");
	//Books
	BookFile.open("BookCopiesData.txt");
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

//Student reading
	Student stutemp;
	while (StudentFile >> stutemp)
	{
		StudentList.push_back(stutemp);
	}

	//Book copy reading
	BookCopy booktemp;
	while (BookFile >> booktemp)
	{
		CopyList.push_back(booktemp);
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
	return Date;
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
	Date = date;
}

void LMS::incrementDate()
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
		return;
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
		return;
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
}