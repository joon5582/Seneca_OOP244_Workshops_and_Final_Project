/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
using namespace std;
namespace sdds {
	void PreTriage::reg()
	{

		if (m_lineupSize == maxNoOfPatients)
		{
			cout << "Line up full!" << endl;

		}
		else
		{
			bool isTerm = false;
			int selection;
			m_pMenu >> selection;
			if (selection == 1)
				m_lineup[m_lineupSize] = new CovidPatient();
			if (selection == 2)
				m_lineup[m_lineupSize] = new TriagePatient();
			if (selection == 0)
				isTerm = true;
			if (!isTerm)
			{
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->read(cin);
				cout << endl;
				cout << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize] << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}

	void PreTriage::admit()
	{
		bool isTerm = false;
		int selection;
		int index = -1;
		char type;
		m_pMenu >> selection;
		if (selection == 1)
			type = 'C';
		if (selection == 2)
			type = 'T';
		if (selection == 0)
			isTerm = true;
		if (!isTerm)
		{
			index = indexOfFirstInLine(type);
			if (index == -1)
				isTerm = true;
			if (!isTerm)
			{
				cout << endl;
				cout << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for " << *m_lineup[index];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int count = 0;
		Time res;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type())
				count++;
		}
		res = p.type() == 'C' ? count * (int)m_averCovidWait : count * (int)m_averTriageWait;
		return res;
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		if (p.type() == 'C')
		{
			m_averCovidWait = ((getTime() - (int)Time(p)) + ((int)m_averCovidWait * (p.number() - 1))) / p.number();
		}
		if (p.type() == 'T')
		{
			m_averTriageWait = ((getTime() - (int)Time(p)) + ((int)m_averTriageWait * (p.number() - 1))) / p.number();
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		bool isFound = false;
		int result = -1;
		if (type == 'C' || type== 'T')
		{
			for (int i = 0; i < m_lineupSize && !isFound; i++)
			{
				if (m_lineup[i]->type() == type)
				{
					isFound = true;
					result = i;
				}
			}
		}
		return result;
	}

	void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		ifstream ifst(m_dataFilename);
		m_averCovidWait.read(ifst);
		ifst.ignore();
		m_averTriageWait.read(ifst);
		ifst.ignore();
		Patient* patPtr = nullptr;
		char ch;
		int flag = 0;
		for (int i = 0; i < maxNoOfPatients; i++) {
			ch = ifst.get();
			if (ch == 'C')
			{
				patPtr = new CovidPatient();

			}
			else if (ch == 'T')
			{
				patPtr = new TriagePatient();

			}
			else flag = 1;
			if (flag == 0)
			{
				ifst.ignore();
				patPtr->fileIO(true);
				patPtr->read(ifst);
				patPtr->fileIO(false);
				m_lineup[m_lineupSize] = patPtr;
				m_lineupSize++;
			}
		}
		if (!ifst.eof())
			cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
		if (m_lineupSize == 0)
			cout << "No data or bad data file!";
		else
			cout << m_lineupSize << " Records imported...";
		cout << endl << endl;
	}

	PreTriage::PreTriage(const char* dataFilename) :
		m_averCovidWait(15),
		m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{

		if (dataFilename)
		{
			m_dataFilename = new char[strLen(dataFilename) + 1];
			strCpy(m_dataFilename, dataFilename);
		}
		load();
	}

	PreTriage::~PreTriage()
	{
		fstream data;
		data.open(m_dataFilename, ios::out);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		data << m_averCovidWait << ',' << m_averTriageWait << endl;

		cout << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			m_lineup[i]->fileIO(true);
			data << *m_lineup[i] << endl;
			cout << i + 1 << "- " << *m_lineup[i] << endl;
		}
		for (int i = 0; i < m_lineupSize; i++)
			delete m_lineup[i];
		delete[] m_dataFilename;
		cout << "done!"<<endl;
	}

	void PreTriage::run(void)
	{

		int selection = 0;
		do
		{
			m_appMenu >> selection;
			if (selection == 1)
				reg();
			if (selection == 2)
				admit();
		} while (selection != 0);
	}

}
