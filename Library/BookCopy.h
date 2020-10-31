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
	int start_date;
	int res_date;
	int exp_date;
public:
	BookCopy();
	BookCopy(std::string isbn, std::string title, std::string author, std::string category, std::string id, std::string reader_name,
		int startDate, int resDate, int expDate);
	std::string getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getCategory();
	std::string getID();
	std::string getReaderName();
	int get_start_date();
	int get_res_date();
	int get_exp_date();
	void setISBN(std::string isbn);
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setCategory(std::string category);
	void setID(std::string id);
	void setReaderName(std::string reader_name);
	void set_start_date(int startDate);
	void set_res_date(int resDate);
	void set_exp_date(int expDate);
	std::vector <std::string> reservees;
	friend std::ostream& operator << (std::ostream& out, BookCopy* book);
	friend std::istream& operator >> (std::istream& in, BookCopy* book);
};


