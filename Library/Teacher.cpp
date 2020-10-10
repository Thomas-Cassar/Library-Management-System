#include "Teacher.h"
#include <string>
#include "BookCopy.h"
#include <vector>
#include <iostream>
Teacher::Teacher()
{
	Username = "NULL";
	Password = "NULL";
	TeacherMaxBorrowed = 10;
}

Teacher::Teacher(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;
}


void Teacher::SetUser(std::string usr)
{
	Username = usr;
}

void Teacher::SetPswd(std::string pswd)
{
	Password = pswd;
}

std::string Teacher::GetUser()
{
	return Username;
}

std::string Teacher::GetPswd()
{
	return Password;
}

void Teacher::TeacherBorrowBooks(std::vector <BookCopy> &y) {
	{
		std::string idValue = "";
		int i = 0;
		if (TeacherBorrowed.size() >= TeacherMaxBorrowed)
		{
			std::cout << "You have already reached the limit of borrowed copies" << std::endl;
			return;
		}

		std::cout << "Enter ID of the copy of the book you want to borrow: ";
		std::cin >> idValue;
		for (i = 0; i < y.size(); i++)
		{
			if (idValue == y[i].getID() && y[i].getReaderName() == "")
			{
				y[i].setReaderName(Username);
				TeacherBorrowed.push_back(y[i]);
				std::cout << "The book has been successfully borrowed!" << std::endl;
				return;
			}
		}
		std::cout << "Failed to borrow book!" << std::endl;
}
