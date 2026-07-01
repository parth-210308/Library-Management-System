#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<iostream>
#include<string>

class Transaction
{
    private:
        int memberId;
        int bookId;

        std::string issueDate;
        std::string dueDate;

        bool returned;

    public:
        void createTransaction(int memberId,int bookId,std::string issueDate,std::string dueDate);
        void displayTransaction();
        bool hasReturned();
        bool matchTransaction(int memberID, int bookID);
        void markReturned();
};

#endif