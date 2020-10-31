#include <iostream>
#include <ctime>
#include <fstream>
#include "LMS.h"
std::string checkDates(LMS &lms, clock_t x);

int main()
{
	LMS mainLMS;//Intitialize LMS class

	Student s1;

	s1 = mainLMS.LogIn();//Prompt user for log in

	int command = -1;//Variable for input command

	srand(time(NULL));//Set the seed for random generators

	std::cout << "Welcome to the Library Management System" << std::endl;

	std::string date;

	std::fstream dateFile("DateData.txt");

	if (dateFile.fail())
	{
		std::cerr << "Could not open date file";
		exit(1);
	}

	int count = 0;

	while (dateFile >> date >> count);

	if (date != "")
	{
		mainLMS.setDate(date);
		mainLMS.setCounter(count);
	}

	dateFile.close();

	dateFile.open("DateData.txt");

	clock_t t = clock();

	clock_t m = t;

	while (command != 0)//Main program loop
	{
		mainLMS.PrintCommands();
		std::cin >> command;
		switch (command)
		{
		std::vector<BookCopy>* copyvectemp; //Pointer that will store address of booklist
		case 1: 
			//mainLMS.recommend();
			break;
		case 2:
			copyvectemp = mainLMS.returnBookCopy();
			s1.StudentBorrowBook(*copyvectemp, mainLMS.getCounter());
			mainLMS.updateFiles();
			break;
		case 3:
			copyvectemp = mainLMS.returnBookCopy();
			s1.ReturnBooks(*copyvectemp);
			mainLMS.updateFiles();
			break;
		case 4:
			std::cout << "The current date is: " << checkDates(mainLMS, t) << std::endl;
			break;
		case 0: 
			break;
		default: 
			std::cout << "Invalid input!";
			break;
		}
		std::cout << std::endl;
	
	}

	m = clock() - m;
	std::string LMSDATE = mainLMS.getDate();

	for (int iter = 0; iter < float(m) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			LMSDATE = mainLMS.incrementDate(LMSDATE);
			mainLMS.incCounter();
		}
	}
	mainLMS.setDate(LMSDATE);
	dateFile << mainLMS.getDate();
	dateFile << " ";
	dateFile << mainLMS.getCounter() << std::endl;


	std::cout << "The date is: " << mainLMS.getDate() << std::endl;

	std::cout << "Goodbye. Thank you for using the Library Management System.";

	dateFile.close();

	return 0;
}

std::string checkDates(LMS &lms, clock_t x)
{
	std::string LMSDATE = lms.getDate();
	clock_t checkDate = clock() - x;
	
	for (int iter = 0; iter < float(checkDate) / 1000; iter++)
	{
		if (iter != 0 && iter % 5 == 0)
		{
			LMSDATE = lms.incrementDate(LMSDATE);
		}
	}
	return LMSDATE;
}