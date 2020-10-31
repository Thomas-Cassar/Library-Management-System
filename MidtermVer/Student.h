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
	int penalty;
	int MaxBorrowed;
	int maxBorrowDate;

public:
	Student();
	Student(std::string user, std::string pswd);

	void SetUser(std::string usr);
	void SetPswd(std::string pswd);

	//
	void SetBorrowedBooks(std::vector<BookCopy> bBooks);
	void SetPenalty(int penalty);
	void SetMaxBorrowed(int maxBorrowed);
	void SetMaxBorrowDate(int maxBorrowDate);
	//

	std::string GetUser();
	std::string GetPswd();

	//
	std::vector<BookCopy> GetBorrowedBooks();
	int GetPenalty();
	int GetMaxBorrowed();
	int GetMaxBorrowDate();
	//

	void StudentBorrowBook(std::vector <BookCopy>& x, int date);
	void ReturnBooks(std::vector<BookCopy>& x);

	//
	friend std::ostream& operator << (std::ostream& out, Student& student);
	friend std::istream& operator >> (std::istream& in, Student& student);
	//
};

std::ostream& operator << (std::ostream& out, Student& student);
std::istream& operator >> (std::istream& in, Student& student);
