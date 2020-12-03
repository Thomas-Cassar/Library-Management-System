#include "Book.h"

/**
 * @brief default Book constructor
 * 
 * @postcondition new Book object created
 * 
 * @postcondition ISBN, Title, Author, and Category set to empty string ("")
 * 
 * @postcondition favor, count, index set to 0
*/
Book::Book()
{
	ISBN = Title = Author = Category = "";
	favor = count = index = 0;
}

/**
 * @brief parameterized Book constructor
 * 
 * @param iSBN - string
 * 
 * @param title - string
 * 
 * @param author - string
 * 
 * @param category - string
 * 
 * @param index - int
 * 
 * @param count - int
 * 
 * @param favor - int
 * 
 * @postcondition new Book object created
 * 
 * @postcondition ISBN of Book set to param iSBN, 
 *  Title of Book set to param title, Author of Book set to param author, 
 *  ISBN of Book set to param iSBN
 * 
 * @postcondition index of Book set to param index, 
 *  count of Book set to param count, favor of Book set to param count
*/
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

/**
 * @return string - ISBN of current Book
*/
std::string Book::getISBN()
{
	return ISBN;
}

/**
 * @return vector<string>* - reserverList of current Book
*/
std::vector <std::string>* Book::getReserverList()
{
	return &reserverList;
}

/**
 * @return string - Title of current Book
*/
std::string Book::getTitle()
{
	return Title;
}

/**
 * @return string - Author of current Book
*/
std::string Book::getAuthor()
{
	return Author;
}

/**
 * @return string - Category of current Book
*/
std::string Book::getCategory()
{
	return Category;
}

/**
 * @return int - index of current Book
*/
int Book::getIndex()
{
	return index;
}

/**
 * @return int - count of current Book
*/
int Book::getCount()
{
	return count;
}

/**
 * @return int - favor of current Book
*/
int Book::getFavor()
{
	return favor;
}

/**
 * @param isbn - string
 * 
 * @postcondition ISBN of current Book set to param isbn
*/
void Book::setISBN(std::string isbn)
{
	ISBN = isbn;
}

/**
 * @param title - string
 *
 * @postcondition Title of current Book set to param title
*/
void Book::setTitle(std::string title)
{
	Title = title;
}

/**
 * @param author - string
 *
 * @postcondition Author of current Book set to param author
*/
void Book::setAuthor(std::string author)
{
	Author = author;
}

/**
 * @param category - string
 *
 * @postcondition Category of current Book set to param category
*/
void Book::setCategory(std::string category)
{
	Category = category;
}

/**
 * @param idx - string
 *
 * @postcondition index of current Book set to param idx
*/
void Book::setIndex(int idx)
{
	index = idx;
}

/**
 * @param cnt - string
 *
 * @postcondition count of current Book set to param cnt
*/
void Book::setCount(int cnt)
{
	count = cnt;
}

/**
 * @param fvr - string
 *
 * @postcondition favor of current Book set to param fvr
*/
void Book::setFavor(int fvr)
{
	favor = fvr;
}


/**
 * @brief overloaded << operator
 * 
 * @param out - ostream&
 * 
 * @param book - Book&
 * 
 * @return ostream& - all relevant member variables of the current Book
 *  are output to one line of param out
*/
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