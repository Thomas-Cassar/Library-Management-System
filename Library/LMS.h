#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Librarian.h"
#include "Teacher.h"
#include "Student.h"
#include "BookCopy.h"

enum UserType
{
	NULLUSER, StudentUser, TeacherUser, LibrarianUser
};

class LMS
{
private:
	std::fstream StudentFile;
	std::fstream TeacherFile;
	std::fstream LibrarianFile;
	std::fstream BookFile;

	std::vector<Student> StudentList;
	std::vector<Teacher> TeacherList;
	std::vector<Librarian> LibrarianList;
	std::vector<BookCopy> CopyList;

	std::string LoggedInUsername;

	UserType usertype;
	
	
public:
	LMS();
	~LMS();

	UserType GetUserType();

	UserType LogIn();

	void PrintCommands();


};

