/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {
	
	class CovidPatient: public Patient {

	public:
		CovidPatient();
		char type() const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};




}
#endif // !SDDS_COVIDPATIENT_H_



