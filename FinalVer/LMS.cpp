#include "LMS.h"
#include <conio.h>
#include <ctime>
#include <string.h>

/**
 * Constructor for class:
 * Opens files
 * Reads files and adds to the respective vector that we use to store the values
 */
LMS::LMS()
{
	//Initial Date of LMS
	LMSDate = "01/01/01";

	counter = 0;

	//Open files
	//Students
	StudentFile.open("student.txt");
	//Books
	BookFile.open("book.txt");
	//Teacher
	TeacherFile.open("teacher.txt");
	//Librarian
	LibrarianFile.open("librarian.txt");


	//Check if file opening was successful
	if (StudentFile.fail())
	{
		std::cerr << "Could not open student file";
		exit(1);
	}
	if (BookFile.fail())
	{
		std::cerr << "Could not open book file";
		exit(1);
	}
	if (TeacherFile.fail())
	{
		std::cerr << "Could not open teacher file";
		exit(1);
	}
	if (LibrarianFile.fail())
	{
		std::cerr << "Could not open librarian file";
		exit(1);
	}
	//Read from files and store in vectors
	//Book copy reading
	BookCopy booktemp;
	while (BookFile >> booktemp)
	{
		CopyList.push_back(booktemp);
	}

	//Student reading
	Student stutemp;
	while (StudentFile >> stutemp)
	{	
		std::vector<BookCopy> tempbooklist;
	
		for (int i = 0; i < CopyList.size(); i++)//Loop through all books in vector to find books that this user has taken out
		{
			if (CopyList[i].getReaderName() == stutemp.GetUser())
				tempbooklist.push_back(CopyList[i]);
		}
		stutemp.SetBorrowedBooks(tempbooklist);//Add books that the user has taken out to that user
		StudentList.push_back(stutemp);//Add student to list of all active students
	}

	//Teacher reading
	Teacher teatemp;
	while (TeacherFile >> teatemp)
	{
		std::vector<BookCopy> tempbooklist;

		for (int i = 0; i < CopyList.size(); i++)//Loop through all books in vector to find books that this user has taken out
		{
			if (CopyList[i].getReaderName() == teatemp.GetUser())
				tempbooklist.push_back(CopyList[i]);
		}
		teatemp.SetBorrowedBooks(tempbooklist);//Add books that the user has taken out to that user
		TeacherList.push_back(teatemp);//Add teacher to list of all active teachers
	}
	//Librarian reading
	Librarian libtemp;
	while (LibrarianFile >> libtemp)
	{
		LibrarianList.push_back(libtemp);//Add teacher to list of all active librarians
	}

	LogIn();//Get user to log in 

}

/*
* Destructor for the class;
* Makes sure all opened files are closed
*/
LMS::~LMS()
{
	//Close all files on class destruction
	StudentFile.close();
	BookFile.close();
	TeacherFile.close();
	LibrarianFile.close();
}


/**
 * LogIn Function:
 * Called at start of program after construction of an LMS class
 * Gets user input for password and username
 * If valid the function returns the address of the student that is logged in
 */
void LMS::LogIn()
{
	std::string tempusr = "", temppswd = "";//Vars for storing input
	char c;//Var for storing char read

	//Get username
	std::cout << "Enter user name:" << std::endl;
	std::cin >> tempusr;
	std::cout << "Enter password:" << std::endl;

	while (((c = _getch()) != '\r') && (c != '\n'))//This function gets the password and hides it with *
	{
		if (c == '\b')//Case where backspace is entered we move cursor back 1 and remove a * and a letter from the input password
		{
			temppswd = temppswd.substr(0, temppswd.length() - 1);
			std::cout  << '\b';
			std::cout << ' ';
			std::cout << '\b';
		}
		else {//Case where we add letter to the string password
			temppswd += c;
			std::cout << "*";
		}
	}
	std::cout << std::endl;

	//Loop through all students
	for (auto& i : StudentList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())//Case where the input is corrrect and we return the adress of the student
			{
				loggedinUser = &i;
				std::cout << std::endl << "Welcome to the Library Management System" << std::endl;
				return;
			}
			else//Case where entered password is incorrect
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}
	//Loop through all teachers
	for (auto& i : TeacherList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())//Case where the input is corrrect and we return the adress of the teacher
			{
				loggedinUser = &i;
				std::cout << std::endl << "Welcome to the Library Management System" << std::endl;
				return;
			}
			else//Case where entered password is incorrect
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}
	//Loop through all librarians
	for (auto& i : LibrarianList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())//Case where the input is corrrect and we return the adress of the librarian
			{
				loggedinUser = &i;
				std::cout << std::endl << "Welcome to the Library Management System" << std::endl;
				return;
			}
			else//Case where entered password is incorrect
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}

	//Case where entered username is not found
	std::cout << "User not found" << std::endl;
	exit(0);
}

/**
 * Prints all commands possible for the following user
 */
void LMS::PrintCommands()
{
	if (dynamic_cast<Reader*>(loggedinUser)!=nullptr)
	{
		std::cout << "************************************************" << std::endl;
		std::cout << "Reader " << loggedinUser->GetUser() << " enter a command from the list below:" << std::endl;
		std::cout << "\t1. Get Recommended Books" << std::endl;
		std::cout << "\t2. Borrow Books" << std::endl;
		std::cout << "\t3. Return Books" << std::endl;
		std::cout << "\t4. Check Current Date" << std::endl;
		std::cout << "\t5. View My Information" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
	}
	else if (dynamic_cast<Librarian*>(loggedinUser) != nullptr)
	{
		std::cout << "************************************************" << std::endl;
		std::cout << "Librarian "<<loggedinUser->GetUser()<<" enter a command from the list below:" << std::endl;
		std::cout << "\t1. Delete Old User" << std::endl;
		std::cout << "\t2. Search User" << std::endl;
		std::cout << "\t3. Add New User" << std::endl;
		std::cout << "\t4. N/A" << std::endl;
		std::cout << "\t5. N/A" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
	}

}

void LMS::ExecuteCommand(int command)
{
	std::string userin;
	Student s;
	Teacher t;
	if (dynamic_cast<Reader*>(loggedinUser) != nullptr)//User is of reader type
	{
		switch (command)
		{
			std::vector<BookCopy>* copyvectemp; //Pointer that will store address of booklist

		case 1: //Get recommendations
			recommend();
			break;
		case 2://Reader wants to borrow book
			copyvectemp = returnBookCopy();
			dynamic_cast<Reader*>(loggedinUser)->BorrowBook(*copyvectemp, getCounter());
			updateFiles();
			break;
		case 3://Reader wants to return book
			copyvectemp = returnBookCopy();
			dynamic_cast<Reader*>(loggedinUser)->ReturnBooks(*copyvectemp, getCounter());
			updateFiles();
			break;
		case 4: //Checks current date
			std::cout << "The current date is: " << /*checkDates(mainLMS, t)*/"FIX" << std::endl;
			break;
		case 5://Prints Reader information
			dynamic_cast<Reader*>(loggedinUser) ->Print();
			break;
		case 0: //Quit
			break;
		default: //Not valid input
			std::cout << "Invalid input!";
			break;
		}
	}

	if (dynamic_cast<Librarian*>(loggedinUser) != nullptr)//User is of librarian type
	{
		switch (command)
		{
		case 1:
			std::cout << "Enter username to delete: " << std::endl;
			std::cin >> userin;
			for (int i = 0; i < StudentList.size(); i++)
			{
				if (userin == StudentList[i].GetUser())
				{
					s = StudentList[i];
					deleteOldUser(s);
					return;
				}
			}
			for (int i = 0; i < TeacherList.size(); i++)
			{
				if (userin == TeacherList[i].GetUser())
				{
					t = TeacherList[i];
					deleteOldUser(t);
					return;
				}
			}
			deleteOldUser(t);
			break;
		case 2:
			searchUser();
			break;
		case 3:
			addUser();
			break;
		case 4:

			break;
		case 5:

			break;
		case 0: //Quit
			break;
		default: //Not valid input
			std::cout << "Invalid input!";
			break;
		}
	}
	std::cout << std::endl;
}

/**
 * @return vector<BookCopy> pointer - points to the list of books
 */
std::vector<BookCopy>* LMS::returnBookCopy()
{
	return &CopyList;
}

/**
 * Increments counter - the number of days since 01/01/01
 */
void LMS::incCounter()
{
	counter++;
}

/**
 * @return string - the string for LMSDate
 */
std::string LMS::getDate()
{
	return LMSDate;
}

/**
 * sets counter to param counter
 * @param counter - int
 */
void LMS::setCounter(int counter)
{
	this->counter = counter;
}

/**
 * @return int - number of days passed since 01/01/01
 */
int LMS::getCounter()
{
	return counter;
}

/**
 * sets date to param date
 * @param date - string
 */
void LMS::setDate(std::string date)
{
	LMSDate = date;
}

/*
*The following function overrides the existing files with the new data that is stored
* in the vectors studentlist and copylist
*/
void LMS::updateFiles()
{
	BookFile.close();
	StudentFile.close();
	TeacherFile.close();
	LibrarianFile.close();

	//Open files
	//Students
	StudentFile.open("student.txt", std::ofstream::out | std::ofstream::trunc);
	//Teachers
	TeacherFile.open("teacher.txt", std::ofstream::out | std::ofstream::trunc);
	//Books
	BookFile.open("book.txt",std::ofstream::out | std::ofstream::trunc);
	//Librarian
	LibrarianFile.open("librarian.txt", std::ofstream::out | std::ofstream::trunc);
	//Check successful
	if (StudentFile.fail())
	{
		std::cerr << "Could not open student file";
		exit(1);
	}
	if (TeacherFile.fail())
	{
		std::cerr << "Could not open teacher file";
		exit(1);
	}
	if (LibrarianFile.fail())
	{
		std::cerr << "Could not open librarian file";
		exit(1);
	}
	if (BookFile.fail())
	{
		std::cerr << "Could not open book file";
		exit(1);
	}

	int i;
	for (i=0; i<StudentList.size();i++)//Print all students to student file
	{
		StudentFile << StudentList[i];
	}

	for (i = 0; i < TeacherList.size(); i++)//Print all students to teachers file
	{
		TeacherFile << TeacherList[i];
	}

	for (i = 0; i < CopyList.size(); i++)//Print all copies to copy file
	{
		BookFile << CopyList[i];
	}
	for (i = 0; i < LibrarianList.size(); i++)//Print all librarians to librarians file
	{
		LibrarianFile << LibrarianList[i];
	}
}

/*
*The following fuction increments the date and returns a string representing the
* current date
*/
std::string LMS::incrementDate(std::string Date)
{
	std::string defaultDate = "01/01/00";
	int i = 0;
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + (Date[7] - '0')) % 4 == 0)
	{
		if (Date[3] == '2' && Date[4] == '9')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return Date;
	}
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + Date[7] - '0') % 4 != 0)
	{
		if (Date[3] == '2' && Date[4] == '8')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return Date;
	}
	if ((Date[1] == '4' || Date[1] == '6' || Date[1] == '9' || (Date[0] == '1' && Date[1] == '1')))
	{
		if (Date[3] == '3' && Date[4] == '0')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
	}
	else
	{
		if (Date[3] == '3' && Date[4] == '1')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[0] == '1' && Date[1] == '2')
			{
				for (i = 0; i < 6; i++)
				{
					Date[i] = defaultDate[i];
				}
				if (Date[6] == '9' && Date[7] == '9')
				{
					Date = defaultDate;
				}
				else
				{
					if (Date[7] == '9')
					{
						Date[7] = '0';
						Date[6]++;
					}
					else
					{
						Date[7]++;
					}
				}
			}
			else
			{
				if (Date[1] == '9')
				{
					Date[0] = '1';
					Date[1] = '0';
				}
				else
					Date[1]++;
			}
		}
		else
		{
			if (Date[4] == '9')
			{

				Date[4] = '0';
				Date[3]++;

			}
			else
				Date[4]++;
		}
	}
	return Date;
}

/*
*The following function takes in a student by reference and based on the books it currently has taken out 
* it will recommend books of similar genres to any books it has taken out 
*/
void LMS::recommend()
{
	Reader* r1 = dynamic_cast<Reader*>(loggedinUser);

	std::vector <BookCopy> category;
	std::vector <BookCopy> temp = CopyList;//makes new vector so that CopyList is not changed

	for (int i = 0; i < r1->GetBorrowedBooks()->size(); i++)
	{
		category.push_back(r1->GetBorrowedBooks()->at(i));
	}
	int count = 0;
	for (int i = 0; i < category.size(); i++)
	{
		for (int j = i+1; j < category.size();j++)
			if (category[i].getCategory() == category[j].getCategory() && category[j].getCategory() != "")
			{
				category[j].setCategory("");
		    }
	}
	for (int i = 0; i < temp.size(); i++)//removes duplicate copies from temp vector
	{
		for (int j = i + 1; j < temp.size(); j++)
		{
			if (temp[i].getTitle() == temp[j].getTitle() && temp[j].getCategory() != "")
			{
				temp[j].setTitle("");
			}
		}
	}
	std::cout << "Some Books You May Like: " << std::endl;
	/*checks to see all books which match the categories of the books the stuedent has borrowed
	  and if the book has not been taken out
	*/
	for (int j = 0; j < category.size();j++)
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getTitle() != "" && (category[j].getCategory() == CopyList[i].getCategory()) && (temp[i].getReaderName() == "NULL") && (category[j].getTitle() != temp[i].getTitle()))
		{
			std::cout << temp[i].getTitle() << " by " << temp[i].getAuthor() << std::endl;
			count++;
		}
	}
	if (count == 0 && r1->GetBorrowedBooks()->size() == 0)//Case where the reader has no books taken out
	{
		std::cout << "Please borrow a book so that we can get an idea of what you like!" << std::endl;
	}
	else if (count == 0 && r1->GetBorrowedBooks()->size() != 0)//Case where the reader has a book taken out of a unique genre
	{
		std::cout << "There are no books that match the categories of the books you have borrowed!" << std::endl;
	}
}

void LMS::addBooks()
{
	BookCopy book;
	std::string ISBN;
	std::cout << "Enter the ISBN of the book: " << std::endl;
	std::cin >> ISBN;
	book.setISBN(ISBN);
	std::string Title;
	std::cout << "Enter the title of the book: " << std::endl;
	std::cin >> Title;
	book.setTitle(Title);
	std::string auth;
	std::cout << "Enter the author of the book: " << std::endl;
	std::cin >> auth;
	book.setAuthor(auth);
	std::string cat;
	std::cout << "Enter the category of the book: " << std::endl;
	std::cin >> cat;
	book.setCategory(cat);
	std::string id = "";
	const char nums[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int x;
	for (x = 0; x < 16; x++)
	{
		id += nums[rand() % (sizeof(nums) - 1)];
	}
	book.setID(id);
	book.set_start_date(counter);
	CopyList.push_back(book);
}

void LMS::deleteBooks()
{
	BookCopy book;
	int i = 0, pos, flag = 0;
	std::string idstr;
	std::cout << "Enter ID of the copy to delete: " << std::endl;
	std::cin >> idstr;
	for (i = 0;i < CopyList.size();i++)
	{
		if (idstr == CopyList[i].getID())
		{
			pos = i;
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		CopyList.erase(CopyList.begin() + pos);
		std::cout << "Copy succesfully removed from library!" << std::endl;
	}
	else
	{
		std::cout << "Copy was not found in library!" << std::endl;
	}
}

void LMS::deleteOldUser(Reader &reader)
{
	int flg = 0;
	Student* s1;
	Teacher* t1;
	for (int i = 0; i < StudentList.size(); i++)
	{
		if (reader.GetUser() == StudentList[i].GetUser())
		{
			s1 = &StudentList[i];
			if (s1->GetBorrowedBooks()->size() != 0)
			{
				std::cout << "Reader could not be deleted!" << std::endl;
				return;
			}
			else
			{
				for (int j = 0; j < s1->GetReservedBooks()->size(); j++)
				{
					BookCopy* b1 = &s1->GetReservedBooks()->at(j);
					b1->setReserverName("NULL");
				}
				StudentList.erase(StudentList.begin() + i);
				std::cout << "Reader was deleted!" << std::endl;
				return;
			}
		}
	}
	
	for (int i = 0; i < TeacherList.size(); i++)
	{
		if (reader.GetUser() == TeacherList[i].GetUser())
		{
			t1 = &TeacherList[i];
			if (t1->GetBorrowedBooks()->size() != 0)
			{
				std::cout << "Reader could not be deleted!" << std::endl;
				return;
			}
			else
			{
				for (int j = 0; j < t1->GetReservedBooks()->size(); j++)
				{
					BookCopy* b1 = &t1->GetReservedBooks()->at(j);
					b1->setReserverName("NULL");
				}
				TeacherList.erase(TeacherList.begin() + i);
				std::cout << "Reader was deleted!" << std::endl;
				return;
			}
			
		}
	}
	std::cout << "Reader was not found in the system!" << std::endl;
}

void LMS::searchUser()
{
	Librarian l;
	Student s;
	Teacher t;
	std::string userin;
	std::cout << "Enter the username: " << std::endl;
	std::cin >> userin;
	for (int i = 0; i < LibrarianList.size(); i++)
	{
		if (userin == LibrarianList[i].GetUser())
		{
			l = LibrarianList[i];
			std::cout << "Here is the information of the Librarian: " << std::endl;
			std::cout << "Username: " << l.GetUser() << std::endl;
			std::cout << "Password: " << l.GetPswd() << std::endl;
			return;
		}
	}
	for (int i = 0; i < StudentList.size(); i++)
	{
		if (userin == StudentList[i].GetUser())
		{
			s = StudentList[i];
			std::cout << "Here is the information of the Student: " << std::endl;
			std::cout << "Username: " << s.GetUser() << std::endl;
			std::cout << "Password: " << s.GetPswd() << std::endl;
			std::cout << "List of Books the student is currently borrowing: " << std::endl;
			for (int j = 0; j < s.GetBorrowedBooks()->size(); j++)
			{
				std::cout << s.GetBorrowedBooks()->at(j).getTitle();
			}
			return;
		}
	}
	for (int i = 0; i < TeacherList.size(); i++)
	{
		if (userin == TeacherList[i].GetUser())
		{
			t = TeacherList[i];
			std::cout << "Here is the information of the Teacher: " << std::endl;
			std::cout << "Username: " << t.GetUser() << std::endl;
			std::cout << "Password: " << t.GetPswd() << std::endl;
			std::cout << "List of Books the teacher is currently borrowing: " << std::endl;
			for (int j = 0; j < t.GetBorrowedBooks()->size(); j++)
			{
				std::cout << t.GetBorrowedBooks()->at(j).getTitle();
			}
			return;
		}
	}
	std::cout << "User was not found in the system!" << std::endl;
}
void LMS::addUser()
{
	int ch;
	std::string userin, passin;
	std::cout << "Enter the type of User: " << std::endl;
	std::cout << "Choose 1 for Librarian: \nChoose 2 for Student \nChoose 3 for Teacher" << std::endl;
	std::cin >> ch;
	if (ch < 1 || ch > 3)
	{
		std::cout << "Wrong choice!" << std::endl;
		return;
	}
	std::cout << "Enter username of new User" << std::endl;
	std::cin >> userin;
	std::cout << "Enter password of new User" << std::endl;
	std::cin >> passin;
	Librarian l;
	Student s;
	Teacher t;
	switch (ch)
	{
	case 1:
		for (int i = 0; i < LibrarianList.size(); i++)
		{
			if (userin == LibrarianList[i].GetUser())
			{
				std::cout << "User already exists!" << std::endl;
				return;
			}
		}
		l.SetUser(userin);
		l.SetPswd(passin);
		LibrarianList.push_back(l);
		break;
	case 2:
		for (int i = 0; i < StudentList.size(); i++)
		{
			if (userin == StudentList[i].GetUser())
			{
				std::cout << "User already exists!" << std::endl;
				return;
			}
		}
		s.SetUser(userin);
		s.SetPswd(passin);
		StudentList.push_back(s);
		break;
	case 3:
		for (int i = 0; i < TeacherList.size(); i++)
		{
			if (userin == TeacherList[i].GetUser())
			{
				std::cout << "User already exists!" << std::endl;
				return;
			}
		}
		t.SetUser(userin);
		t.SetPswd(passin);
		TeacherList.push_back(t);
		break;
	}
	std::cout << "New user added succesfully!" << std::endl;
}