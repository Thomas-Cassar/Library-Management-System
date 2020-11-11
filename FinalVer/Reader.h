#pragma once
#include "User.h"
#include <vector>
#include "BookCopy.h"

class Reader :
    public User
{
private:
    std::vector<BookCopy> ReaderBorrowedBooks;//Stores all books that reader has borrowed
    int maxBorrowed, maxBorrowedCurrent;//Max allowed borrowed books and max allowed books at this time
    int maxBorrowDate;//How long the reader can have books for before overdue
public:
    Reader(std::string user, std::string pswd,int maxBorrowed,
        int maxBorrowedCurrent,int maxBorrowDate);

    //Getter functions
    std::vector<BookCopy>* GetBorrowedBooks();
    int GetMaxBorrowed();
    int GetMaxBorrowedCurrent();
    int GetMaxBorrowDate();

    //Setter functions
    void SetBorrowedBooks(std::vector<BookCopy> bBooks);
    void SetMaxBorrowed(int maxBorrowed);
    void SetMaxBorrowedCurrent(int maxBorrowedCurrent);
    void SetMaxBorrowDate(int maxBorrowDate);

    //Command functions
    void BorrowBook(std::vector <BookCopy>& x, int date);
    void ReturnBooks(std::vector<BookCopy>& x, int date);
    void Print();

    //Overloaded operators
    friend std::ostream& operator << (std::ostream& out, Reader& reader);
    friend std::istream& operator >> (std::istream& in, Reader& reader);
};

// Stream operators
std::ostream& operator << (std::ostream& out, Reader& reader);
std::istream& operator >> (std::istream& in, Reader& reader);

