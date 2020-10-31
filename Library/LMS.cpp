#include "LMS.h"
#include <conio.h>
#include <ctime>

LMS::LMS()
{
	//Initial Date of LMS
	Date = "01/01/01";

	counter = 0;

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
	while (StudentFile >> stutemp)
	{
		StudentList.push_back(stutemp);
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
	book.set_start_date(counter);
	CopyList.push_back(book);
}

void LMS::incCounter()
{
	counter++;
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

std::string LMS::getDate()
{
	return Date;
}

void LMS::setCounter(int counter)
{
	this->counter = counter;
}

int LMS::getCounter()
{
	return counter;
}

void LMS::setDate(std::string date)
{
	Date = date;
}

void LMS::incrementDate()
{
	std::string defaultDate = "01/01/00";
	int i = 0;
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + (Date[7] - '0'))%4 == 0)
	{
		if (Date[3] == '2' && Date[4] == '9')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
			    Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return;
	}
	if (Date[0] == '0' && Date[1] == '2' && (((Date[6] - '0') * 10) + Date[7] - '0') % 4 != 0)
	{
		if (Date[3] == '2' && Date[4] == '8')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
		return;
	}
	if ((Date[1] == '4' || Date[1] == '6' || Date[1] == '9' || (Date[0] == '1' && Date[1] == '1')))
	{
		if (Date[3] == '3' && Date[4] == '0')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[1] == '9')
			{
				Date[0] = '1';
				Date[1] = '0';
			}
			else
				Date[1]++;
		}
		else
		{
			if (Date[4] == '9')
			{
				Date[4] = '0';
				Date[3]++;
			}
			else
			{
				Date[4]++;
			}
		}
	}
	else
	{
		if (Date[3] == '3' && Date[4] == '1')
		{
			Date[3] = '0';
			Date[4] = '1';
			if (Date[0] == '1' && Date[1] == '2')
			{
				for (i = 0; i < 6; i++)
				{
					Date[i] = defaultDate[i];
				}
				if (Date[6] == '9' && Date[7] == '9')
				{
					Date = defaultDate;
				}
				else
				{
					if (Date[7] == '9')
					{
						Date[7] = '0';
						Date[6]++;
					}
					else
					{
						Date[7]++;
					}
				}
			}
			else
			{
				if (Date[1] == '9')
				{
					Date[0] = '1';
					Date[1] = '0';
				}
				else
					Date[1]++;
			}
		}
		else
		{
			if (Date[4] == '9')
			{
				
				Date[4] = '0';
				Date[3]++;

			}
			else
				Date[4]++;
		}
	}
}
