//  file name -- assign4.cpp
//  This file contains the client code

//  ========================= header files =======================
#include <iostream>
#include <string>
#include <cstring>
#include "book.h"

//  ======================= symbolic constrantes =================
const int MIN = 1;
const int MAX = 7;
const int DECIMAL = 2;
const int librarySize = 20;

//  ======================= namespaces used ======================
using namespace std;

// ======================== function prototypes ==================

void displayMenu();
void getChoice(int &);
void takeAction(int, Book &);
void acquireNewBook(Book &, int, char, float);
void readNewPage(Book &);
void jumpNewPage(Book &, int);
void newBackup(Book &, int);
void returnNewBook(Book &);
void displayNewBook(Book &);
void changeNewBook(Book &, string, string, string, int);

// int library[librarySize];
// int &bookIndex;

int main()
// beginning of int main
{
    int number, *bookIndex, *otherNum;
    string *bookISBN, *bookTitle, *bookAurthor;
    char *bookTy;
    float *bookPric;
    Book bookLibrary[10];

    cin >> number;

    while (cin)
    {
        bookIndex = new int;
        otherNum = new int;

        bookTy = new char;
        bookPric = new float;

        bookISBN = new string;
        bookTitle = new string;
        bookAurthor = new string;

        if (number == 1)
        {
            cin >> *bookIndex >> *otherNum >> *bookTy >> *bookPric;
            acquireNewBook(bookLibrary[*bookIndex], *otherNum, *bookTy, *bookPric);
        }

        if (number == 2)
        {
            cin >> *bookIndex;
            readNewPage(bookLibrary[*bookIndex]);
        }

        if (number == 3)
        {
            cin >> *bookIndex >> *otherNum;
            jumpNewPage(bookLibrary[*bookIndex], *otherNum);
        }

        if (number == 4)
        {
            cin >> *bookIndex >> *otherNum;
            newBackup(bookLibrary[*bookIndex], *otherNum);
        }

        if (number == 5)
        {
            cin >> *bookIndex;
            returnNewBook(bookLibrary[*bookIndex]);
        }

        if (number == 6)
        {
            cin >> *bookIndex >> *bookISBN >> *bookTitle >> *bookAurthor >> *otherNum;
            changeNewBook(bookLibrary[*bookIndex], *bookISBN, *bookTitle, *bookAurthor, *otherNum);
        }

        if (number == 7)
        {
            cin >> *bookIndex;
            if (*bookIndex == 0)
            {
                for (*otherNum = 0; *otherNum < 10; *otherNum += 1)
                {
                    displayNewBook(bookLibrary[*otherNum]);
                }
            }
            else
            {
                displayNewBook(bookLibrary[*bookIndex - 1]);
            }
        }

        if (number == 8)
        {
            break;
        }

        delete bookIndex, otherNum, bookPric, bookTy, bookISBN, bookTitle, bookAurthor;

        cin >> number;
    }
    return 0;

} // end of main

void acquireNewBook(Book &book, int newBookStatus, char newBookType, float amtPaid)
{
    cout << endl
         << "Option 1 was selected... " << endl;
    cout << "Book status(1- purchased, 2-rented, 3-neither of these): ";
    cout << newBookStatus << endl;

    cout << "Book Type(R/r for recreational, A/a for academic, N/n-neither): ";
    cout << newBookType << endl;

    cout << "Amount paid for book: ";
    cout << amtPaid << endl;

    book.acquireBook(newBookStatus, newBookType, amtPaid);
    cout << endl;
}

void readNewPage(Book &book)
{
    cout << "option 2 was selected... " << endl;
    if (book.getBookStatus() != 3)
    {
        book.readPage();
        cout << "Page read!" << endl;
    }
    else
    {
        cout << "You cannot read this book. You have neither purchased it nor rented it" << endl;
    }
    cout << endl;
}

void jumpNewPage(Book &book, int addPages)
{
    cout << "option 3 was selected... " << endl;
    if (book.getBookStatus() != 3)
    {
        cout << "Number of pages you jumped forward by: ";
        cout << addPages << endl;

        if (addPages > book.getPages() || addPages > book.getPages() - book.getCurrentPage())
        {
            cout << endl
                 << "You cannot jump by " << addPages << " pages. It is more than the number of pages the book has..." << endl;
        }
        else if (addPages < 0)
        {
            cout << endl
                 << "You cannot jump page by a negative number..." << endl;
        }
        else
        {
            book.jumpPages(addPages);
            cout << endl
                 << "You went forward by " << addPages << " number of pages!" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl
             << "You cannot read this book. You have neither purchased it nor rented it" << endl;
    }
}

void newBackup(Book &book, int subPages)
{
    cout << endl
         << "option 4 was selected... " << endl;
    if (book.getBookStatus() != 3)
    {
        cout << "Number of pages you skipped backwards by: ";
        cout << subPages << endl;

        if (subPages > book.getCurrentPage())
        {
            cout << endl
                 << "You cannot backup more than " << book.getCurrentPage() << " number of pages" << endl;
        }
        else if (subPages < 0)
        {
            cout << endl
                 << "You cannot jump page by a negative number..." << endl;
        }
        else
        {
            book.backup(subPages);
            cout << "You went backwards by " << subPages << " number of pages!" << endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl
             << "You cannot read this book. You have neither purchased it nor rented it" << endl;
    }
}

void returnNewBook(Book &book)
{
    cout << endl
         << "option 5 was selected... " << endl;
    if (book.getBookStatus() == 2)
    {
        book.returnBook();
        cout << "you have returned to book. ";
    }
    else
    {
        cout << endl
             << "You can only return a book you rented!" << endl;
    }
    cout << endl;
}

void changeNewBook(Book &book, string changedISBN, string changedTitle, string changedAuthor, int changedNumPages)
{
    cout << "option 6 was selected " << endl;
    cout << "New ISBN: ";
    cout << changedISBN << endl;

    cout << "New Title: ";
    cout << changedTitle << endl;

    cout << "New Author: ";
    cout << changedAuthor << endl;

    cout << "New number of pages: ";
    cout << changedNumPages << endl;

    book.changeBook(changedISBN, changedTitle, changedAuthor, changedNumPages);
    cout << endl;
}

void displayNewBook(Book &book)
{
    cout << "option 7 was selected " << endl;
    cout << "**************************************************" << endl;
    cout << "the state of the book will now be displayed:" << endl
         << endl;
    cout << "The Book title is: " << book.getTitle() << endl;

    if (tolower(book.getBookType()) == 'r')
    {
        cout << "The Book type is: Recreational" << endl;
    }
    else if (tolower(book.getBookType()) == 'a')
    {
        cout << "The Book type is: Academic" << endl;
    }
    else
    {
        cout << "The book is neither recreational nor academic" << endl;
    }

    if (book.getBookStatus() == 1)
    {
        cout << "the book Status is: Purchased" << endl;
    }
    else if (book.getBookStatus() == 2)
    {
        cout << "the book status is: Rented" << endl;
    }
    else
    {
        cout << "You have neither purchased nor rented the book" << endl;
    }

    cout << "The number of pages of the book is: " << book.getPages() << endl;
    cout << "The current page of the book is: " << book.getCurrentPage() << endl;
    cout << "**************************************************" << endl
         << endl;
}

/*
void takeAction(int choice, Book &book1)
{
    int newBookStatus;
    char newBookType;
    int addPages;
    int subPages;
    float amtPaid;

    switch(choice)
    //switch statment to do the required action based on the
    //choice of the user.
    {
        case 1:
                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;

        case 5:
                break;

        case 6:
                break;

        default:
                break;

    }
}

void displayMenu()
// this funciton displays the main menu of the program
{
    cout << "*********************************" << endl;
    cout << "Test book driver" << endl;
    cout << "1.  Acquire Book button" << endl;
    cout << "2.  Press Read button" << endl;
    cout << "3.  Press Jump button" << endl;
    cout << "4.  Press Backup button" << endl;
    cout << "5.  Press Return Book button" << endl;
    cout << "6.  Display book state" << endl;
    cout << "7.  Exit" << endl;
    cout << "please enter your choice: ";
}// end of the main menu

void getChoice(int &option)
//this function asks the user to input a choice based on the menu options.
//if the user inputs a value that is out of bounds, the function will ask them
//to reenter the value. this will continue until the user inputs a value that
//is int he bounds.
{
   do
   {
      cin >> option;
      if (option < MIN || option > MAX)
      {
         cout << "The choice: "
              << option
              << " is out of bounds of the given range a values ."
              << endl;
         cout << "Please enter the value agine ";
      }
   } while (option < MIN || option > MAX);
}// end of function getChoice
*/
