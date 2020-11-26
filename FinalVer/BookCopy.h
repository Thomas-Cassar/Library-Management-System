#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Book.h"
class BookCopy
	:public Book
{
private:
	Book book;
	std::string ID;//Stores unique book ID
	std::string readerName;//Stores user that currently has book taken out NULL if not taken out
	int start_date;//Day value (since 01/01/01) that book was taken out
	int exp_date;//Last day value (since 01/01/01) that book can be returned on and not be overdue
	int reserve_date;
	bool available;
public:
	//Constructors
	BookCopy();
	BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
		int startDate, int expDate, int resDate);
	Book* returnBook();
	//Getter functions
	std::string getID();
	std::string getReaderName();
	int get_start_date();
	int get_exp_date();
	bool get_available();
	int get_reserve_date();

	//Setter functions
	void set_available(bool avl);
	void set_reserve_date(int res);
	void setID(std::string id);
	void setReaderName(std::string reader_name);
	void set_start_date(int startDate);
	void set_exp_date(int expDate);

	//Overloaded operators
	friend std::ostream& operator << (std::ostream& out, BookCopy& book);
	friend std::istream& operator >> (std::istream& in, BookCopy& book);
};

// Stream operators
std::ostream& operator << (std::ostream& out, BookCopy& book);
std::istream& operator >> (std::istream& in, BookCopy& book);
