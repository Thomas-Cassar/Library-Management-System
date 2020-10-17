#include "Student.h"
#include <iostream>
#include "BookCopy.h"
#include <vector>
#include "LMS.h"
Student::Student()
{
	Username = "NULL";
	Password = "NULL";
	MaxBorrowed = 5;
	penalty = 0;

	// also want to include maxBorrowingPeriods in the constructors?
}

Student::Student(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;

	// leaving comment blocks around the things I change - Eshan
	MaxBorrowed = 5;
	penalty = 0;
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

void Student::SetReservedBooks(std::vector<BookCopy> rBooks)
{
	this->StudentReservedBooks = rBooks;
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

std::vector<BookCopy> Student::GetReservedBooks()
{
	return this->StudentReservedBooks;
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

void Student::StudentBorrowBook(std::vector <BookCopy> &x)
{
	std::string idValue = "";
	int i = 0;
	std::string reserveAnswer = "";
	if(StudentBorrowedBooks.size() >= (MaxBorrowed - penalty))
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
				std::cout << "This book is taken out, would you like to reserve it? " << std::endl << std::endl;
				std::cout << "Yes or No: ";
				std::cin >> reserveAnswer;
				if (reserveAnswer == "Yes") 
				{
					std::cout << std::endl << "You have now reserved this book!" << std::endl;
					x[i].reservees.push_back(Username);
					StudentReservedBooks.push_back(x[i]);
				}
				else
				{
					std::cout << std::endl << "You have not reserved this book and not borrow the book!" << std::endl;
					return;

				}
			}
		}
	}
	std::cout << "Failed to borrow book!" << std::endl;	
}

void Student::CancelStudentReservation(std::vector<BookCopy> &x) 
{
	std::string idValue = "";
	int i = 0, j = 0, k = 0;
	std::cout << "What book reservation do you want to cancel?(Enter ID) " << std::endl;
	std::cin >> idValue;
	for (i = 0; i < StudentReservedBooks.size(); i++) 
	{
		if (StudentReservedBooks[i].getID() == idValue) 
		{
			std::cout << "You have successfully cancelled the Reservation!" << std::endl;
			StudentReservedBooks.erase(StudentReservedBooks.begin()+i); //removes the reservation from the user
			for (j = 0; j < x.size(); j++) {
				if(x[j].getID() == idValue)
				{
					for(k = 0; k < x[j].reservees.size(); k++)
					{
						if (x[j].reservees[k] == Username) {
							x[j].reservees.erase(x[j].reservees.begin() + k);
						}
					}//removes the user from the books reservation
				}//checks for which book is being referred to 
			}
			return;
		}
	}
	std::cout << "Cancellation request has failed!" << std::endl;
}

void Student::ReturnBooks(LMS &lms)
{
	std::cout << "Enter the ID of the book you want to return: " << std::endl;
	std::string id;
	std::cin >> id;
	int i,j;
	for (i = 0; i < lms.returnBookCopy().size(); i++)
	{
		if (id == lms.returnBookCopy()[i].getID())
		{
			lms.returnBookCopy()[i].setReaderName("");
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
void Student::operator << (std::ostream& out) 
{
	out << "Username: " << this->Username << std::endl;
	
	// maybe don't want to show password
	out << "Password: " << this->Password << std::endl;
	//

	out << "Current Borrowed Books: " << std::endl;
	for (int i = 0; i < this->StudentBorrowedBooks.size(); i++) {
		this->StudentBorrowedBooks[i].operator<<(out);
		out << std::endl << std::endl;
	}

	out << "Current Reserved Books: " << std::endl;
	for (int i = 0; i < this->StudentReservedBooks.size(); i++) {
		this->StudentReservedBooks[i].operator<<(out);
		out << std::endl << std::endl;
	}

	out << "Current Penalty: " << this->penalty << std::endl;

	// if we also include maxBorrowingPeriods for student
	// out << "Max. Borrowing Periods: " << this->MaxBorrowingPeriods << std::endl;
}

void Student::operator >> (std::istream& in)
{
	std::string Username, Password;

	// may have to add penalty and maxborrowed
	// int penalty, maxBorrowed

	in >> Username >> Password;
	
	// in >> penalty >> maxBorrowed;

	this->Username = Username;
	this->Password = Password;
	
	/*
	this->penalty = penalty;
	this->MaxBorrowed = maxBorrowed;
	*/
}
//
