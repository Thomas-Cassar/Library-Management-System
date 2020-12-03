#include "Teacher.h"

/**
 * @brief default Teacher constructor
 * 
 * @postcondition creates a new Teacher object
 * 
 * @postcondition sets Username to "NULL"
 * 
 * @postcondition sets Password to "NULL"
 * 
 * @postcondition sets MaxBorrowed to 5
 * 
 * @postcondition sets MaxBorrowedCurrent to 5
 * 
 * @postcondition sets maxBorrowDate to 30
 * 
 * @postcondition sets penalty to 0
*/
Teacher::Teacher() : Reader("NULL", "NULL", 5, 5, 30,0)
{
	//Default set values that should be overwritten by reading in from a file
}

/**
 * @brief parameterized Teacher constructor
 * 
 * @param user - string
 * 
 * @param pswd - string
 * 
 * @postcondition creates a new Teacher object
 * 
 * @postcondition sets Username to param user
 * 
 * @postcondition sets Password to param pswd
 * 
 * @postcondition sets MaxBorrowed to 5
 * 
 * @postcondition sets MaxBorrowedCurrent to 5
 * 
 * @postcondition sets maxBorrowDate to 30
 * 
 * @postcondition sets penalty to 0
*/
Teacher::Teacher(std::string user, std::string pswd) : Reader(user, pswd, 5, 5, 30, 0)
{
	//Default set values that should be overwritten by reading in from a file
}