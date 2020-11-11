#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Student.h"
#include "BookCopy.h"

class LMS
{
private:
	//File variables
	std::fstream StudentFile;
	std::fstream BookFile;

	//Vectors for storing data read from file
	std::vector<Student> StudentList;
	std::vector<BookCopy> CopyList;

	std::string LoggedInUsername;//Current username
	std::string LMSDate;//Stores date string
	int counter;//Ammount of days since 01/01/01


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
	Student* LogIn();
	void PrintCommands();
	void incCounter();
	void updateFiles();
	void recommend(Student &s1);
	std::string incrementDate(std::string Date);
};
