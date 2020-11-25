#pragma once
#include <string>
#include <vector>
#include <iostream>
class BookCopy
{
private:
	std::string ISBN;//Stores book ISBN
	std::string Title;//Stores book title
	std::string Author;//Stores book author
	std::string Category;//Stores book category
	std::string ID;//Stores unique book ID
	std::string readerName;//Stores user that currently has book taken out NULL if not taken out
	std::string reserverName;
	int start_date;//Day value (since 01/01/01) that book was taken out
	int exp_date;//Last day value (since 01/01/01) that book can be returned on and not be overdue
public:
	//Constructors
	BookCopy();
	BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
		int startDate, int expDate);

	//Getter functions
	std::string getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getCategory();
	std::string getID();
	std::string getReaderName();
	std::string getReserverName();
	int get_start_date();
	int get_exp_date();

	//Setter functions
	void setISBN(std::string isbn);
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setCategory(std::string category);
	void setID(std::string id);
	void setReaderName(std::string reader_name);
	void setReserverName(std::string reserver_name);
	void set_start_date(int startDate);
	void set_exp_date(int expDate);

	//Overloaded operators
	friend std::ostream& operator << (std::ostream& out, BookCopy& book);
	friend std::istream& operator >> (std::istream& in, BookCopy& book);
};

// Stream operators
std::ostream& operator << (std::ostream& out, BookCopy& book);
std::istream& operator >> (std::istream& in, BookCopy& book);
