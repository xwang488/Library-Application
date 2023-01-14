/*
            Ms-5
Full Name  :Jennifer Wang
Student ID#: 169554219
Email      : xwang488@myseneca.ca
Section    : NII
Date       :2022/8/05
Version 1.0
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
namespace sdds
{
    Book::Book() {
        author_name = nullptr;
    }
    char Book::type()const {
        return 'B';
    }
    //Streamable pure virtual function implementations
//-----------------------------------------------
    bool Book::conIO(istream& is) const {
        bool valid = false;
        if (&is == &cin) {
            valid = true;
        }
        return valid;
    }
    bool Book::conIO(ostream& os) const {
        bool valid = false;
        if (&os == &cout) {
            valid = true;
        }
        return valid;
    }

    ostream& Book::write(ostream& os) const {
        Publication::write(os);
        if (conIO(os)) {
           
            if (strlen(author_name) > SDDS_AUTHOR_WIDTH) {
                os << " ";
                for(int i= 0; i < SDDS_AUTHOR_WIDTH && author_name[i]!='\0'; i++)
                os << author_name[i] ;
            }
            else {
                os << " ";
                os.width(SDDS_AUTHOR_WIDTH);
                os.fill(' ');
                cout.setf(ios::left);
                os << author_name ;
            }
            os << " |";
        }
        else {
            os << "\t" << author_name;
        }
        return os;
    }
    istream& Book::read(istream& istr) {
        Publication::read(istr);
        char temp_name[256]{};
        delete[] author_name;
        author_name = nullptr;
        if (conIO(istr)) {
            istr.ignore(1, '\n');
            cout << "Author: ";
            istr.get(temp_name, 256,'\n');
        }
        else {
            istr.ignore(1, '\t');
            istr.get(temp_name, 256, '\n');
        }
        if (istr) {
            author_name = new char[strlen(temp_name) + 1];
            strcpy(author_name, temp_name);
        }
        return istr;
    }
    void Book::set(int member_id){
        Publication::set(member_id);
        Publication::resetDate();
    }
    Book::operator bool() const {
        bool valid = false;
        if (Publication::operator bool()&& author_name!=nullptr) {
            valid = true;
        }
        return valid;
    }
    Book::~Book() {
        delete[] author_name;
        author_name = nullptr;
    }

    Book::Book(const Book& b) {
        *this = b;
    }
    Book& Book::operator=(const Book& b) {
        Publication::operator=(b);
        if (this != &b) {
            if (b.author_name != nullptr) {
                delete[] author_name;
                author_name = new char[strlen(b.author_name) + 1];
                strcpy(author_name, b.author_name);
            }
        }
        return *this;
    }
}