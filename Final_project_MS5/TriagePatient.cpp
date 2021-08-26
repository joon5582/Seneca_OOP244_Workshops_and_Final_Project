/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include <iostream>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	int nextTriageTicket = 1;

   TriagePatient::TriagePatient():Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
   }

   char TriagePatient::type() const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr)
   {
	   Patient::csvWrite(ostr) << ',';
	   ostr << m_symptoms;
	   return ostr;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.get();
	   m_symptoms = getcstr(nullptr, istr, '\n');
	   nextTriageTicket = number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
	   if (fileIO())
	   {
		   Patient::csvWrite(ostr);
		   ostr << ',' << m_symptoms;
	   }
	   else
	   {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr) << endl;
		   ostr << "Symptoms: " << m_symptoms<<endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr)
   {
	   if (fileIO())
		   csvRead(istr);
	   else
	   {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   m_symptoms = getcstr("Symptoms: ", istr, '\n');
	   }
	   return istr;
   }

}