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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* cstring, int lineLen);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;


	};

}



#endif 