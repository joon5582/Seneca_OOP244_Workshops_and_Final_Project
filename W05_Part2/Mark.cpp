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
#include "Mark.h"

namespace sdds {
	void Mark::setEmpty()
	{
		m_grade = -1;
	}
	Mark::Mark()
	{
		m_grade=0;
	}
	Mark::Mark(int grade)
	{
		setEmpty();
		if (grade >= 0 && grade <= 100)
			m_grade = grade;
	}

	Mark::operator bool() const
	{
		return m_grade >= 0 && m_grade <= 100;
	}

	Mark::operator int() const
	{
		int res = 0;
		if (*this) res = m_grade;
		return res;
	}
	Mark::operator double() const
	{
		double res = 0.0;
		if (*this)
		{
			if (m_grade < 50)
				res = 0.0;
			else if (m_grade < 60)
				res = 1.0;
			else if (m_grade < 70)
				res = 2.0;
			else if (m_grade < 80)
				res = 3.0;
			else
				res = 4.0;
		}
		return res;
	}
	Mark::operator char() const
	{
		char res = 'X';
		if (*this)
		{
			if (m_grade < 50)
				res = 'F';
			else if (m_grade < 60)
				res = 'D';
			else if (m_grade < 70)
				res = 'C';
			else if (m_grade < 80)
				res = 'B';
			else
				res = 'A';
		}
		return res;
		
	}
	Mark& Mark::operator+=(int addedGrade)
	{
		if (addedGrade>=0 && *this)
			m_grade += addedGrade;
		return *this;
	}
	Mark& Mark::operator=(int setGrade)
	{
		m_grade = setGrade;
		return *this;
	}
	int& operator+=(int& val, Mark& mark)
	{
		if (mark) val += mark.operator int();
		return val;
	}
}