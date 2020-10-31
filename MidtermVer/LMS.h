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
	std::string LMSDate;
	int counter;


public:
	LMS();
	~LMS();

	std::string getDate();
	void setDate(std::string date);
	std::string incrementDate(std::string Date);
	void setCounter(int counter);
	std::vector <BookCopy>* returnBookCopy();
	Student LogIn();
	int getCounter();
	void PrintCommands();
	void incCounter();
	void updateFiles();
	void recommend(Student &s1);
};
