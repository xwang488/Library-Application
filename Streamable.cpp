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
#include "Streamable.h"
using namespace std;

namespace sdds {
   istream& operator>>(istream& is, Streamable& S) {
      
      return S.read(is);
   }
   ostream& operator<<(ostream& os, const Streamable& S) {
      //if (S) {
         S.write(os);
      //}
      return os;
   }
}