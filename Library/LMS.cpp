#include "LMS.h"
#include <conio.h>
#include <ctime>

LMS::LMS()
{
	//Initial Date of LMS
	Date = "01/01/01";

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

UserType LMS::GetUserType()
{
	return usertype;
}

UserType LMS::LogIn()
{
	

	std::string tempusr="", temppswd="";
	char c;

	std::cout << "Enter user name:" << std::endl;
	std::cin >> tempusr;
	std::cout << "Enter password:" << std::endl;

	int i = 0;
	while (((c = _getch()) != '\r')&&(c!='\n'))
	{
		temppswd+= c;
		std::cout << "*";
		i++;
	}
	std::cout << std::endl;

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

void LMS::PrintCommands()
{
	std::cout << "Enter a command from the list below:" << std::endl;
	switch (usertype)
	{
	case StudentUser:
		std::cout << "\t1. Search Books" << std::endl;
		std::cout << "\t2. Borrow Books" << std::endl;
		std::cout << "\t3. Return Books" << std::endl;
		std::cout << "\t4. Reserve Books" << std::endl;
		std::cout << "\t5. Cancel Reservations" << std::endl;
		std::cout << "\t6. My Information" << std::endl;
		std::cout << "\t7. Change Password" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
		break;

	case TeacherUser:
		std::cout << "\t1. Search Books" << std::endl;
		std::cout << "\t2. Borrow Books" << std::endl;
		std::cout << "\t3. Return Books" << std::endl;
		std::cout << "\t4. Reserve Books" << std::endl;
		std::cout << "\t5. Cancel Reservations" << std::endl;
		std::cout << "\t6. My Information" << std::endl;
		std::cout << "\t7. Change Password" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
		break;

	case LibrarianUser:
		std::cout << "\t1. Search Books" << std::endl;
		std::cout << "\t2. Add Books" << std::endl;
		std::cout << "\t3. Delete Books" << std::endl;
		std::cout << "\t4. Search Users" << std::endl;
		std::cout << "\t5. Add Users" << std::endl;
		std::cout << "\t6. Delete Users" << std::endl;
		std::cout << "\t7. My Information" << std::endl;
		std::cout << "\t8. Change Password" << std::endl;
		std::cout << "\t0. Log Out" << std::endl;
		break;

	default:
		std::cerr << "Critical error user type not found" << std::endl;
		break;
	}
}

std::vector<BookCopy> LMS::returnBookCopy()
{
	return CopyList; 
}

void LMS::AddBooks()
{
	BookCopy book;
	std::string ISBN;
	std::cout << "Enter the ISBN of the book: " << std::endl;
	std::cin >> ISBN;
	book.setISBN(ISBN);
	std::string Title;
	std::cout << "Enter the title of the book: " << std::endl;
	std::cin >> Title;
	book.setTitle(Title);
	std::string auth;
	std::cout << "Enter the author of the book: " << std::endl;
	std::cin >> auth;
	book.setAuthor(auth);
	std::string cat;
	std::cout << "Enter the category of the book: " << std::endl;
	std::cin >> cat;
	book.setCategory(cat);
	std::string id = "";
	const char nums[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int x;
	for (x = 0; x < 16; x++)
	{
		id += nums[rand() % (sizeof(nums) - 1)];
	}
	book.setID(id);
	book.set_start_date(Date);
	CopyList.push_back(book);
}

void LMS::DeleteBooks()
{
	BookCopy book;
	int i = 0, pos, flag = 0;
	std::string idstr;
	std::cout << "Enter ID of the copy to delete: " << std::endl;
	std::cin >> idstr;
	for (i=0;i<CopyList.size();i++)
	{
		if (idstr == CopyList[i].getID())
		{
			pos = i;
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		CopyList.erase(CopyList.begin() + pos);
		std::cout << "Copy succesfully removed from library!" << std::endl;
	}
	else
	{
		std::cout << "Copy was not found in library!" << std::endl;
	}
}
