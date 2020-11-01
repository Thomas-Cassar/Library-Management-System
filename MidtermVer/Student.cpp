#include "Student.h"
#include <iostream>
#include "BookCopy.h"
#include <vector>
#include <ctime>
#include <string>
#include "LMS.h"

/**
 * default Student constructor
 * creates a new Student object
 * sets Username and Password to "NULL"
 * sets MaxBorrowed to 5
 * sets MaxBorrowedCurrent to 5
 * sets maxBorrowDate to 30
 */
Student::Student()
{
	//Default values that should be overwritten by reading in from a file
	Username = "NULL";
	Password = "NULL";
	MaxBorrowed = 5;
	MaxBorrowedCurrent = 5;
	maxBorrowDate = 30;
}

/**
 * parameterized Student constructor
 * creates a new Student object
 * @param user - string
 * @param pswd - string
 * sets Username to param user
 * sets Password to param pswd
 * sets MaxBorrowed to 5
 * sets MaxBorrowedCurrent to 5
 * sets maxBorrowDate to 30
 */
Student::Student(std::string user, std::string pswd)
{
	//Set vars from parameters
	Username = user;
	Password = pswd;

	//Default values that should be overwritten by reading in from a file
	MaxBorrowed = 5;
	MaxBorrowedCurrent = 5;
	maxBorrowDate = 30;
	
}

/**
 * sets Username of current Student object to param usr
 * @param usr - string
 */
void Student::SetUser(std::string usr)
{
	Username = usr;
}

/**
 * sets Password of current Student object to param pswd
 * @param pswd - string
 */
void Student::SetPswd(std::string pswd)
{
	Password = pswd;
}

//
/**
 * sets StudentBorrowedBooks vector of current Student object
 *  to param bBooks
 * @param bBooks - vector<BookCopy>
 */
void Student::SetBorrowedBooks(std::vector<BookCopy> bBooks)
{
	this->StudentBorrowedBooks = bBooks;
}

/**
 * sets MaxBorrowed of current Student object to param maxBorrowed
 * @param maxBorrowed - int
 */
void Student::SetMaxBorrowed(int maxBorrowed)
{
	this->MaxBorrowed = maxBorrowed;
}

/**
 * sets MaxBorrowedCurrent of current Student object to param maxBorrowedCurrent
 * @param maxBorrowedCurrent - int
 */
void Student::SetMaxBorrowedCurrent(int maxBorrowedCurrent)
{
	this->MaxBorrowedCurrent = maxBorrowedCurrent;
}
//

/**
 * @return string - Username of current Student object
 */
std::string Student::GetUser()
{
	return Username;
}

/**
 * @return string - Password of current Student object
 */
std::string Student::GetPswd()
{
	return Password;
}

/**
 * @return vector<BookCopy> - StudentBorrowedBooks of 
 *  current Student object
 */
//
std::vector<BookCopy> Student::GetBorrowedBooks()
{
	return this->StudentBorrowedBooks;
}

/**
 * @return int - MaxBorrowed of current Student object
 */
int Student::GetMaxBorrowed()
{
	return this->MaxBorrowed;
}

/**
 * @return int - MaxBorrowedCurrent of current Student object
 */
int Student::GetMaxBorrowedCurrent()
{
	return MaxBorrowedCurrent;
}
//
/**
 * @return int - maxBorrowDate of current Student object
 */
int Student::GetMaxBorrowDate()
{
	return maxBorrowDate;
}

/**
 * sets maxBorrowDate of current Student object to param maxBorrowDate
 * @param maxBorrowDate - int
*/
void Student::SetMaxBorrowDate(int maxBorrowDate)
{
	this->maxBorrowDate = maxBorrowDate;
}

/*
* This fuction is called from the main loop if the user wants to borrow a book
*/
void Student::StudentBorrowBook(std::vector <BookCopy>& x, int date)
{
	std::string idValue = "";
	int i = 0;
	std::string reserveAnswer = "";

	for (int iter = 0; iter < float(clock()) / 1000; iter++)//Calculate the value for the current date
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;
	bool shouldreturn = false;

	//This function checks to see if any books are overdue
	//If said book is overdue then MaxBorrowed is decremented and no new book is allowed to be taken out
	for (i = 0; i < StudentBorrowedBooks.size(); i++)
	{
		if (current_date > StudentBorrowedBooks[i].get_exp_date())
		{
			std::cout << StudentBorrowedBooks[i].getTitle() << " is overdue! Please return the book!" << std::endl;

			shouldreturn = true;
		}
		
	}
	if (shouldreturn)
		return;

	//This function checks to see if we are already over the limit for books allowed to be borrowed
	if (StudentBorrowedBooks.size() >= MaxBorrowedCurrent)
	{
		std::cout << "You have already reached the limit of borrowed copies" << std::endl;
		return;
	}

	//If here is reached then the book is allowed to be borrowed and we ask what they want to borrow
	std::cout << "Enter ID of the copy of the book you want to borrow: ";
	std::cin >> idValue;
	for (i = 0; i < x.size(); i++)//Loop through book copy vector
	{
		if (idValue == x[i].getID())//Case where the book is in the copy vector
		{
			if (x[i].getReaderName() == "NULL")//Case where the book is not taken out
			{
				x[i].setReaderName(Username);
				x[i].set_start_date(current_date);
				x[i].set_exp_date(current_date + maxBorrowDate);
				StudentBorrowedBooks.push_back(x[i]);
				std::cout << x[i].getTitle() << " has been successfully borrowed!" << std::endl;

				return;
			}
			else //Case when someone else has the book taken out
			{
				std::cout << "This book is taken out!" << std::endl << std::endl;
				return;
			}
		}
	}
	//Case where the book ID is not found in the copy vector
	std::cout << "Invalid book ID!" << std::endl;
}

/**
 * prints relevant info for a Student object
 */
void Student::Print()
{
	std::cout << std::endl;
	std::cout << "Username: " << Username << std::endl;
	std::cout << "Password: " << Password << std::endl;
	std::cout << "Maximum Books You can Borrow out of Original Maximum: " << MaxBorrowedCurrent <<'/'<<MaxBorrowed<< std::endl;
	std::cout << "Maximum Borrowing Time: " << maxBorrowDate << " days" << std::endl;
	std::cout << "Books You have Borrowed: " << std::endl;
	for (int i = 0; i < StudentBorrowedBooks.size(); i++)//Prints all books reader has taken out
	{
		std::cout << StudentBorrowedBooks[i].getTitle() << std::endl;
	}
}

/**
 * used to return books to library system from Student
 */
void Student::ReturnBooks(std::vector<BookCopy>& x, int date)
{
	//First we calculate the value of the date
	std::string idValue = "";
	int i = 0,j;
	std::string reserveAnswer = "";

	for (int iter = 0; iter < float(clock()) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;

	std::cout << "Enter the ID of the book you want to return: " << std::endl;
	std::string id;
	std::cin >> id;
	for (i = 0; i < x.size(); i++)//Loop through all books
	{
		if (id == x[i].getID())//Check if this is ID we want
		{
			for (j = 0; j < StudentBorrowedBooks.size(); j++)//See if this reader has the book taken out
			{
				if (StudentBorrowedBooks[j].getID() == id)//Case where the reader does have the book taken out
				{
					//This function checks to see if any books are overdue
					//If said book is overdue then MaxBorrowed is decremented
					if (current_date > StudentBorrowedBooks[j].get_exp_date())//Case where the book was overdue
					{
						std::cout << StudentBorrowedBooks[j].getTitle() << " was overdue max books allowed to be taken out has been decreased" << std::endl;
						if (MaxBorrowedCurrent > 1)
						{
							MaxBorrowedCurrent--;
						}
					}
					else if (MaxBorrowedCurrent < MaxBorrowed)//Case where overdue and we add to max books allowed to be borrowed
					{
						std::cout << StudentBorrowedBooks[j].getTitle() << " was not overdue max books allowed to be taken out has been increased" << std::endl;
							MaxBorrowedCurrent++;
					}
					//Return book
					x[i].setReaderName("NULL");
					StudentBorrowedBooks.erase(StudentBorrowedBooks.begin() + j);
					std::cout << "Book was returned successfully!!" << std::endl;
					return;
				}
			}
			//Case where the student has not taken out this book
			std::cout << "You do not have this book borrowed!" << std::endl;
			return;
		}
	}
	//Case where the book ID is not valid
	std::cout << "Could not find the book to return!" << std::endl;
	return;
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
* a student
*/
std::ostream& operator << (std::ostream& out, Student& student)
{
	//Output all variables to ostream seperated by spaces
	out << 
		student.GetUser() << ' ' << 
		student.GetPswd() << ' ' << 
		student.GetMaxBorrowed() <<' ' << 
		student.GetMaxBorrowedCurrent() << ' '<<
		student.GetMaxBorrowDate() 
	<< std::endl;
	return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
* a student
*/
std::istream& operator >> (std::istream& in, Student& student)
{
	//Temp variables for reading in values
	std::string Username, Password;
	int maxborrow = 5, maxborrowcur=5, maxborrowper = 30;

	//Take in values from istream
	in >> 
		Username >> 
		Password >>
		maxborrow >> 
		maxborrowcur>>
		maxborrowper;

	
	//Set variables based on values taken in
	student.SetUser(Username);
	student.SetPswd(Password);
	student.SetMaxBorrowed(maxborrow);
	student.SetMaxBorrowedCurrent(maxborrowcur);
	student.SetMaxBorrowDate(maxborrowper);
	
	return in;
}