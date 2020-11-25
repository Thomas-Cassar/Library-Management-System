#include "LMS.h"
#include <conio.h>
#include <ctime>
#include <string.h>

/**
 * Constructor for class:
 * Opens files
 * Reads files and adds to the respective vector that we use to store the values
 */
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

	//Check if file opening was successful
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
	
		for (int i = 0; i < CopyList.size(); i++)//Loop through all books in vector to find books that this user has taken out
		{
			if (CopyList[i].getReaderName() == stutemp.GetUser())
				tempbooklist.push_back(CopyList[i]);
		}
		stutemp.SetBorrowedBooks(tempbooklist);//Add books that the user has taken out to that user
		StudentList.push_back(stutemp);//Add student to list of all active students
	}

}

/*
* Destructor for the class;
* Makes sure all opened files are closed
*/
LMS::~LMS()
{
	//Close all files on class destruction
	StudentFile.close();
	BookFile.close();
}


/**
 * LogIn Function:
 * Called at start of program after construction of an LMS class
 * Gets user input for password and username
 * If valid the function returns the address of the student that is logged in
 */
Student* LMS::LogIn()
{
	std::string tempusr = "", temppswd = "";//Vars for storing input
	char c;//Var for storing char read

	//Get username
	std::cout << "Enter user name:" << std::endl;
	std::cin >> tempusr;
	std::cout << "Enter password:" << std::endl;

	while (((c = _getch()) != '\r') && (c != '\n'))//This function gets the password and hides it with *
	{
		if (c == '\b')//Case where backspace is entered we move cursor back 1 and remove a * and a letter from the input password
		{
			temppswd = temppswd.substr(0, temppswd.length() - 1);
			std::cout  << '\b';
			std::cout << ' ';
			std::cout << '\b';
		}
		else {//Case where we add letter to the string password
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
			if (temppswd == i.GetPswd())//Case where the input is corrrect and we return the adress of the student
			{
				return &i;
			}
			else//Case where entered password is incorrect
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}

	//Case where entered username is not found
	std::cout << "User not found" << std::endl;
	exit(0);
}

/**
 * Prints all commands possible for the following user
 */
void LMS::PrintCommands()
{		
		std::cout << "************************************************"<<std::endl;
	    std::cout << "Enter a command from the list below:" << std::endl;
		std::cout << "\t1. Get Recommended Books" << std::endl;
		std::cout << "\t2. Borrow Books" << std::endl;
		std::cout << "\t3. Return Books" << std::endl;
		std::cout << "\t4. Check Current Date" << std::endl;
		std::cout << "\t5. View My Information" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
}

/**
 * @return vector<BookCopy> pointer - points to the list of books
 */
std::vector<BookCopy>* LMS::returnBookCopy()
{
	return &CopyList;
}

/**
 * Increments counter - the number of days since 01/01/01
 */
void LMS::incCounter()
{
	counter++;
}

/**
 * @return string - the string for LMSDate
 */
std::string LMS::getDate()
{
	return LMSDate;
}

/**
 * sets counter to param counter
 * @param counter - int
 */
void LMS::setCounter(int counter)
{
	this->counter = counter;
}

/**
 * @return int - number of days passed since 01/01/01
 */
int LMS::getCounter()
{
	return counter;
}

/**
 * sets date to param date
 * @param date - string
 */
void LMS::setDate(std::string date)
{
	LMSDate = date;
}

/*
*The following function overrides the existing files with the new data that is stored
* in the vectors studentlist and copylist
*/
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
	for (i=0; i<StudentList.size();i++)//Print all students to student file
	{
		StudentFile << StudentList[i];
	}

	for (i = 0; i < CopyList.size(); i++)//Print all copies to copy file
	{
		BookFile << CopyList[i];
	}
}

/*
*The following fuction increments the date and returns a string representing the
* current date
*/
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

/*
*The following function takes in a student by reference and based on the books it currently has taken out 
* it will recommend books of similar genres to any books it has taken out 
*/
void LMS::recommend(Student& s1)
{
	std::vector <BookCopy> category;
	std::vector <BookCopy> temp = CopyList;//makes new vector so that CopyList is not changed

	for (int i = 0; i < s1.GetBorrowedBooks().size(); i++)
	{
		category.push_back(s1.GetBorrowedBooks()[i]);
	}
	int count = 0;
	for (int i = 0; i < category.size(); i++)
	{
		for (int j = i+1; j < category.size();j++)
			if (category[i].getCategory() == category[j].getCategory() && category[j].getCategory() != "")
			{
				category[j].setCategory("");
		    }
	}
	for (int i = 0; i < temp.size(); i++)//removes duplicate copies from temp vector
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
	/*checks to see all books which match the categories of the books the stuedent has borrowed
	  and if the book has not been taken out
	*/
	for (int j = 0; j < category.size();j++)
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getTitle() != "" && (category[j].getCategory() == CopyList[i].getCategory()) && (temp[i].getReaderName() == "NULL") && (category[j].getTitle() != temp[i].getTitle()))
		{
			std::cout << temp[i].getTitle() << " by " << temp[i].getAuthor() << std::endl;
			count++;
		}
	}
	if (count == 0 && s1.GetBorrowedBooks().size() == 0)//Case where the reader has no books taken out
	{
		std::cout << "Please borrow a book so that we can get an idea of what you like!" << std::endl;
	}
	else if (count == 0 && s1.GetBorrowedBooks().size() != 0)//Case where the reader has a book taken out of a unique genre
	{
		std::cout << "There are no books that match the categories of the books you have borrowed!" << std::endl;
	}
}


