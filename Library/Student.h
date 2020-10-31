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
	int maxBorrowDate;

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
	void SetMaxBorrowDate(int maxBorrowDate);
	//

	std::string GetUser();
	std::string GetPswd();

	//
	std::vector<BookCopy> GetBorrowedBooks();
	std::vector<BookCopy> GetReservedBooks();
	int GetPenalty();
	int GetMaxBorrowed();
	int GetMaxBorrowDate();
	//

	void StudentBorrowBook(std::vector <BookCopy> &x, int date);
	void CancelStudentReservation(std::vector<BookCopy>& x);
	void ReturnBooks(std::vector<BookCopy>& x, int date);

	//
	friend std::ostream& operator << (std::ostream& out, Student& student);
	friend std::istream& operator >> (std::istream& in, Student& student);
	//
};

std::ostream& operator << (std::ostream& out, Student& student);
std::istream& operator >> (std::istream& in, Student& student);