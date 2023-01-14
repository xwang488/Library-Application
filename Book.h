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

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include"Publication.h"

namespace sdds{
    class Book : public Publication
    {
        char* author_name{};
    public:
        Book();
        virtual char type()const;
        bool conIO(std::istream& is)const;
        bool conIO(std::ostream& os)const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);  
        virtual void set(int member_id);
        operator bool() const;
        ~Book();
        Book(const Book& b);
        Book& operator=(const  Book& b);
    };
}
#endif