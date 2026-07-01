#include "Transaction.h"

using namespace std;

void Transaction::createTransaction(int memberId, int bookId, string issueDate, string dueDate)
{
    this->memberId = memberId;
    this->bookId = bookId;

    this->issueDate = issueDate;
    this->dueDate = dueDate;

    returned = false;
}

void Transaction::displayTransaction()
{
    cout << "Member ID : " << memberId << endl;
    cout << "Book ID : " << bookId << endl;
    cout << "Issue Date : " << issueDate << endl;
    cout << "Due Date : " << dueDate << endl;
    cout << "Returned : ";

    if (returned)
        cout << "Yes\n";
    else
        cout << "No\n";
}

bool Transaction::hasReturned()
{
    return returned;
}

bool Transaction::matchTransaction(int memberID, int bookID)
{
    return memberId==memberID && bookId==bookID;
}

void Transaction::markReturned()
{
    returned = true;
}