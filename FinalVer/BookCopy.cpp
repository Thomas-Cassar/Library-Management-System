#include "BookCopy.h"

/**
 * @brief default BookCopy constructor
 * 
 * @postcondition creates a new BookCopy object
 * 
 * @postcondition sets ID and readerName to empty string ("")
 * 
 * @postcondition sets start_date to 0
 * 
 * @postcondition sets exp_date to 30
 * 
 * @postcondition sets reserve_date to 0
 * 
 * @postcondition sets available to true
*/
BookCopy::BookCopy()
{
	ID = "";
	readerName = "";
	start_date = 0;
	exp_date = 30;
	reserve_date = 0;
	available = true;
}


 /**
  * @brief parameterized BookCopy constructor
  *
  * @param isbn - string
  * 
  * @param title - string
  * 
  * @param author - string
  * 
  * @param category - string
  * 
  * @param id - string
  * 
  * @param reader_name - string
  * 
  * @param startDate - int
  * 
  * @param expDate - int
  * 
  * @param resData - int
  * 
  * @postcondition creates a new BookCopy object
  *
  * @postcondition sets ISBN to param isbn
  *				sets Title to param title
  *				sets Author to param author
  *				sets Category to param category
  *				sets index, count, and favor to 0
  *				sets ID to param id
  *				sets readerName to param reader_name
  *				sets start_date to param startDate
  *				sets exp_date to param expDate
				sets reserve_date to param resDate
  *
  * @postcondition sets available to true
 */
BookCopy::BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
	int startDate, int expDate, int resDate) : Book (isbn, title, author, category, 0, 0, 0)
{
	ID = id;
	readerName = reader_name;
	start_date = startDate;
	exp_date = expDate;
	reserve_date = resDate;
}

/**
 * @return string - ID of current BookCopy object
 */
std::string BookCopy::getID()
{
	return ID;
}

/**
 * @return Book* - book of current BookCopy
*/
Book* BookCopy::returnBook()
{
	return &book;
}

/**
 * @return string - readerName of current BookCopy object
 */
std::string BookCopy::getReaderName()
{
	return readerName;
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
 * @return int - reserve_date of current BookCopy object
*/
int BookCopy::get_reserve_date()
{
	return reserve_date;
}

/**
 * @return bool - availability of current BookCopy object
*/
bool BookCopy::get_available()
{
	return available;
}

/**
 * @param id - string
 * 
 * @postcondition ID of current BookCopy set to param id
 */
void BookCopy::setID(std::string id)
{
	ID = id;
}

/**
 * @param book - Book&
 * 
 * @postcondition book of current BookCopy set to param book
*/
void BookCopy::setBook(Book& book)
{
	this->book = book;
}

/**
 * @param reader_name - string
 * 
 * @postcondition readerName of current BookCopy set to param reader_name
 */
void BookCopy::setReaderName(std::string reader_name)
{
	readerName = reader_name;
}

/**
 * @param startDate - string
 * 
 * @postcondition start_date of current BookCopy set to param startDate
 */
void BookCopy::set_start_date(int startDate)
{
	start_date = startDate;
}

/**
 * @param expDate - string
 * 
 * @postcondition exp_date of current BookCopy set to param expDate
 */
void BookCopy::set_exp_date(int expDate)
{
	exp_date = expDate;
}

/**
 * @param res - int
 * 
 * @postcondition reserve_date of current BookCopy set to param res
*/
void BookCopy::set_reserve_date(int res)
{
	 reserve_date = res;
}

/**
 * @param avl - bool
 * 
 * @postcondition availability (var. available) of current BookCopy set to param avl
*/
void BookCopy::set_available(bool avl)
{
	available = avl;
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
* a book copy
*/
std::ostream& operator << (std::ostream& out, BookCopy& book)
{
	//Output all variables to one line on ostream
	out <<
		book.getISBN() << ' ' <<
		book.getTitle() << ' ' <<
		book.getAuthor() << ' ' <<
		book.getCategory() << ' ' <<
		book.getID() << ' ' <<
		book.getReaderName() << ' ' <<
		book.get_start_date() << ' ' <<
		book.get_exp_date() << ' ' <<
		book.get_reserve_date() << 
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
	int start_date, exp_date, resDate;

	//Take in all values from istream
	in >>
		ISBN >>
		Title >>
		Author >>
		Category >>
		ID >>
		readerName >>
		start_date >>
		exp_date >>
		resDate;

	//Set all variables based on istream
	book.setISBN(ISBN);
	book.setTitle(Title);
	book.setAuthor(Author);
	book.setCategory(Category);
	book.setID(ID);
	book.setReaderName(readerName);
	book.set_start_date(start_date);
	book.set_exp_date(exp_date);
	book.set_reserve_date(resDate);
	return in;
}