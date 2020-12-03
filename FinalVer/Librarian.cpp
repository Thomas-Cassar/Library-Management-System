#include "Librarian.h"

/**
 * @brief default Librarian constructor
 * 
 * @postcondition new Librarian object created
 * 
 * @postcondition Username set to "NULL"
 * 
 * @postcondition Password set to "NULL"
*/
Librarian::Librarian() : User("NULL", "NULL")
{
}

/**
 * @brief parameterized Librarian constructor
 * 
 * @param user - string
 * 
 * @param pswd - string
 * 
 * @postcondition new Librarian object created
 * 
 * @postcondition Username set to param user
 * 
 * @postcondition Password set to param pswd
*/
Librarian::Librarian(std::string user, std::string pswd) : User(user, pswd)
{
}

/*
* This function overloads the << ostream operator to be able to print all variables on one line of
*  an output stream
*/
std::ostream& operator<<(std::ostream& out, Librarian& librarian)
{
	//Output all variables to ostream seperated by spaces
	out <<
		librarian.GetUser() << ' ' <<
		librarian.GetPswd() << ' ' <<
		std::endl;
		return out;
}

/*
* This function overloads the >> istream operator to be able to read all variables on one line of
*  an input stream
*/
std::istream& operator>>(std::istream& in, Librarian& librarian)
{
	std::string user, pswd;
	in >> user >> pswd;

	librarian.SetUser(user);
	librarian.SetPswd(pswd);

	return in;
}
