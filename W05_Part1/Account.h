/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    ==================================================
    Workshop #5 (Part-1):
    ==================================================
    Name   : Junwoo Lee
    ID     : 124395203
    Email  : jlee648@myseneca.ca
    Section: NAA
*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double()const;
      bool operator ~() const;
      Account& operator =(int accountNumber);
      Account& operator =(Account& otherAccount);
      Account& operator +=(double amount);
      Account& operator -=(double amount);
      Account& operator << (Account& otherAccount);
      Account& operator >> (Account& otherAccount);

   };
   double operator +(const Account& account1, const Account& account2);
   double operator+=(double& amount, const Account& account);
   
}
#endif // SDDS_ACCOUNT_H_