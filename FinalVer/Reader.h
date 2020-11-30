#pragma once
#include "User.h"
#include <vector>
#include "BookCopy.h"

class Reader :
    public User
{
private:
    std::vector<BookCopy> ReaderBorrowedBooks;//Stores all books that reader has borrowed
    std::vector<BookCopy> ReaderReservedBooks;//Stores all books that reader has reserved
    int maxBorrowed, maxBorrowedCurrent;//Max allowed borrowed books and max allowed books at this time
    int maxBorrowDate;//How long the reader can have books for before overdue
    int penalty;
public:
    Reader(std::string user, std::string pswd,int maxBorrowed,
        int maxBorrowedCurrent,int maxBorrowDate, int penalty);

    //Getter functions
    std::vector<BookCopy>* GetBorrowedBooks();
    std::vector<BookCopy>* GetReservedBooks();
    int GetMaxBorrowed();
    int GetMaxBorrowedCurrent();
    int GetMaxBorrowDate();
    int GetPenalty();

    //Setter functions
    void SetPenalty(int pnlty);
    void SetBorrowedBooks(std::vector<BookCopy> bBooks);
    void SetMaxBorrowed(int maxBorrowed);
    void SetMaxBorrowedCurrent(int maxBorrowedCurrent);
    void SetMaxBorrowDate(int maxBorrowDate);

    //Command functions
    void BorrowBook(std::vector <BookCopy>& x, std::vector<Book>& y, int date);
    void ReturnBooks(std::vector<BookCopy>& x, int date);
    void ReserveBooks(std::vector<BookCopy>& x, std::vector<Book>& y, int date);
    void CancelReservation(std::vector<BookCopy>& x, std::vector<Book>& y, int date);
    void RenewBook(std::vector<BookCopy>& x, int date);
    void Print();

    //Overloaded operators
    friend std::ostream& operator << (std::ostream& out, Reader& reader);
    friend std::istream& operator >> (std::istream& in, Reader& reader);
};

// Stream operators
std::ostream& operator << (std::ostream& out, Reader& reader);
std::istream& operator >> (std::istream& in, Reader& reader);

