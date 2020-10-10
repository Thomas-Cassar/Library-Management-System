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

void Student::BorrowBook(std::vector <BookCopy> &x)
{
	std::string idValue = 0;
	int i = 0;
	if(BorrowedBooks.size() >= MaxBorrowed)
	{
		std::cout << "You have already reached the limit of borrowed copies" << std::endl;
		return;
	}

	std::cout << "Enter ID of the copy of the book you want to borrow: ";
	std::cin >> idValue;
	for (i = 0; i < x.size(); i++) 
	{
		if (idValue == x[i].getID() && x[i].getReaderName() == "")
		{
			x[i].setReaderName(Username);
			BorrowedBooks.push_back(x[i]);
			std::cout << "The book has been successfully borrowed!" << std::endl;
			return;
		}
	}
	std::cout << "Failed to borrow book!" << std::endl;
	
}
