/* Citation and Sources...
Final Project Milestone 3
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Junwoo Lee
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/14  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "IOAble.h"
using namespace std;
namespace sdds {
	ostream& IOAble::csvWrite(ostream& ostr) const
	{
		return ostr;
	}
	istream& IOAble::csvRead(istream& istr)
	{
		return istr;
	}
	ostream& IOAble::write(ostream& ostr) const
	{
		return ostr;
	}
	istream& IOAble::read(istream& istr)
	{
		return istr;
	}
	IOAble::~IOAble()
	{
	}
	ostream& operator<<(ostream& ostr, const IOAble& ioable)
	{
		ioable.write(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, IOAble& ioable)
	{
		ioable.read(istr);
		return istr;
	}
}