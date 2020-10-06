#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Librarian.h"
#include "Teacher.h"
#include "Student.h"
#include "BookCopy.h"

class LMS
{
private:
	std::vector<Student> StudentList;
	std::vector<Teacher> TeacherList;
	std::vector<Librarian> LibrarianList;
	std::vector<BookCopy> CopyList;

	std::string LoggedInUsername;
	
	
public:
	LMS();
	bool LogIn();


};

