//  file name -- book.cpp
//  This file contains the implementations of the member function of
//  Book class.

//  ========================= header files =======================
#include <iostream> // for console I/O
#include <string>   // for string library
#include <cstring>  // for c string library
#include "book.h"   // for Employee class

//  ======================= namespaces used ======================
using namespace std; // for std functions

Book::Book(string newISBN, string newTitle,
           string newAuthor, int newNumPages)
// purpose: intialize the data members with values
// precondition: none
// postcondition: the new variables should be able to change the content
// of the private variables.
{
    ISBN = newISBN;
    title = newTitle;
    author = newAuthor;
    numPages = newNumPages;

    bookType = 'n';
    bookStatus = 3;
    currentPage = 0;
    price = 0;

} // end of value constructor

Book::Book()
// default constructor
{
    ISBN = "";
    title = "";
    author = "";
    numPages = 0;
    bookType = 'n';
    bookStatus = 3;
    currentPage = 0;
    price = 0;
} // end of default constructor

// accessor functions to retrieve content of member variables (private)
string Book::getISBN()
{
    return ISBN;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

float Book::getPrice()
{
    return price;
}

char Book::getBookType()
{
    return bookType;
}

int Book::getBookStatus()
{
    return bookStatus;
}

int Book::getPages()
{
    return numPages;
}

int Book::getCurrentPage()
{
    return currentPage;
}

void Book::acquireBook(int newBookStatus, char newBookType, float amtPaid)
{
    if (tolower(newBookType) == 'r' || tolower(newBookType) == 'a')
    {
        bookType = newBookType;
    }
    else
    {
        bookType = bookType;
    }

    if (newBookStatus == 1 || newBookStatus == 2)
    {
        bookStatus = newBookStatus;
    }
    else
    {
        bookStatus = bookStatus;
    }

    if (tolower(newBookType) == 'r' || tolower(newBookType) == 'a')
    {
        price = amtPaid;
    }
    else
    {
        price = price;
    }
}

void Book::readPage()
{
    if ((bookStatus != 3) && (currentPage < numPages))
    {
        if (currentPage + 1 < numPages)
        {
            currentPage += 1;
        }
    }
}

void Book::jumpPages(int addPages)
{
    if (!(addPages < 0))
    {
        if ((bookStatus != 3) && (currentPage < numPages))
        {
            if (currentPage + addPages <= numPages)
            {
                currentPage += addPages;
            }
        }
    }
}

void Book::backup(int subPages)
{
    if (!(subPages < 0))
    {
        if ((bookType != 3) && (currentPage != 1))
        {
            if (currentPage - subPages > 0)
            {
                currentPage -= subPages;
            }
        }
    }
}

void Book::returnBook()
{
    if (bookType == 2)
    {
        bookType = 3;
        bookStatus = 'n';
        price = 0.0;
    }
}

void Book::changeBook(string changedISBN, string changedTitle, string changedAuthor, int changedNumPages)
{
    ISBN = changedISBN;
    title = changedTitle;
    author = changedAuthor;
    numPages = changedNumPages;
}
