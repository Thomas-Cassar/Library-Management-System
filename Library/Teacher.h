#pragma once

#include <string>
#include "BookCopy.h"
#include <vector>
class Teacher
{
private:
	std::string Username;
	std::string Password;
	std::vector <BookCopy> TeacherBorrowed;
	int TeacherMaxBorrowed;

public:
	Teacher();
	Teacher(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);

	std::string GetUser();
	std::string GetPswd();

	void TeacherBorrowBooks(std::vector <BookCopy> &y);


};