/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #8 (Part-1):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#include "Shape.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}
