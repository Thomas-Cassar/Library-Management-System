#pragma once

#include <string>
#include "BookCopy.h"
#include <vector>
#include <iostream>
class Student
{
private:
	std::string Username;//Stores logged in students username
	std::string Password;//Stores logged in students password
	std::vector<BookCopy> StudentBorrowedBooks;//Stores all books that student has borrowed
	int MaxBorrowed,MaxBorrowedCurrent;//Max allowed borrowed books and max allowed books at this time
	int maxBorrowDate;//How long the student can have books for before overdue

public:
	//Constructors
	Student();
	Student(std::string user, std::string pswd);

	//Setter functions
	void SetUser(std::string usr);
	void SetPswd(std::string pswd);
	void SetBorrowedBooks(std::vector<BookCopy> bBooks);
	void SetMaxBorrowed(int maxBorrowed);
	void SetMaxBorrowedCurrent(int maxBorrowedCurrent);
	void SetMaxBorrowDate(int maxBorrowDate);

	//Getter functions
	std::string GetUser();
	std::string GetPswd();
	std::vector<BookCopy> GetBorrowedBooks();
	int GetMaxBorrowed();
	int GetMaxBorrowedCurrent();
	int GetMaxBorrowDate();
	
	//Command functions
	void StudentBorrowBook(std::vector <BookCopy>& x, int date);
	void ReturnBooks(std::vector<BookCopy>& x, int date);
	void Print();

	//Overloaded operators
	friend std::ostream& operator << (std::ostream& out, Student& student);
	friend std::istream& operator >> (std::istream& in, Student& student);
};

// Stream operators
std::ostream& operator << (std::ostream& out, Student& student);
std::istream& operator >> (std::istream& in, Student& student);
