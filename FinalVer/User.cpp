#include "User.h"

/**
 * @brief parameterized User constructor
 * 
 * @param user - string
 * 
 * @param pswd - string
 * 
 * @postcondition new User object created
 * 
 * @postcondition Username set to param user
 * 
 * @postcondition Password set to param pswd
*/
User::User(std::string user, std::string pswd) : Username(user), Password(pswd)
{
}

/**
 * @brief User destructor
*/
User::~User()
{
}

/**
 * @return string - Username of current Student object
 */
std::string User::GetUser()
{
	return this->Username;
}

/**
 * @return string - Password of current Student object
 */
std::string User::GetPswd()
{
	return this->Password;
}

/**
 * @param usr - string
 * 
 * @postcondition Username of current Student set to param usr
 */
void User::SetUser(std::string usr)
{
	this->Username = usr;
}

/**
 * @param pswd - string
 * 
 * @postcondition Password of current Student set to param pswd
 */
void User::SetPswd(std::string pswd)
{
	this->Password = pswd;
}

/**
 * @brief prints details for the current User object
*/
void User::Print()
{
	//Should be overloaded
}
