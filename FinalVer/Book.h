#pragma once
#include <string>
#include <iostream>
class Book
{
	private:
		std::string ISBN;//Stores book ISBN
		std::string Title;//Stores book title
		std::string Author;//Stores book author
		std::string Category;//Stores book category
		int index;
		int count;
		int favor;
	public:
		std::string getISBN();
		std::string getTitle();
		std::string getAuthor();
		std::string getCategory();
		int getIndex();
		int getCount();
		int getFavor();
		void setISBN(std::string isbn);
		void setTitle(std::string title);
		void setAuthor(std::string author);
		void setCategory(std::string category);
		void setIndex(int idx);
		void setCount(int cnt);
		void setFavor(int fvr);
		friend std::ostream& operator << (std::ostream& out, Book& book);
		friend std::istream& operator >> (std::istream& in, Book& book);
};

std::ostream& operator << (std::ostream& out, Book& book);
std::istream& operator >> (std::istream& in, Book& book);