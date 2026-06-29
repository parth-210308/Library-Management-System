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