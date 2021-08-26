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
#include <iostream>
#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabels = noOfLabels;
		m_labels = new Label[m_noOfLabels];
	}
	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (int i = 0; i < m_noOfLabels; i++)
		{
			cout << "Enter label number " << i + 1 << endl;
			m_labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < m_noOfLabels; i++)
		{
			m_labels[i].printLabel()<<endl;
		}
	}

	LabelMaker::~LabelMaker()
	{
		delete[] m_labels;
	}

}