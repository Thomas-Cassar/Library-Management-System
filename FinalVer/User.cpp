#include "User.h"


User::User(std::string user, std::string pswd)
	:Username(user),
	Password(pswd)
{

}

User::~User()
{
}

/**
 * @return string - Username of current Student object
 */
std::string User::GetUser()
{
	return Username;
}

/**
 * @return string - Password of current Student object
 */
std::string User::GetPswd()
{
	return Password;
}

/**
 * sets Username of current Student object to param usr
 * @param usr - string
 */
void User::SetUser(std::string usr)
{
	Username = usr;
}

/**
 * sets Password of current Student object to param pswd
 * @param pswd - string
 */
void User::SetPswd(std::string pswd)
{
	Password = pswd;
}

void User::Print()
{
	//Should be overloaded
}
