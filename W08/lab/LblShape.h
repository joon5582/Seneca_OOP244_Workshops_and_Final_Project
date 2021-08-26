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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds {
	class LblShape :public Shape {
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape(const char* cstring = nullptr);
		~LblShape();
		LblShape(LblShape& I) = delete;
		LblShape& operator=(LblShape& other) = delete;
		void getSpecs(std::istream& istr);
	};
}



#endif // !SDDS_LBLSHAPE_H_
