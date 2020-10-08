#include "LMS.h"

LMS::LMS()
{
	usertype = NULLUSER;
	//Open files
	//Students
	StudentFile.open("StudentsData.txt");
	//Teachers
	TeacherFile.open("TeachersData.txt");
	//Librarians
	LibrarianFile.open("LibrariansData.txt");
	//Books
	BookFile.open("BookCopiesData.txt");
//Check successful
	if (StudentFile.fail())
	{
		std::cerr << "Could not open student file";
		exit(1);
	}
	if (TeacherFile.fail())
	{
		std::cerr << "Could not open teacher file";
		exit(1);
	}
	if (LibrarianFile.fail())
	{
		std::cerr << "Could not open librarian file";
		exit(1);
	}
	if (BookFile.fail())
	{
		std::cerr << "Could not open book file";
		exit(1);
	}

//Read from files and store in vectors
	std::string usrtemp, pswdtemp;//Vars for storing read usr/pswd

//Student reading
	Student stutemp;
	StudentFile >> usrtemp >> pswdtemp;
	while (usrtemp != "$$$")
	{
		stutemp.SetUser(usrtemp);
		stutemp.SetPswd(pswdtemp);

		StudentList.push_back(stutemp);

		StudentFile >> usrtemp >> pswdtemp;
	}

//Teacher reading
	Teacher teatemp;
	TeacherFile >> usrtemp >> pswdtemp;
	while (usrtemp != "$$$")
	{
		teatemp.SetUser(usrtemp);
		teatemp.SetPswd(pswdtemp);

		TeacherList.push_back(teatemp);

		TeacherFile >> usrtemp >> pswdtemp;
	}

//Librarian reading
	Librarian libtemp;
	LibrarianFile >> usrtemp >> pswdtemp;
	while (usrtemp!="$$$")
	{
		libtemp.SetUser(usrtemp);
		libtemp.SetPswd(pswdtemp);

		LibrarianList.push_back(libtemp);

		LibrarianFile >> usrtemp >> pswdtemp;
	}

	
}

LMS::~LMS()
{
	//Close all files on class destruction
	StudentFile.close();
	TeacherFile.close();
	LibrarianFile.close();
	BookFile.close();

}

UserType LMS::LogIn()
{
	

	std::string tempusr, temppswd;

	std::cout << "Enter user name:" << std::endl;
	std::cin >> tempusr;
	std::cout << "Enter password:" << std::endl;
	std::cin >> temppswd;

	//Loop through all students
	for (auto &i : StudentList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())
			{
				LoggedInUsername = tempusr;
				usertype = StudentUser;
				return StudentUser;
			}
			else
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}

	//Loop through all teachers
	for (auto& i : TeacherList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())
			{
				LoggedInUsername = tempusr;
				usertype = TeacherUser;
				return TeacherUser;
			}
			else
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}
	
	//Loop through all librarians
	for (auto& i : LibrarianList)
	{
		if (tempusr == i.GetUser())
		{
			if (temppswd == i.GetPswd())
			{
				LoggedInUsername = tempusr;
				usertype = LibrarianUser;
				return LibrarianUser;
			}
			else
			{
				std::cout << "Wrong password" << std::endl;
				exit(0);
			}
		}
	}
	
	std::cout << "User not found" << std::endl;
	exit(0);
}
