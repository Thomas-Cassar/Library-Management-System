#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Librarian.h"
#include "User.h"
#include "BookCopy.h"

class LMS
{
private:
	//File variables
	std::fstream StudentFile;
	std::fstream BookFile;
	std::fstream TeacherFile;
	std::fstream LibrarianFile;
	std::fstream CopyReserverFile;
	std::fstream BookReserverFile;
	//Vectors for storing data read from file
	std::vector<Student> StudentList;
	std::vector<Teacher> TeacherList;
	std::vector<Librarian> LibrarianList;
	std::vector<BookCopy> CopyList;
	std::vector<Book> BookList;

	std::string LoggedInUsername;//Current username
	std::string LMSDate;//Stores date string
	int counter;//Ammount of days since 01/01/01

	User* loggedinUser;

public:
	//Constructor and Destructor
	LMS();
	~LMS();

	//Getter Functions
	std::string getDate();
	int getCounter();
	std::vector <BookCopy>* returnBookCopy();
	std::vector <Book>* returnBook();
	void updateBooks();
	//Setter functions
	void setDate(std::string date);
	void setCounter(int counter);
	void ChangePassword();
	void myInfo();

	//Command functions
	void LogIn();
	void PrintCommands();
	void ExecuteCommand(int command);
	void AutoRemove();
	void incCounter();
	void updateFiles();
	void recommend();
	void addBooks();
	void deleteBooks();
	void deleteOldUser(Reader& reader);
	void searchUser();
	void addUser();
	void searchBooks();
	std::string incrementDate(std::string Date);
};
