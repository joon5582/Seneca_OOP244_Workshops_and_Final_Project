/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"
namespace sdds {
	class LabelMaker {
		int m_noOfLabels;
		Label* m_labels;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}




#endif // !SDDS_LABELMAKER_H
