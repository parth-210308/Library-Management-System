#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>

#include "Book.h"
#include "Member.h"

class Library
{
    private:
        vector<Book>books;
        vector<Member>members;
    public:
        void addBook();
        void displayBooks();
        int findBook(int ID_NEED);
        void searchBook();
        void removeBook();

        void addMember();
        void displayMembers();
        void getId();
        int findMember(int ID_NEED);
        void searchMember();
        void removeMember();
};

#endif