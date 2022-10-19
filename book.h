#ifndef CLASS_BOOK_
#define CLASS_BOOK_
#include <string>
using namespace std;

class Book
{
private:
    string ISBN;
    string title;
    string author;
    char bookType;  // R/r - recreational, A/a - academic, N/n-neither
    int bookStatus; // 1- purchased, 2-rented, 3-neither of these
    int numPages;
    int currentPage;
    float price; // amount paid to purchase or rent book

public:
    Book(string, string, string, int);
    Book();

    string getISBN();
    string getTitle();
    string getAuthor();
    float getPrice();
    char getBookType();
    int getBookStatus();
    int getPages();
    int getCurrentPage();

    void acquireBook(int, char, float);
    void readPage();
    void jumpPages(int);
    void backup(int);
    void returnBook();
    void changeBook(string, string, string, int);

}; // class Book

#endif
