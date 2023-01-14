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

#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Streamable.h"
#include "Lib.h"
#include "Date.h"

namespace sdds {
   class Publication : public Streamable {
      char* m_title{};
      char m_shelfId[SDDS_SHELF_ID_LEN+1]{};
      int m_membership{};
      int m_libRef{};
      Date m_date{};
   public:
      Publication();
      void setEmpty();
      virtual void set(int member_id);
      void setRef(int value);
      void resetDate();

      virtual char type()const;
      bool onLoan()const;
      Date checkoutDate()const;
      bool operator==(const char* title)const;
      operator const char* ()const;
      int getRef()const;

      bool conIO(std::istream& is)const;
      bool conIO(std::ostream& os)const;
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      operator bool() const;
      ~Publication();
      Publication(const Publication& P);
      Publication& operator=(const Publication& P);
   };

}

#endif
