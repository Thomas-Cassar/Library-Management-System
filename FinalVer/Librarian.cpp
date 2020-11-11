#include "Librarian.h"


Librarian::Librarian(std::string user, std::string pswd)
	:User(user, pswd)
{

}

Librarian::Librarian()
	: User("NULL", "NULL")
{

}

std::ostream& operator<<(std::ostream& out, Librarian& librarian)
{
	//Output all variables to ostream seperated by spaces
	out <<
		librarian.GetUser() << ' ' <<
		librarian.GetPswd() << ' ' <<
		std::endl;
		return out;
}

std::istream& operator>>(std::istream& in, Librarian& librarian)
{
	std::string user, pswd;
	in >>
		user >>
		pswd;

	librarian.SetUser(user);
	librarian.SetPswd(pswd);

	return in;
}
