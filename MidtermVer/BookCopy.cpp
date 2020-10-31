#include "BookCopy.h"

BookCopy::BookCopy()
{
	ISBN = "";
	Title = "";
	Author = "";
	Category = "";
	ID = "";
	readerName = "";
	start_date = 0;
	exp_date = 30;
}

BookCopy::BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
	int startDate, int expDate)
{
	ISBN = isbn;
	Title = title;
	Author = author;
	Category = category;
	ID = id;
	readerName = reader_name;
	start_date = startDate;
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
int BookCopy::get_start_date()
{
	return start_date;
}
int BookCopy::get_exp_date()
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
void BookCopy::set_start_date(int startDate)
{
	start_date = startDate;
}
void BookCopy::set_exp_date(int expDate)
{
	exp_date = expDate;
}

//

std::ostream& operator << (std::ostream& out, BookCopy& book)
{
	out << "ISBN: " << book.getISBN() << std::endl;
	out << "Title: " << book.getTitle() << std::endl;
	out << "Author: " << book.getAuthor() << std::endl;
	out << "Category: " << book.getCategory() << std::endl;
	out << "ID: " << book.getID() << std::endl;
	out << "Reader Name: " << book.getReaderName() << std::endl;
	out << "Start Date: " << book.get_start_date() << std::endl;
	out << "Expiration Date: " << book.get_exp_date() << std::endl;
	return out;
}
std::istream& operator >> (std::istream& in, BookCopy& book)
{
	std::string ISBN, Title, Author, Category, ID,
		readerName;
	int start_date, res_date, exp_date;
	in >> ISBN >> Title >> Author >> Category >> ID
		>> readerName >> start_date >> exp_date;
	book.setISBN(ISBN);
	book.setTitle(Title);
	book.setAuthor(Author);
	book.setCategory(Category);
	book.setID(ID);
	book.setReaderName(readerName);
	book.set_start_date(start_date);
	book.set_exp_date(exp_date);
	return in;
}