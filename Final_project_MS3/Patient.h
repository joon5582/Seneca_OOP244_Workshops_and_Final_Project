/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
namespace sdds {
	class Patient : public IOAble {
		char* m_patName;
		int m_ohipNum;
		Ticket m_ticket;
		bool m_ioflag;
	public:
		Patient(int ticketNum = 0, bool IOflag = false);
		Patient(const Patient& I) = delete;
		~Patient();
		Patient& operator=(const Patient& Ro) = delete;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		virtual char type() const = 0;
		bool fileIO()const;
		void fileIO(bool flag);
		bool operator ==(char ch) const;
		bool operator ==(const Patient& Op) const;
		void setArrivalTime();
		operator Time() const;
		int number()const;
	};

}


#endif