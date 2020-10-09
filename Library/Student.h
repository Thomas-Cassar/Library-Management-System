#pragma once

#include <string>
#include <BookCopy.h>
#include <vector>
class Student
{
private:
	std::string Username;
	std::string Password;
	std::vector<BookCopy> BorrowedBooks;
	int MaxBorrowed;

public:
	Student();
	Student(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);

	std::string GetUser();
	std::string GetPswd();

	void BorrowBook(std::vector <BookCopy> &x);
};
