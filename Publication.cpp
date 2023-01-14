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
#include "Date.h"
#include "Publication.h"
using namespace std;

namespace sdds {
   Publication::Publication() {
      setEmpty();
   }
//Modifiers-----------------------------------------------
   void Publication::setEmpty() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
      Date m_date;
   }
   void Publication::set(int member_id) {
      m_membership = member_id;
   }
   void Publication::setRef(int value) {
      m_libRef = value;
   }
   void Publication::resetDate() {
      Date current;
      m_date = current;
   }
//Queries-----------------------------------------------
   char Publication::type() const {
      return 'P';
   }
   bool Publication::onLoan() const {
      bool valid = false;
      if (m_membership != 0) {
         valid = true;
      }
      return valid;
   }
   Date Publication::checkoutDate() const {
      return m_date;
   }
   bool Publication::operator==(const char* title) const {
      bool valid = false;
      char* pch = strstr(m_title, title);
      if (pch) {
         valid = true;
      }
      return valid;
   }
   Publication::operator const char*() const {
      return m_title;
   }
   int Publication::getRef() const {
      return m_libRef;
   }
//Streamable pure virtual function implementations
//-----------------------------------------------
   bool Publication::conIO(istream& is) const {
      bool valid = false;
      if (&is == &cin) {
         valid = true;
      }
      return valid;
   }
   bool Publication::conIO(ostream& os) const {
      bool valid = false;
      if (&os == &cout) {
         valid = true;
      }
      return valid;
   }

   ostream& Publication::write(ostream& os) const {
         if (conIO(os)) {
            os << "| " << m_shelfId << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH) {
                for (int i = 0; i < SDDS_TITLE_WIDTH && m_title[i] != '\0'; i++)
                    os << m_title[i];
            }
            else {
                os.width(30);
                os.fill('.');
                os.setf(ios::left);

                os << m_title;
            }
             os << " | ";
            if (m_membership == 0) {
               os << " N/A ";
            }
            else {
               os << m_membership;
            }
            os << " | ";
            m_date.write();
            os << " |";
         }
         else {
            os << type() << '\t' << m_libRef << "\t" <<
                m_shelfId << '\t' << m_title << '\t' <<
                m_membership << '\t' << m_date;
         }
      return os;
   }
   istream& Publication::read(istream& istr) {
      setEmpty();
      char title[1000]{};
      char shelfID[6]{};
      int membership{};
      int libRef{};
      Date date{};
      if (conIO(istr)) {
         cout << "Shelf No: ";
         istr.get(shelfID,6);
         if (strlen(shelfID)!= SDDS_SHELF_ID_LEN) {
            istr.setstate(ios_base::failbit);
         }
         istr.ignore(100, '\n');
         cout << "Title: ";
         istr.getline(title, 100, '\n');
       
         cout << "Date: ";
         istr >> date;
         if (date.errCode() != 0) {
            istr.setstate(ios_base::failbit);
         }
         
      }
      else {
         istr >> libRef;
         istr.get();
         istr >> shelfID;
         istr.get();
         istr.get(title, 1000, '\t');
         istr.get();
         istr >> membership;
         istr.get();
         istr >> date;
         if (date.errCode() != 0) {
            istr.setstate(ios_base::failbit);
         }
      }
      if (istr) {
         m_membership = membership;
         m_date = date;
         m_libRef = libRef;
         strcpy(m_shelfId, shelfID);
         m_title = new char[strlen(title) + 1];
         strcpy(m_title, title);
      }
      return istr;
   }
   Publication::operator bool() const {
       return m_title != nullptr && m_shelfId[0] != '\0';
   }
   Publication::~Publication() {
      delete[] m_title;
      m_title = nullptr;
   }
   Publication::Publication(const Publication& P) {
      *this = P;
   }
   Publication& Publication::operator=(const Publication& P) {
      if (this != &P) {
         m_membership = P.m_membership;
         m_libRef = P.m_libRef;
         m_date = P.m_date;
         strcpy(m_shelfId, P.m_shelfId);

         if (P.m_title) {
            delete[] m_title;
            m_title = new char[strlen(P.m_title) + 1];
            strcpy(m_title, P.m_title);
         }
      }
      return *this;
   }
}