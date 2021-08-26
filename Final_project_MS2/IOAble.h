/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Junwoo Lee
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>
using namespace std;
namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& ostr)const=0;
		virtual istream& csvRead(istream& istr)=0;
		virtual ostream& write(ostream& ostr) const=0;
		virtual istream& read(istream& istr)=0;
		virtual ~IOAble(){};
	};
	ostream& operator<<(ostream& ostr, const IOAble& ioable);
	istream& operator>>(istream& istr, IOAble& ioable);
}

#endif