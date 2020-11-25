#include "BookCopy.h"

/**
 * default BookCopy constructor
 * creates a new BookCopy object
 * sets ISBN, Title, Author, Category, ID, readerName to empty string
 * sets start_date to 0
 * sets exp_date to 30
 */
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

/**
 * parameterized BookCopy constructor
 * @param isbn - string
 * @param title - string
 * @param author - string
 * @param category - string
 * @param id - string
 * @param reader_name - string
 * @param startDate - string
 * @param expDate - string
 * creates a new BookCopy object
 * sets ISBN to param isbn
 * sets Title to param title
 * sets Author to param author
 * sets Category to param category
 * sets ID to param id
 * sets readerName to param reader_name
 * sets start_date to param startDate
 * sets exp_date to param expDate
 */
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

/**
 * @return string - ISBN of current BookCopy object
 */
std::string BookCopy::getISBN()
{
	return ISBN;
}

/**
 * @return string - Title of current BookCopy object
 */
std::string BookCopy::getTitle()
{
	return Title;
}

/**
 * @return string - Author of current BookCopy object
 */
std::string BookCopy::getAuthor()
{
	return Author;
}

/**
 * @return string - Category of current BookCopy object
 */
std::string BookCopy::getCategory()
{
	return Category;
}

/**
 * @return string - ID of current BookCopy object
 */
std::string BookCopy::getID()
{
	return ID;
}

/**
 * @return string - readerName of current BookCopy object
 */
std::string BookCopy::getReaderName()
{
	return readerName;
}

std::string BookCopy::getReserverName()
{
	return reserverName;
}

/**
 * @return string - start_date of current BookCopy object
 */
int BookCopy::get_start_date()
{
	return start_date;
}

/**
 * @return string - exp_date of current BookCopy object
 */
int BookCopy::get_exp_date()
{
	return exp_date;
}

/**
 * sets ISBN of current BookCopy object to param isbn
 * @param isbn - string
 */
void BookCopy::setISBN(std::string isbn)
{
	ISBN = isbn;
}

/**
 * sets Title of current BookCopy object to param title
 * @param title - string
 */
void BookCopy::setTitle(std::string title)
{
	Title = title;
}

/**
 * sets author of current BookCopy object to param author
 * @param author - string
 */
void BookCopy::setAuthor(std::string author)
{
	Author = author;
}

/**
 * sets category of current BookCopy object to param category
 * @param category - string
 */
void BookCopy::setCategory(std::string category)
{
	Category = category;
}

/**
 * sets ID of current BookCopy object to param id
 * @param id - string
 */
void BookCopy::setID(std::string id)
{
	ID = id;
}

/**
 * sets readerName of current BookCopy object to param reader_name
 * @param reader_name - string
 */
void BookCopy::setReaderName(std::string reader_name)
{
	readerName = reader_name;
}

void BookCopy::setReserverName(std::string reserver_name)
{
	reserverName = reserver_name;
}
/**
 * sets start_date of current BookCopy object to param startDate
 * @param startDate - string
 */
void BookCopy::set_start_date(int startDate)
{
	start_date = startDate;
}

/**
 * sets exp_date of current BookCopy object to param expDate
 * @param expDate - string
 */
void BookCopy::set_exp_date(int expDate)
{
	exp_date = expDate;
}


/*
* This function overloads the << ostream operator to be able to print all variables on one line of
* a book copy
*/
std::ostream& operator << (std::ostream& out, BookCopy& book)
{
	//Output all variables to one line on ostream
	out <<
		book.getISBN() <<' '<<
		book.getTitle() << ' ' <<
		book.getAuthor() << ' ' <<
		book.getCategory() << ' ' <<
		book.getID() << ' ' <<
		book.getReaderName() << ' ' <<
		book.get_start_date() << ' ' <<
		book.get_exp_date() <<
	std::endl;

	return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
* a book copy
*/
std::istream& operator >> (std::istream& in, BookCopy& book)
{
	//Temp variables for storing istream data
	std::string ISBN, Title, Author, Category, ID,
		readerName;
	int start_date, exp_date;

	//Take in all values from istream
	in >> 
		ISBN >> 
		Title >> 
		Author >> 
		Category >> 
		ID>> 
		readerName >> 
		start_date >> 
		exp_date;

	//Set all variables based on istream
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