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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {

	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* cstring, int width, int height):LblShape(cstring)
	{
		m_width = 0;
		m_height = 0;
		if (cstring && height >= 3 &&  width >= (int)(strlen(label()) + 2))
		{
			m_width = width;
			m_height = height;
		}
		
	}


	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		while (istr.get() != '\n');
	}

	void Rectangle::draw(std::ostream& ostr)const
	{
		if (m_width > 0 && m_height > 0)
		{
			cout << '+';
			cout.width(m_width - 2);
			cout.fill('-');
			cout << '-' << '+' << endl;
			cout << '|';
			cout.setf(ios::left);
			cout.width(m_width - 2);
			cout.fill(' ');
			cout << label() << '|' << endl;
			cout.unsetf(ios::left);
			for(int i=0;i<m_height-3;i++)
			{
				cout << '|';
				cout.width(m_width - 2);
				cout.fill(' ');
				cout << ' ' << '|' << endl;
			}
			cout << '+';
			cout.width(m_width - 2);
			cout.fill('-');
			cout << '-' << '+';
		}
	}

}