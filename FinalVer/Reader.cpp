#include "Reader.h"
#include <ctime>

Reader::Reader(std::string user, std::string pswd, int maxBorrowed,
	int maxBorrowedCurrent, int maxBorrowDate)
	:User(user,pswd),
	maxBorrowed(maxBorrowed),
	maxBorrowedCurrent(maxBorrowedCurrent),
	maxBorrowDate(maxBorrowDate)
{

}

/**
 * @return vector<BookCopy> - ReaderBorrowedBooks of
 *  current Reader object
 */
 //
std::vector<BookCopy>* Reader::GetBorrowedBooks()
{
	return &ReaderBorrowedBooks;
}

/**
 * @return int - MaxBorrowed of current Reader object
 */
int Reader::GetMaxBorrowed()
{
	return this->maxBorrowed;
}

/**
 * @return int - MaxBorrowedCurrent of current Reader object
 */
int Reader::GetMaxBorrowedCurrent()
{
	return maxBorrowedCurrent;
}
//
/**
 * @return int - maxBorrowDate of current Reader object
 */
int Reader::GetMaxBorrowDate()
{
	return maxBorrowDate;
}

//
/**
 * sets ReaderBorrowedBooks vector of current Reader object
 *  to param bBooks
 * @param bBooks - vector<BookCopy>
 */
void Reader::SetBorrowedBooks(std::vector<BookCopy> bBooks)
{
	this->ReaderBorrowedBooks = bBooks;
}

/**
 * sets MaxBorrowed of current Reader object to param maxBorrowed
 * @param maxBorrowed - int
 */
void Reader::SetMaxBorrowed(int maxBorrowed)
{
	maxBorrowed = maxBorrowed;
}

/**
 * sets MaxBorrowedCurrent of current Reader object to param maxBorrowedCurrent
 * @param maxBorrowedCurrent - int
 */
void Reader::SetMaxBorrowedCurrent(int maxBorrowedCurrent)
{
	this->maxBorrowedCurrent = maxBorrowedCurrent;
}
//



/**
 * sets maxBorrowDate of current Reader object to param maxBorrowDate
 * @param maxBorrowDate - int
*/
void Reader::SetMaxBorrowDate(int maxBorrowDate)
{
	this->maxBorrowDate = maxBorrowDate;
}

/*
* This fuction is called from the main loop if the user wants to borrow a book
*/
void Reader::BorrowBook(std::vector <BookCopy>& x, int date)
{
	std::string idValue = "";
	int i = 0;
	std::string reserveAnswer = "";

	for (int iter = 0; iter < float(clock()) / 1000; iter++)//Calculate the value for the current date
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;
	bool shouldreturn = false;

	//This function checks to see if any books are overdue
	//If said book is overdue then MaxBorrowed is decremented and no new book is allowed to be taken out

	for (i = 0; i < GetBorrowedBooks()->size(); i++)
	{
		if (current_date > GetBorrowedBooks()->at(i).get_exp_date())
		{
			std::cout << GetBorrowedBooks()->at(i).getTitle() << " is overdue! Please return the book!" << std::endl;

			shouldreturn = true;
		}

	}
	if (shouldreturn)
		return;

	//This function checks to see if we are already over the limit for books allowed to be borrowed
	if (GetBorrowedBooks()->size() >= GetMaxBorrowedCurrent())
	{
		std::cout << "You have already reached the limit of borrowed copies" << std::endl;
		return;
	}

	//If here is reached then the book is allowed to be borrowed and we ask what they want to borrow
	std::cout << "Enter ID of the copy of the book you want to borrow: ";
	std::cin >> idValue;
	for (i = 0; i < x.size(); i++)//Loop through book copy vector
	{
		if (idValue == x[i].getID())//Case where the book is in the copy vector
		{
			if (x[i].getReaderName() == "NULL")//Case where the book is not taken out
			{
				x[i].setReaderName(GetUser());
				x[i].set_start_date(current_date);
				x[i].set_exp_date(current_date + GetMaxBorrowDate());
				GetBorrowedBooks()->push_back(x[i]);
				std::cout << x[i].getTitle() << " has been successfully borrowed!" << std::endl;

				return;
			}
			else //Case when someone else has the book taken out
			{
				std::cout << "This book is taken out!" << std::endl << std::endl;
				return;
			}
		}
	}
	//Case where the book ID is not found in the copy vector
	std::cout << "Invalid book ID!" << std::endl;
}

/**
 * prints relevant info for a Reader object
 */
void Reader::Print()
{
	std::cout << std::endl;
	std::cout << "Username: " << GetUser() << std::endl;
	std::cout << "Password: " << GetPswd() << std::endl;
	std::cout << "Maximum Books You can Borrow out of Original Maximum: " << GetMaxBorrowedCurrent() << '/' << GetMaxBorrowed() << std::endl;
	std::cout << "Maximum Borrowing Time: " << GetMaxBorrowDate() << " days" << std::endl;
	std::cout << "Books You have Borrowed: " << std::endl;
	for (int i = 0; i < GetBorrowedBooks()->size(); i++)//Prints all books reader has taken out
	{
		std::cout << GetBorrowedBooks()->at(i).getTitle() << std::endl;
	}
}

/**
 * used to return books to library system from Reader
 */
void Reader::ReturnBooks(std::vector<BookCopy>& x, int date)
{
	//First we calculate the value of the date
	std::string idValue = "";
	int i = 0, j;
	std::string reserveAnswer = "";

	for (int iter = 0; iter < float(clock()) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;

	std::cout << "Enter the ID of the book you want to return: " << std::endl;
	std::string id;
	std::cin >> id;
	for (i = 0; i < x.size(); i++)//Loop through all books
	{
		if (id == x[i].getID())//Check if this is ID we want
		{
			for (j = 0; j < GetBorrowedBooks()->size(); j++)//See if this reader has the book taken out
			{
				if (GetBorrowedBooks()->at(j).getID() == id)//Case where the reader does have the book taken out
				{
					//This function checks to see if any books are overdue
					//If said book is overdue then MaxBorrowed is decremented
					if (current_date > GetBorrowedBooks()->at(j).get_exp_date())//Case where the book was overdue
					{
						std::cout << GetBorrowedBooks()->at(j).getTitle() << " was overdue max books allowed to be taken out has been decreased" << std::endl;
						if (GetMaxBorrowedCurrent() > 1)
						{
							SetMaxBorrowedCurrent(GetMaxBorrowedCurrent() - 1);
						}
					}
					else if (GetMaxBorrowedCurrent() < GetMaxBorrowed())//Case where overdue and we add to max books allowed to be borrowed
					{
						std::cout << GetBorrowedBooks()->at(j).getTitle() << " was not overdue max books allowed to be taken out has been increased" << std::endl;
						SetMaxBorrowedCurrent(GetMaxBorrowedCurrent() + 1);
					}
					//Return book
					x[i].setReaderName("NULL");
					GetBorrowedBooks()->erase(GetBorrowedBooks()->begin() + j);
					std::cout << "Book was returned successfully!!" << std::endl;
					return;
				}
			}
			//Case where the reader has not taken out this book
			std::cout << "You do not have this book borrowed!" << std::endl;
			return;
		}
	}
	//Case where the book ID is not valid
	std::cout << "Could not find the book to return!" << std::endl;
	return;
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
* a reader
*/
std::ostream& operator << (std::ostream& out, Reader& reader)
{
	//Output all variables to ostream seperated by spaces
	out <<
		reader.GetUser() << ' ' <<
		reader.GetPswd() << ' ' <<
		reader.GetMaxBorrowed() << ' ' <<
		reader.GetMaxBorrowedCurrent() << ' ' <<
		reader.GetMaxBorrowDate()
		<< std::endl;
	return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
* a reader
*/
std::istream& operator >> (std::istream& in, Reader& reader)
{
	//Temp variables for reading in values
	std::string Username, Password;
	int maxborrow = 5, maxborrowcur = 5, maxborrowper = 30;

	//Take in values from istream
	in >>
		Username >>
		Password >>
		maxborrow >>
		maxborrowcur >>
		maxborrowper;


	//Set variables based on values taken in
	reader.SetUser(Username);
	reader.SetPswd(Password);
	reader.SetMaxBorrowed(maxborrow);
	reader.SetMaxBorrowedCurrent(maxborrowcur);
	reader.SetMaxBorrowDate(maxborrowper);

	return in;
}