#include "Librarian.h"

Librarian::Librarian()
{
	Username = "NULL";
	Password = "NULL";
}

Librarian::Librarian(std::string user, std::string pswd)
{
	Username = user;
	Password = pswd;
}


void Librarian::SetUser(std::string usr)
{
	Username = usr;
}

void Librarian::SetPswd(std::string pswd)
{
	Password = pswd;
}