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
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}
	Line::Line(const char* cstring, int lineLen):LblShape(cstring)
	{
		m_length = lineLen;
	}
	void Line::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		while (istr.get() != '\n');
	}
	void Line::draw(ostream& ostr)const
	{
		if (m_length > 0 && label() != nullptr)
		{
			ostr << label() << endl;
			ostr.width(m_length);
			ostr.fill('=');
			ostr << '=';
		}
	}
}