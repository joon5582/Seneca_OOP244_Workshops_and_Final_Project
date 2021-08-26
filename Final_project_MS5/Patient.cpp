/* Citation and Sources...
Final Project Milestone 5
Module: Patient
Filename: Patient.cpp
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
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticketNum, bool IOflag) :m_patName(nullptr), m_ticket(ticketNum)
	{
		m_ohipNum = -1;
		m_ioflag = IOflag;
	}
	
	Patient::~Patient()
	{
		delete[] m_patName;
	}
	
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << ',' << m_patName << ',' << m_ohipNum << ',';
		m_ticket.csvWrite(ostr);

		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{
		delete[] m_patName;
		m_patName = getcstr(nullptr, istr, ',');
		istr >> m_ohipNum;
		istr.get();
		m_ticket.csvRead(istr);
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr) const
	{
		m_ticket.write(ostr) << endl;
		char temp[26];
		strnCpy(temp, m_patName, 25);
		ostr << temp << ", OHIP: " << m_ohipNum;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr)
	{
		m_patName = getcstr("Name: ", istr, '\n');
		m_ohipNum = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
		return istr;
	}
	
	bool Patient::fileIO() const
	{
		return m_ioflag;
	}
	void Patient::fileIO(bool flag)
	{
		m_ioflag = flag;
	}

	bool Patient::operator==(char ch) const
	{
		return ch == type();
	}

	bool Patient::operator==(const Patient& Op) const
	{

		return type() == Op.type();
	}

	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}

	Patient::operator Time() const
	{
		return (Time)m_ticket;
	}

	int Patient::number() const
	{
		return m_ticket.number();
	}

}