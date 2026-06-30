#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>

#include "Book.h"
#include "Member.h"
#include "Transaction.h"

class Library
{
    private:
        vector<Book>books;
        vector<Member>members;
        vector<Transaction> transactions;

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

        void issueBook();
        void displayTransactions();
};

#endif