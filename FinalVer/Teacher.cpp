#include "Teacher.h"

/**
 * default Teacher constructor
 * creates a new teacher object
 * sets Username and Password to "NULL"
 * sets MaxBorrowed to 5
 * sets MaxBorrowedCurrent to 5
 * sets maxBorrowDate to 30
 */
Teacher::Teacher()
	:Reader("NULL", "NULL", 5, 5, 30)
{
	//Default set values that should be overwritten by reading in from a file
}

/**
 * parameterized Teacher constructor
 * creates a new Teacher object
 * @param user - string
 * @param pswd - string
 * sets Username to param user
 * sets Password to param pswd
 * sets MaxBorrowed to 5
 * sets MaxBorrowedCurrent to 5
 * sets maxBorrowDate to 30
 */
Teacher::Teacher(std::string user, std::string pswd)
	:Reader(user, pswd, 5, 5, 30)
{
	//Default set values that should be overwritten by reading in from a file
}