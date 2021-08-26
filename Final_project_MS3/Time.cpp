/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
		
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours;
		int mins;
		hours = m_min / 60;
		mins = m_min % 60;
		ostr.setf(ios::right);
		ostr.width(2);
		ostr.fill('0');
		ostr << hours;
		ostr << ":";
		ostr.width(2);
		ostr.fill('0');
		ostr << mins;
		return ostr;
		
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hours;
		int mins;
		char delim;
		istr >> hours;
		istr >> delim;
		istr >> mins;
		if(!istr.fail()&&(hours<0||delim!=':'||mins<0))
			istr.setstate(ios::failbit);
		else if (!istr.fail())
		{
			m_min = 0;
			m_min += hours * 60;
			m_min += mins;
		}
		return istr;		
	}
	Time& Time::operator-=(const Time& D)
	{
		int temp = m_min;
		temp -= D.m_min;
		while (temp < 0) temp += 1440;
		m_min = temp;
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		int tempmin = m_min;
		tempmin -= D.m_min;
		while (tempmin < 0) tempmin += 1440;
		Time temp = tempmin;
		return temp;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{	
		int tempmin = m_min;
		tempmin += D.m_min;
		Time temp = tempmin;
		return temp;
	}
	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}
	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const
	{
		int tempmin = m_min;
		tempmin *= val;
		Time temp = tempmin;
		return temp;
	}
	Time Time::operator/(unsigned int val) const
	{
		int tempmin = m_min;
		tempmin /= val;
		Time temp = tempmin;
		return temp;
	}
	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time::operator int() const
	{
		return m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}