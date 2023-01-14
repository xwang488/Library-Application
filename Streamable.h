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
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>

namespace sdds {
   class Streamable {
   public:
      virtual bool conIO(std::istream&)const = 0;
      virtual bool conIO(std::ostream&)const = 0;
      virtual std::ostream& write(std::ostream&) const = 0;
      virtual std::istream& read(std::istream&) = 0;
      virtual operator bool()const = 0;
      virtual ~Streamable() {};
      friend std::istream& operator>>(std::istream& is, Streamable& OR);
      friend std::ostream& operator<<(std::ostream& os, const Streamable& OR);
   };
}

#endif
