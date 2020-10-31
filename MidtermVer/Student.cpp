#include "Student.h"
#include <iostream>
#include "BookCopy.h"
#include <vector>
#include <ctime>
#include <string>
#include "LMS.h"

Student::Student()
{
	Username = "NULL";
	Password = "NULL";
	MaxBorrowed = 5;
	maxBorrowDate = 30;

	// also want to include maxBorrowingPeriods in the constructors?
}

Student::Student(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;

	// leaving comment blocks around the things I change - Eshan
	MaxBorrowed = 5;
	maxBorrowDate = 30;
	//
}


void Student::SetUser(std::string usr)
{
	Username = usr;
}

void Student::SetPswd(std::string pswd)
{
	Password = pswd;
}

//
void Student::SetBorrowedBooks(std::vector<BookCopy> bBooks)
{
	this->StudentBorrowedBooks = bBooks;
}

void Student::SetMaxBorrowed(int maxBorrowed)
{
	this->MaxBorrowed = maxBorrowed;
}
//

std::string Student::GetUser()
{
	return Username;
}

std::string Student::GetPswd()
{
	return Password;
}

//
std::vector<BookCopy> Student::GetBorrowedBooks()
{
	return this->StudentBorrowedBooks;
}

int Student::GetMaxBorrowed()
{
	return this->MaxBorrowed;
}
//
int Student::GetMaxBorrowDate()
{
	return maxBorrowDate;
}

/*
* 
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

	for (int iter = 0; iter < float(clock()) / 1000; iter++)
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
			MaxBorrowed--;
			shouldreturn = true;
		}
		
	}
	if (shouldreturn)
		return;

	//This function checks to see if we are already over the limit for books allowed to be borrowed
	if (StudentBorrowedBooks.size() >= MaxBorrowed)
	{
		std::cout << "You have already reached the limit of borrowed copies" << std::endl;
		return;
	}

	//If here is reached then the book is allowed to be borrowed and we ask what they want to borrow
	std::cout << "Enter ID of the copy of the book you want to borrow: ";
	std::cin >> idValue;
	for (i = 0; i < x.size(); i++)
	{
		if (idValue == x[i].getID())
		{
			if (x[i].getReaderName() == "NULL")
			{
				x[i].setReaderName(Username);
				x[i].set_start_date(current_date);
				x[i].set_exp_date(current_date + maxBorrowDate);
				StudentBorrowedBooks.push_back(x[i]);
				std::cout << x[i].getTitle() << " has been successfully borrowed!" << std::endl;

				return;
			}
			else
			{
				std::cout << "This book is taken out!" << std::endl << std::endl;
				return;
			}
		}
	}
	std::cout << "Invalid book ID!" << std::endl;
}

void Student::ReturnBooks(std::vector<BookCopy>& x)
{
	std::cout << "Enter the ID of the book you want to return: " << std::endl;
	std::string id;
	std::cin >> id;
	int i, j;
	for (i = 0; i < x.size(); i++)
	{
		if (id == x[i].getID())
		{
			x[i].setReaderName("NULL");
			for (j = 0; j < StudentBorrowedBooks.size(); j++)
			{
				if (StudentBorrowedBooks[j].getID() == id)
				{
					StudentBorrowedBooks.erase(StudentBorrowedBooks.begin() + j);
					std::cout << "Book was returned successfully!!" << std::endl;
				}
				
			}
			if (MaxBorrowed < 5)
			{
				MaxBorrowed++;
			}
			return;
		}
	}
	std::cout << "Could not find the book to return!" << std::endl;
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
* a student
*/
std::ostream& operator << (std::ostream& out, Student& student)
{
	//Output all variables to ostream
	out << 
		student.GetUser() << ' ' << 
		student.GetPswd() << ' ' << 
		student.GetMaxBorrowed() <<' ' 
		<< student.GetMaxBorrowDate() 
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
	int maxborrow = 5, maxborrowper = 30;

	//Take in values from istream
	in >> 
		Username >> 
		Password >>
		maxborrow >> 
		maxborrowper;

	
	//Set variables based on values taken in
	student.SetUser(Username);
	student.SetPswd(Password);
	student.SetMaxBorrowed(maxborrow);
	student.SetMaxBorrowDate(maxborrowper);
	
	return in;
}