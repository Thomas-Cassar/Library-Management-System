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
}

Student::Student(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;
}


void Student::SetUser(std::string usr)
{
	Username = usr;
}

void Student::SetPswd(std::string pswd)
{
	Password = pswd;
}

std::string Student::GetUser()
{
	return Username;
}

std::string Student::GetPswd()
{
	return Password;
}

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
