/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
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
#include "IOAble.h"


namespace sdds {
	ostream& operator<<(ostream& ostr, const IOAble& ioable)
	{
		return ioable.write(ostr);
	}
	istream& operator>>(istream& istr, IOAble& ioable)
	{
		return ioable.read(istr);
	}
}