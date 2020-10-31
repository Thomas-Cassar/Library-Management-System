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
	penalty = 0;
	maxBorrowDate = 30;

	// also want to include maxBorrowingPeriods in the constructors?
}

Student::Student(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;

	// leaving comment blocks around the things I change - Eshan
	MaxBorrowed = 5;
	penalty = 0;
	maxBorrowDate = 30
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


void Student::SetPenalty(int penalty)
{
	this->penalty = penalty;
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


int Student::GetPenalty()
{
	return this->penalty;
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

void Student::SetMaxBorrowDate(int maxBorrowDate)
{
	this->maxBorrowDate = maxBorrowDate;
}

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
	for (i = 0; i < StudentBorrowedBooks.size(); i++)
	{
		if (current_date > StudentBorrowedBooks[i].get_exp_date())
		{
			std::cout << StudentBorrowedBooks[i].getTitle() << "is overdue! Please return the book!" << std::endl;
			penalty++;
		}
		return;
	}
	if (StudentBorrowedBooks.size() >= (MaxBorrowed - penalty))
	{
		std::cout << "You have already reached the limit of borrowed copies" << std::endl;
		return;
	}

	std::cout << "Enter ID of the copy of the book you want to borrow: ";
	std::cin >> idValue;
	for (i = 0; i < x.size(); i++)
	{
		if (idValue == x[i].getID())
		{
			if (x[i].getReaderName() == "")
			{
				x[i].setReaderName(Username);
				StudentBorrowedBooks.push_back(x[i]);
				std::cout << "The book has been successfully borrowed!" << std::endl;
				return;
			}
			else
			{
				std::cout << "This book is taken out!" << std::endl << std::endl;
				return;
			}
		}
	}
	std::cout << "Failed to borrow book!" << std::endl;
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
			x[i].setReaderName("");
			for (j = 0; j < StudentBorrowedBooks.size(); j++)
			{
				if (StudentBorrowedBooks[j].getID() == id)
				{
					StudentBorrowedBooks.erase(StudentBorrowedBooks.begin() + i);
				}
			}
			return;
		}
	}
	std::cout << "Could not find the book to return!" << std::endl;
}

//
std::ostream& operator << (std::ostream& out, Student& student)
{
	out << "Username: " << student.GetUser() << std::endl;

	// maybe don't want to show password
	out << "Password: " << student.GetPswd() << std::endl;
	//

	out << "Current Borrowed Books: " << std::endl;
	for (int i = 0; i < student.GetBorrowedBooks().size(); i++) {
		out << student.GetBorrowedBooks()[i].getTitle();
		out << std::endl;
	}

	/*out << "Current Reserved Books: " << std::endl;
	for (int i = 0; i < student->get.size(); i++) {
		this->StudentReservedBooks[i].operator<<(out);
		out << std::endl << std::endl;
	}*/

	out << "Max Borrow Period: " << student.GetMaxBorrowDate() << std::endl;
	out << "Max Books That Can Be Borrowed: " << student.GetMaxBorrowed() << std::endl;

	// if we also include maxBorrowingPeriods for student
	// out << "Max. Borrowing Periods: " << this->MaxBorrowingPeriods << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Student& student)
{
	std::string Username, Password;
	int maxborrow = 5, maxborrowper = 30;

	// may have to add penalty and maxborrowed
	// int penalty, maxBorrowed
	in >> Username >> Password;
	in >> maxborrow >> maxborrowper;

	// in >> penalty >> maxBorrowed;

	student.SetUser(Username);
	student.SetPswd(Password);
	student.SetMaxBorrowed(maxborrow);
	student.SetMaxBorrowDate(maxborrowper);
	/*
	this->penalty = penalty;
	this->MaxBorrowed = maxBorrowed;
	*/
	return in;
}