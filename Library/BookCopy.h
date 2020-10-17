#pragma once
#include <string>
#include <vector>
#include <iostream>
class BookCopy
{
private:
	std::string ISBN;
	std::string Title;
	std::string Author;
	std::string Category;
	std::string ID;
	std::string readerName;
	std::string start_date;
	std::string res_date;
	std::string exp_date;
public:
	BookCopy();
	BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
		std::string startDate, std::string resDate, std::string expDate);
	std::string getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getCategory();
	std::string getID();
	std::string getReaderName();
	std::string get_start_date();
	std::string get_res_date();
	std::string get_exp_date();
	void setISBN(std::string isbn);
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setCategory(std::string category);
	void setID(std::string id);
	void setReaderName(std::string reader_name);
	void set_start_date(std::string startDate);
	void set_res_date(std::string resDate);
	void set_exp_date(std::string expDate);
	std::vector <std::string> reservees;

	//
	void operator << (std::ostream& out);
	void operator >> (std::istream& in);
	//
};

