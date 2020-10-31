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
	std::fstream StudentFile;
	std::fstream BookFile;

	std::vector<Student> StudentList;
	std::vector<BookCopy> CopyList;

	std::string LoggedInUsername;
	std::string Date;
	int counter;


public:
	LMS();
	~LMS();

	std::string getDate();
	void setDate(std::string date);
	void incrementDate();
	void setCounter(int counter);
	std::vector <BookCopy>* returnBookCopy();
	Student LogIn();
	int getCounter();
	void PrintCommands();
	void incCounter();


};
