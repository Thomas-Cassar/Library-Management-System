#include "Book.h"

Book::Book()
{
	ISBN = Title = Author = Category = "";
	favor = count = index = 0;
}
Book::Book(std::string iSBN, std::string title, std::string author, std::string category, int index, int count, int favor)
{
	ISBN = iSBN;
	Title = title;
	Author = author;
	Category = category;
	this->index = index;
	this->count = count;
	this->favor = favor;
}
std::string Book::getISBN()
{
	return ISBN;
}
std::vector <std::string>* Book::getReserverList()
{
	return &reserverList;
}
std::string Book::getTitle()
{
	return Title;
}
std::string Book::getAuthor()
{
	return Author;
}
std::string Book::getCategory()
{
	return Category;
}
int Book::getIndex()
{
	return index;
}
int Book::getCount()
{
	return count;
}
int Book::getFavor()
{
	return favor;
}
void Book::setISBN(std::string isbn)
{
	ISBN = isbn;
}
void Book::setTitle(std::string title)
{
	Title = title;
}
void Book::setAuthor(std::string author)
{
	Author = author;
}
void Book::setCategory(std::string category)
{
	Category = category;
}
void Book::setIndex(int idx)
{
	index = idx;
}
void Book::setCount(int cnt)
{
	count = cnt;
}
void Book::setFavor(int fvr)
{
	favor = fvr;
}

std::ostream& operator << (std::ostream& out, Book& book)
{
	//Output all variables to one line on ostream
	out <<
		book.getISBN() << ' ' <<
		book.getTitle() << ' ' <<
		book.getAuthor() << ' ' <<
		book.getCategory() << ' ' <<
		book.getIndex() << ' ' <<
		book.getCount() << ' ' <<
		book.getFavor() << ' ' <<
		std::endl;

	return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
* a book copy
*/
std::istream& operator >> (std::istream& in, Book& book)
{
	//Temp variables for storing istream data
	std::string ISBN, Title, Author, Category;
	int count, favor, index;

	//Take in all values from istream
	in >>
		ISBN >>
		Title >>
		Author >>
		Category >>
		index >>
		count >>
		favor;

	//Set all variables based on istream
	book.setISBN(ISBN);
	book.setTitle(Title);
	book.setAuthor(Author);
	book.setCategory(Category);
	book.setIndex(index);
	book.setCount(count);
	book.setFavor(favor);
	return in;
}