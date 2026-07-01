#include "Library.h"

using namespace std;

void Library::addBook()
{
    Book b;
    b.addBook();
    if (findBook(b.getId()) != -1)
    {
        cout << "Book ID already exists.\n";
        return;
    }
    books.push_back(b);
}

void Library::displayBooks()
{
    if(books.empty())
    {
        cout<<"There is no any books !!\n";
        cout << "-----------------\n";
        return;
    }
    for(Book &b:books)
    {
        b.displayBook();
        cout << "-----------------\n";
    }
}

int Library::findBook(int ID_NEED)
{
    for(int i=0;i<books.size();++i)
    {
        Book& b = books[i];
        int id = b.getId();
        if(id==ID_NEED)
        {
            return i;
        }
    }
    return -1;
}

void Library::searchBook()
{
    cout << "Enter Which Id book do you need -->> ";
    cout << endl;
    int ID_NEED;
    cin >> ID_NEED;

    int idx = findBook(ID_NEED);
    if(idx!=-1)
    {
        cout << ".......Book Found :) .......\n";
        books[idx].displayBook();
        return;
    }
    cout << ".......Book Not Found :( ........\n";
}

void Library::removeBook()
{
    cout << "Enter Which id book  do you want to remove ...\n";
    int ID;
    cin>>ID;
    if(ID<=0)
    {
        cout<<"Please!! Enter valid id (Id should be greater than zero):\n";
        return;
    }
    int idx = findBook(ID);
    if(idx==-1)
    {
        cout<<"There is no book with id no -> "<<ID<<" ):\n";
        return;
    }

    books.erase(books.begin() + idx);
    cout << "Book with id->" << ID << " removed successfully (:\n";
}

void Library::addMember()
{
    Member m;
    m.addMember();
    if(findMember(m.getId())!=-1)
    {
        cout << "Member ID already exists.\n";
        return;
    }
    members.push_back(m);
}

void Library::displayMembers()
{
    if(members.empty())
    {
        cout<<"Member list is Empty !!\n";
        cout << "-----------------\n";
        return;
    }
    for(auto&m:members)
    {
        m.displayMember();
    }
    cout << "-----------------\n";
}

int Library::findMember(int ID_NEED)
{
    for (size_t i = 0; i < members.size(); ++i)
    {
        Member &m = members[i];
        int id = m.getId();
        if (id == ID_NEED)
        {
            return i;
        }
    }
    return -1;
}

void Library::searchMember()
{
    cout << "Enter Which id Member do you need -->> ";
    cout << endl;
    int ID_NEED;
    cin >> ID_NEED;

    int idx = findMember(ID_NEED);
    if (idx != -1)
    {
        cout << ".......Member Found :) .......\n";
        members[idx].displayMember();
        return;
    }
    cout << ".......Member Not Found :( ........\n";
}

void Library::removeMember()
{
    cout << "Enter Which id Member  do you want to remove ...\n";
    int ID;
    cin >> ID;  
    if (ID <= 0)
    {
        cout << "Please!! Enter valid id (Id should be greater than zero):\n";
        return;
    }
    int idx = findMember(ID);
    if (idx == -1)
    {
        cout << "There is no Member with id no -> " << ID << " ):\n";
        return;
    }

    members.erase(members.begin() + idx);
    cout << "Member with id->" << ID << " removed successfully (:\n";
}

void Library::issueBook()
{
    int memberId;
    int bookId;

    cout<<"Please !! Enter your Member id : ";
    cin>>memberId;

    int memberIndex = findMember(memberId);
    if (memberIndex == -1)
    {
        cout<<"You're not the member of library ! please Take membership first :)\n";
        return;
    }

    cout << "Enter Book ID :\n";
    cin>>bookId;

    int bookIndex = findBook(bookId);
    if (bookIndex == -1)
    {
        cout<<"This Book is not available in our library :(\n";
        return;
    }

    Book &b = books[bookIndex];

    if (b.getAvailableCopies() == 0)
    {
        cout<<"This books copies are not available :( \n";
        return;
    }

    b.issueCopy();

    Transaction t;
    string issueDate;
    string dueDate;

    cout << "Enter Issue Date : ";
    cin >> issueDate;

    cout << "Enter Due Date : ";
    cin >> dueDate;

    t.createTransaction(memberId,bookId,issueDate,dueDate);
    transactions.push_back(t);
    cout << "Transaction recorded successfully.\n";
    
    cout<<"Book issued succesfully :) \n";
    cout << "Remaining Copies : "
         << b.getAvailableCopies()
         << "\n";
}

int Library::findTransaction(int memberId,int bookId)
{
    for (size_t i = 0; i < transactions.size();++i)
    {
        Transaction &t = transactions[i];
        if(t.matchTransaction(memberId,bookId))
        {
            return i;
        }
    }
    return -1;
}

void Library::returnBook()
{
    cout << "Enter Member ID : ";
    int memberId;
    cin >> memberId;
    cout << "Enter Book ID : ";
    int bookId;
    cin >> bookId;

    int transactionIdx = findTransaction(memberId, bookId);
    if (transactionIdx == -1)
    {
        cout << "You were not take this book \n";
        return;
    }

    Transaction &t = transactions[transactionIdx];

    if(t.hasReturned())
    {
        cout<<"You're areadly returned this book \n";
        return;
    }

    int bookIdx = findBook(bookId);
    Book &b = books[bookIdx];
    b.addCopy();
    transactions.erase(transactions.begin()+transactionIdx);
    cout<<"Book returned succesfully :)\n";
}