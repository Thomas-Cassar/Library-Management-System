#include "Reader.h"
#include <ctime>

/**
 * @brief parameterized Reader constructor
 * 
 * @param user - string
 * 
 * @param pswd - string
 * 
 * @param maxBorrowed - int
 * 
 * @param maxBorrowedCurrent - int
 * 
 * @param maxBorrowDate - int
 * 
 * @param penalty - int
 * 
 * @postcondition new Reader object created
 * 
 * @postcondition Username set to param user
 *				Password set to param pswd
 *				maxBorrowed set to param maxBorrowed
 *				maxBorrowedCurrent set to param maxBorrowedCurrent
 *				maxBorrowDate set to param maxBorrowDate
 *				penalty set to param penalty
*/
Reader::Reader(std::string user, std::string pswd, int maxBorrowed,
	int maxBorrowedCurrent, int maxBorrowDate, int penalty) : User(user, pswd),
	maxBorrowed(maxBorrowed),
	maxBorrowedCurrent(maxBorrowedCurrent),
	maxBorrowDate(maxBorrowDate),
	penalty(penalty)
{
}

/**
 * @return vector<BookCopy>* - ReaderBorrowedBooks of
 *  current Reader object
 */
std::vector<BookCopy>* Reader::GetBorrowedBooks()
{
	return &ReaderBorrowedBooks;
}

/**
 * @return vector<BookCopy>* - ReaderReservedBooks of
 *  current Reader object
*/
std::vector<BookCopy>* Reader::GetReservedBooks()
{
	return &ReaderReservedBooks;
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

/**
 * @return int - maxBorrowDate of current Reader object
 */
int Reader::GetMaxBorrowDate()
{
	return maxBorrowDate;
}

/**
 * @return int - penalty of current Reader object
*/
int Reader::GetPenalty()
{
	return penalty;
}


/**
 * @param bBooks - vector<BookCopy>
 * 
 * @postcondition ReaderBorrowedBooks vector of current Reader 
 *  set to param bBooks
 */
void Reader::SetBorrowedBooks(std::vector<BookCopy> bBooks)
{
	this->ReaderBorrowedBooks = bBooks;
}

/**
 * @param maxBorrowed - int
 * 
 * @postcondition MaxBorrowed of current Reader set to param maxBorrowed
 */
void Reader::SetMaxBorrowed(int maxBorrowed)
{
	this->maxBorrowed = maxBorrowed;
}

/**
 * @param maxBorrowedCurrent - int
 * 
 * @postcondition MaxBorrowedCurrent of current Reader set to param maxBorrowedCurrent
 */
void Reader::SetMaxBorrowedCurrent(int maxBorrowedCurrent)
{
	this->maxBorrowedCurrent = maxBorrowedCurrent;
}

/**
 * @param maxBorrowDate - int
 * 
 * @postcondition maxBorrowDate of current Reader set to param maxBorrowDate
*/
void Reader::SetMaxBorrowDate(int maxBorrowDate)
{
	this->maxBorrowDate = maxBorrowDate;
}

/**
 * @param pnlty - int
 * 
 * @postcondition penalty of current Reader set to param pnlty
*/
void Reader::SetPenalty(int pnlty)
{
	penalty = pnlty;
}

/*
* This fuction is called from the main loop if the user wants to borrow a book
*/
void Reader::BorrowBook(std::vector <BookCopy>& x, std::vector<Book>& y, int date)
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
			if (!x[i].getReserverList()->empty())
			{
				if (x[i].returnBook()->getReserverList()->at(0) == GetUser())
				{
					std::cout << "You are the first reservee in the list!" << std::endl;
					for (int j = 0; j < x.size(); j++)
					{
						if (x[i].getISBN() == x[j].getISBN() && x[j].get_available())
						{
							std::cout << "Copy with id " << x[j].getID() << " is available! Would you like to borrow it?" << std::endl;
							std::cout << "Enter 0 for Yes, 1 for No" << std::endl;
							int ans;
							std::cin >> ans;
							if (ans == 0)
							{
								x[j].setReaderName(GetUser());
								x[j].set_start_date(current_date);
								x[j].set_exp_date(current_date + GetMaxBorrowDate() - x[i].getReserverList()->size() / 20);
								x[j].set_available(false);
								for (int it = 0; it < x.size(); it++)
								{
									if (x[it].getISBN() == x[j].getISBN())
									{
										for (int its = 0; its < x[it].getReserverList()->size(); its++)
										{
											if (x[it].getReserverList()->at(its) == GetUser())
											{
												x[it].getReserverList()->erase(x[it].getReserverList()->begin() + its);
											}
										}
									}
								}
								for (int it = 0; it < y.size(); it++)
								{
									if (y[it].getISBN() == x[j].getISBN())
									{
										for (int its = 0; its < y[it].getReserverList()->size();its++)
										{
											if (y[it].getReserverList()->at(its) == GetUser())
											{
												y[it].getReserverList()->erase(y[it].getReserverList()->begin() + its);
											}
										}
									}
								}
								for (int q = 0; q < ReaderReservedBooks.size(); q++)
								{
									if (x[j].getID() == ReaderReservedBooks[q].getID())
									{
										ReaderReservedBooks.erase(ReaderReservedBooks.begin() + q);
									}
								}
								GetBorrowedBooks()->push_back(x[j]);
								std::cout << x[j].getTitle() << " has been successfully borrowed!" << std::endl;
								return;
							}
							else if (ans == 1)
							{
								std::cout << "This copy was not borrowed!" << std::endl;
							}
							else
							{
								std::cout << "Wrong command!" << std::endl;
							}
						}
					}
				}
				std::cout << "This book is not available!" << std::endl;
				return;
			}
			if (x[i].getReaderName() == "NULL")//Case where the book is not taken out
			{
				x[i].setReaderName(GetUser());
				x[i].set_start_date(current_date);
				x[i].set_exp_date(current_date + GetMaxBorrowDate() - x[i].getReserverList()->size()/20);
				x[i].set_available(false);
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
	int i = 0, j, u = 0;
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
						std::cout << GetBorrowedBooks()->at(j).getTitle() << " was overdue penalty has increased" << std::endl;
						penalty++;
					}
					SetMaxBorrowedCurrent(GetMaxBorrowedCurrent() - penalty / 5);
					/*else if (GetMaxBorrowedCurrent() < GetMaxBorrowed())//Case where overdue and we add to max books allowed to be borrowed
					{
						std::cout << GetBorrowedBooks()->at(j).getTitle() << " was not overdue max books allowed to be taken out has been increased" << std::endl;
						SetMaxBorrowedCurrent(GetMaxBorrowedCurrent() + 1);
					}*/
					//Return book
					for (int iter = 0; iter < float(clock()) / 1000; iter++)
					{
						if (iter != 0 && iter % 5 == 0)
						{
							u++;
						}
					}
					current_date = u + date;
					x[i].set_reserve_date(current_date);
					x[i].setReaderName("NULL");
					x[i].set_available(true);
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

//NEED TO FINISH
void Reader::ReserveBooks(std::vector<BookCopy>& x, std::vector<Book>& y, int date)
{
	int i = 0;
	for (int iter = 0; iter < float(clock()) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;
	std::cout << "Enter the ID of the book you want to reserve: " << std::endl;
	std::string id;
	std::cin >> id;
	for (i = 0; i < x.size(); i++)//Loop through all books
	{
		if (id == x[i].getID())//Check if this is ID we want
		{
			for (int j = 0; j < GetBorrowedBooks()->size(); j++)//See if this reader has the book taken out
			{
				//This function checks to see if any books are overdue
				if (current_date > GetBorrowedBooks()->at(j).get_exp_date())//Case where the book was overdue
				{
					std::cout << "You have overdue books. You can't reserve any books!" << std::endl;
					return;
				}
			}
			if (x[i].getReaderName() == GetUser())
			{
				std::cout << "You are already borrowing this book!" << std::endl;
				return;
			}
			for (int k = 0; k < x[i].getReserverList()->size(); k++)
			{
				if (x[i].getReserverList()->at(k) == GetUser())
				{
					std::cout << "You are already in the reservation list!" << std::endl;
					return;
				}
			}
			if (x[i].getReserverList()->empty())
			{
				x[i].set_reserve_date(current_date);
			}
			x[i].getReserverList()->push_back(GetUser());
			for (int k = 0; k < y.size(); k++)
			{
				if (x[i].getISBN() == y[k].getISBN())
				{
					y[k].getReserverList()->push_back(GetUser());
				}
			}
			ReaderReservedBooks.push_back(x[i]);
			std::cout << "You have been added to the reservation list!" << std::endl;
			return;
		}
	}
	std::cout << "Could not find the book to reserve!" << std::endl;
	return;
}

void Reader::CancelReservation(std::vector<BookCopy>& x, std::vector<Book>& y, int date)
{
	std::cout << "Enter the ID of the book you want to cancel reservation: " << std::endl;
	std::string id;
	std::cin >> id;
	for (int i = 0; i < x.size(); i++)
	{
		if (id == x[i].getID())
		{
			for (int k = 0; k < x[i].getReserverList()->size(); k++)
			{
				if (x[i].getReserverList()->at(k) == GetUser())
				{
					x[i].getReserverList()->erase(x[i].getReserverList()->begin() + k);
					for (int j = 0; j < y.size(); j++)
					{
						if (y[j].getISBN() == x[i].getISBN())
						{
							for (int s = 0; s < y[j].getReserverList()->size(); s++)
							{
								if (y[j].getReserverList()->at(s) == GetUser())
								{
									y[j].getReserverList()->erase(y[j].getReserverList()->begin() + s);
									break;
								}
							}
						}
					}
					for (int s = 0; s < ReaderReservedBooks.size(); s++)
					{
						if (x[i].getID() == ReaderReservedBooks[s].getID())
						{
							ReaderReservedBooks.erase(ReaderReservedBooks.begin() + s);
							std::cout << "Cancelled reservation succesfully!" << std::endl;
							return;
						}
					}
				}
			}
			std::cout << "You have not reserved this book!" << std::endl;
			return;
		}
	}
	std::cout << "Book not found in library!" << std::endl;
}

void Reader::RenewBook(std::vector<BookCopy>& x, int date)
{
	int i = 0;
	for (int iter = 0; iter < float(clock()) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			i++;
		}
	}
	int current_date = i + date;
	std::cout << "Enter the ID of the book to renew!" << std::endl;
	std::string id;
	std::cin >> id;
	for (i = 0; i < x.size(); i++)
	{
		if (id == x[i].getID())
		{
			for (int j = 0; j < GetBorrowedBooks()->size(); j++)//See if this reader has the book taken out
			{
				//This function checks to see if any books are overdue
				if (current_date > GetBorrowedBooks()->at(j).get_exp_date())//Case where the book was overdue
				{
					std::cout << "You have overdue books. You can't renew the book!" << std::endl;
					return;
				}
			}
			if (!x[i].getReserverList()->empty())
			{
				std::cout << "The book cannot be renewed as people are waiting in line!" << std::endl;
				return;
			}
			for (int j = 0; j < GetBorrowedBooks()->size(); j++)//See if this reader has the book taken out
			{
				if (id == GetBorrowedBooks()->at(j).getID())
				{
					x[i].set_exp_date(current_date + GetMaxBorrowDate());
					x[i].set_available(false);
					std::cout << "Book has been succesfully renewed!" << std::endl;
					return;
				}
			}
			std::cout << "You are not borrowing this book!" << std::endl;
			return;
		}
	}
	std::cout << "Book was not found in the library!" << std::endl;
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
*  an output stream
*/
std::ostream& operator << (std::ostream& out, Reader& reader)
{
	//Output all variables to ostream seperated by spaces
	out <<
		reader.GetUser() << ' ' <<
		reader.GetPswd() << ' ' <<
		reader.GetMaxBorrowed() << ' ' <<
		reader.GetMaxBorrowedCurrent() << ' ' <<
		reader.GetMaxBorrowDate() << ' ' <<
		reader.GetPenalty()
		<< std::endl; 
	return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
*  an input stream
*/
std::istream& operator >> (std::istream& in, Reader& reader)
{
	//Temp variables for reading in values
	std::string Username, Password;
	int maxborrow = 5, maxborrowcur = 5, maxborrowper = 30, pen = 0;

	//Take in values from istream
	in >>
		Username >>
		Password >>
		maxborrow >>
		maxborrowcur >>
		maxborrowper >>
		pen;


	//Set variables based on values taken in
	reader.SetUser(Username);
	reader.SetPswd(Password);
	reader.SetMaxBorrowed(maxborrow);
	reader.SetMaxBorrowedCurrent(maxborrowcur);
	reader.SetMaxBorrowDate(maxborrowper);
	reader.SetPenalty(pen);
	return in;
}