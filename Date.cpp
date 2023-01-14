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

// Final Project Milestone 1
// Date Module
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"

namespace sdds {
   bool sdds_test = false;
   int sdds_year = 2022;
   int sdds_mon = 8;
   int sdds_day = 7;

   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      int theYear = sdds_year;
      if (!sdds_test) {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         theYear = lt.tm_year + 1900;
      }
      return theYear;
   }
   void Date::setToToday() {
      if (sdds_test) {
         m_day = sdds_day;
         m_mon = sdds_mon;
         m_year = sdds_year;
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         m_day = lt.tm_mday;
         m_mon = lt.tm_mon + 1;
         m_year = lt.tm_year + 1900;
      }
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }

//operators
   bool Date::operator==(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() == D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   bool Date::operator!=(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() != D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   bool Date::operator>=(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() >= D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   bool Date::operator<=(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() <= D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   bool Date::operator<(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() < D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   bool Date::operator>(const Date& D) const {
      bool valid = false;
      if (daysSince0001_1_1() > D.daysSince0001_1_1()) {
         valid = true;
      }
      return valid;
   }
   int Date::operator-(const Date& D) const {
      return daysSince0001_1_1() - D.daysSince0001_1_1();
   }
   bool Date::operator!() const {
      return m_ErrorCode!=0;
   }

   Date::operator bool() {
       bool valid = true;
       if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
           valid = false;
       }
       else if (m_mon < 1 || m_mon > 12) {
           valid = false;
       }
       else if (m_day < 1 || m_day > mdays()) {
           valid = false;
       }
       return valid;
   }

   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

//read and print
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

   std::istream& Date::read(std::istream& is) {
      errCode(NO_ERROR);
      if (is >> m_year) {
         is.get();
         if (is >> m_mon) {
            is.get();
            if (is >> m_day) {
               validate();
               is.clear();
            }
            else {
               errCode(CIN_FAILED);
               is.clear();
            }
         }
         else {
            errCode(CIN_FAILED);
            is.clear();
         }
      }
      else {
         errCode(CIN_FAILED);
         is.clear();
      }
      return is;
   }
   std::ostream& Date::write(std::ostream& os) const {
      if (m_ErrorCode != 0) {
         os << dateStatus();
      }
      else {
         os << m_year << "/";
         os.width(2);
         os.fill('0');
         os.setf(ios::right);
         os << m_mon << "/";
         os.width(2);
         os.fill('0');
         os << m_day;
         os.unsetf(ios::right);
      }
      return os;
   }
}
