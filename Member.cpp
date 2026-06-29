#include "Member.h"

using namespace std;

void Member::addMember()
{
    cout<<"Enter your Id: ";
    cin>>id;
    cin.ignore();

    cout<<"Enter your name : ";
    getline(cin,name);

    cout<<"Enter your mobile no : ";
    cin>>mobile_no;
    cin.ignore();
}

void Member::displayMember()
{
    cout<<"ID : "<<id<<"\n";
    cout<<"NAME : "<<name<<"\n";
    cout<<"MOBILE NO : "<<mobile_no<<"\n";
}

int Member::getId()
{
    return id;
}