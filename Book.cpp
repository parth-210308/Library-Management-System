#include "Book.h"

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

    cout << "Enter genre : ";
    cin>>genre;
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