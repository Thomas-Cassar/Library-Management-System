#include <iostream>
#include <ctime>
#include <fstream>
#include "LMS.h"
std::string checkDates(LMS &lms, clock_t x);

int main()
{
	LMS mainLMS;//Intitialize LMS class

	Student* s1;//Pointer to logged in student

	s1 = mainLMS.LogIn();//Prompt user for log in

	int command = -1;//Variable for input command

	srand(time(NULL));//Set the seed for random generators

	std::cout << std::endl<<"Welcome to the Library Management System" << std::endl;

	std::string date;// Var for holding date
	// Open date file to read last date on exit
	std::fstream dateFile("DateData.txt");
	if (dateFile.fail())
	{
		std::cerr << "Could not open date file";
		exit(1);
	}

	int count = 0;

	//loop through date file to get the most recent date
	while (dateFile >> date >> count);

	if (date != "")
	{
		mainLMS.setDate(date);
		mainLMS.setCounter(count);
	}

	//Reset fstream flags
	dateFile.close();
	//opens file again
	dateFile.open("DateData.txt");

	clock_t t = clock();

	clock_t m = t;

	while (command != 0)//Main program loop exit when quit command
	{
		//Print commands and take in user input for command
		mainLMS.PrintCommands();
		std::cin >> command;

		switch (command)
		{
		std::vector<BookCopy>* copyvectemp; //Pointer that will store address of booklist

		case 1: //Get recommendations
			mainLMS.recommend(*s1); 
			break;
		case 2://Reader wants to borrow book
			copyvectemp = mainLMS.returnBookCopy();
			s1->StudentBorrowBook(*copyvectemp, mainLMS.getCounter());
			mainLMS.updateFiles();
			break;
		case 3://Reader wants to return book
			copyvectemp = mainLMS.returnBookCopy();
			s1->ReturnBooks(*copyvectemp,mainLMS.getCounter());
			mainLMS.updateFiles();
			break;
		case 4: //Checks current date
			std::cout << "The current date is: " << checkDates(mainLMS, t) << std::endl;
			break;
		case 5://Prints Reader information
			s1->Print();
			break;
		case 0: //Quit
			break;
		default: //Not valid input
			std::cout << "Invalid input!";
			break;
		}
		std::cout << std::endl;
	
	}

	m = clock() - m;
	std::string LMSDATE = mainLMS.getDate();

	//increments the date of LMS system based on the amount of time that has passed between login and logout
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

	mainLMS.updateFiles();
	dateFile.close();

	return 0;
}

//function to check current date, increments date by 1 day after 5 seconds have passed
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