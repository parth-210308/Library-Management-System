#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<string>

using namespace std;

class Book
{
    private:
        int id;
        string title;
        string author;
        int totalCopies;
        int availableCopies;
        string genre;

    public:
        void addBook();
        void displayBook();
        int getId();
        int getAvailableCopies();
        void issueCopy();
};

#endif
