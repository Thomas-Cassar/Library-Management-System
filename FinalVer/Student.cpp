#include "Student.h"

/**
 * @brief default Student constructor
 * 
 * @postcondition creates a new Student object
 * 
 * @postcondition sets Username and Password to "NULL"
 * 
 * @postcondition sets MaxBorrowed to 5
 * 
 * @postcondition sets MaxBorrowedCurrent to 5
 * 
 * @postcondition sets maxBorrowDate to 30
 * 
 * @postcondition sets penalty to 0
*/
Student::Student() : Reader("NULL","NULL",5,5,30,0)
{
	//Default set values that should be overwritten by reading in from a file
}

/**
 * parameterized Student constructor
 * creates a new Student object
 * @param user - string
 * @param pswd - string
 * sets Username to param user
 * sets Password to param pswd
 * sets MaxBorrowed to 5
 * sets MaxBorrowedCurrent to 5
 * sets maxBorrowDate to 30
 */

/**
 * @brief parameterized Student constructor
 * 
 * @param user - string
 * 
 * @param pswd - string
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
Student::Student(std::string user, std::string pswd)
	:Reader(user,pswd, 5, 5, 30, 0)
{
	//Default set values that should be overwritten by reading in from a file
}


