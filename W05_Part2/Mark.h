/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#ifndef SDDS_MARK_H_

using namespace std;
namespace sdds {
	class Mark {
		int m_grade;
		void setEmpty();
	public:
		Mark();
		Mark(int grade);
		operator bool() const;
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator +=(int addedGrade);
		Mark& operator =(int setGrade);
	};

	int& operator +=(int& val, Mark& mark);

}


#define SDDS_MARK_H_
#endif // !SDDS_MARK_H_

