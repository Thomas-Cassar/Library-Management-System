#include "Teacher.h"

Teacher::Teacher()
{
	Username = "NULL";
	Password = "NULL";
}

Teacher::Teacher(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;
}


void Teacher::SetUser(std::string usr)
{
	Username = usr;
}

void Teacher::SetPswd(std::string pswd)
{
	Password = pswd;
}