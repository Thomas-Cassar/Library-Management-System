#include "BookCopy.h"

BookCopy::BookCopy()
{
	ISBN = "";
	Title = "";
	Author = "";
	Category = "";
	ID = "";
	readerName = "";
	start_date = "";
	res_date = "";
	exp_date = "";
}

BookCopy::BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
	std::string startDate, std::string resDate, std::string expDate)
{
	ISBN = isbn;
	Title = title;
	Author = author;
	Category = category;
	ID = id;
	readerName = reader_name;
	start_date = startDate;
	res_date = resDate;
	exp_date = expDate;
}

std::string BookCopy::getISBN()
{
	return ISBN;
}
std::string BookCopy::getTitle()
{
	return Title;
}
std::string BookCopy::getAuthor()
{
	return Author;
}
std::string BookCopy::getCategory()
{
	return Category;
}
std::string BookCopy::getID()
{
	return ID;
}
std::string BookCopy::getReaderName()
{
	return readerName;
}
std::string BookCopy::get_start_date()
{
	return start_date;
}
std::string BookCopy::get_res_date()
{
	return res_date;
}
std::string BookCopy::get_exp_date()
{
	return exp_date;
}
void BookCopy::setISBN(std::string isbn)
{
	ISBN = isbn;
}
void BookCopy::setTitle(std::string title)
{
	Title = title;
}
void BookCopy::setAuthor(std::string author)
{
	Author = author;
}
void BookCopy::setCategory(std::string category)
{
	Category = category;
}
void BookCopy::setID(std::string id)
{
	ID = id;
}
void BookCopy::setReaderName(std::string reader_name)
{
	readerName = reader_name;
}
void BookCopy::set_start_date(std::string startDate)
{
	start_date = startDate;
}
void BookCopy::set_exp_date(std::string expDate)
{
	exp_date = expDate;
}
void BookCopy::set_res_date(std::string resDate)
{
	res_date = resDate;
}

//
void BookCopy::operator << (std::ostream &out)
{
	out << "ISBN: " << this->ISBN << std::endl;
	out << "Title: " << this->Title << std::endl;
	out << "Author: " << this->Author << std::endl;
	out << "Category: " << this->Category << std::endl;
	out << "ID: " << this->ID << std::endl;
	out << "Reader Name: " << this->readerName << std::endl;
	out << "Start Date: " << this->start_date << std::endl;
	out << "Reservation Date: " << this->res_date << std::endl;
	out << "Expiration Date: " << this->exp_date << std::endl;
}

void BookCopy::operator >> (std::istream& in) 
{
	std::string ISBN, Title, Author, Category, ID,
		readerName, start_date, res_date, exp_date;
	in >> ISBN >> Title >> Author >> Category >> ID
		>> readerName >> start_date >> res_date >> exp_date;
	this->ISBN = ISBN;
	this->Title = Title;
	this->Author = Author;
	this->Category = Category;
	this->ID = ID;
	this->readerName = readerName;
	this->start_date = start_date;
	this->res_date = res_date;
	this->exp_date = exp_date;
}
//
