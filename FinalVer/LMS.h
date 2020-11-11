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

	//Vectors for storing data read from file
	std::vector<Student> StudentList;
	std::vector<Teacher> TeacherList;
	std::vector<Librarian> LibrarianList;
	std::vector<BookCopy> CopyList;

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

	//Setter functions
	void setDate(std::string date);
	void setCounter(int counter);

	//Command functions
	void LogIn();
	void PrintCommands();
	void ExecuteCommand(int command);
	void incCounter();
	void updateFiles();
	void recommend();
	std::string incrementDate(std::string Date);
};
