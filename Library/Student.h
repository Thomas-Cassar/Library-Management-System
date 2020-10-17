#pragma once

#include <string>
#include "BookCopy.h"
#include <vector>
#include <iostream>
class Student
{
private:
	std::string Username;
	std::string Password;
	std::vector<BookCopy> StudentBorrowedBooks;
	std::vector<BookCopy> StudentReservedBooks;
	int penalty;
	int MaxBorrowed;

public:
	Student();
	Student(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);
	
	//
	void SetBorrowedBooks(std::vector<BookCopy> bBooks);
	void SetReservedBooks(std::vector<BookCopy> rBooks);
	void SetPenalty(int penalty);
	void SetMaxBorrowed(int maxBorrowed);
	//

	std::string GetUser();
	std::string GetPswd();

	//
	std::vector<BookCopy> GetBorrowedBooks();
	std::vector<BookCopy> GetReservedBooks();
	int GetPenalty();
	int GetMaxBorrowed();
	//

	void StudentBorrowBook(std::vector <BookCopy> &x);
	void CancelStudentReservation(std::vector<BookCopy>& x);
	void ReturnBooks(LMS &lms);

	//
	void operator << (std::ostream& out);
	void operator >> (std::istream& in);
	//
};
