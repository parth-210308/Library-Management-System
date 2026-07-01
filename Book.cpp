#include "Book.h"
//this my first git modification
void Book::addBook()
{
    cout << "Enter Book ID : ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title : ";
    getline(cin,title);

    cout<< "Enter Author : ";
    getline(cin,author);

    cout << "Enter totalCopies : ";
    cin>>totalCopies;

    cout << "Enter availableCopies : ";
    cin>>availableCopies;

    if(availableCopies>totalCopies)
    {
        cout<<"availableCopies should be less than equal to totalCopies !!\n";
        cout << "Enter availableCopies : ";
        cin >> availableCopies;
    }
    
    cin.ignore();
    
    cout << "Enter genre : ";
    getline(cin,genre);
}

void Book::displayBook()
{
    cout<<"ID : "<<id<<endl;
    cout<<"Title : "<<title<<endl;
    cout<<"Author : "<<author<<endl;
    cout<<"TotalCopies : "<<totalCopies<<endl;
    cout<<"AvailableCopies : "<<availableCopies<<endl;
    cout<<"Genre : "<<genre<<endl;
}

int Book::getId()
{
    return id;
}

int Book::getAvailableCopies()
{
    return availableCopies;
}

void Book::addCopy()
{
    availableCopies++;
}

void Book::issueCopy()
{
    if(availableCopies>0)availableCopies -= 1;
}