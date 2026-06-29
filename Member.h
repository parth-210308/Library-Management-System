#ifndef MEMBER_H
#define MEMBER_H

#include<iostream>
#include<vector>
#include<string>


class Member
{
    private:
        int id;
        std::string name;
        std::string mobile_no;

    public:

        void addMember();
        void displayMember();
        int getId();
};

#endif