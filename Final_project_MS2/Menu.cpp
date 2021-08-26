/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Junwoo Lee
Revision History
-----------------------------------------------------------
Date      Reason
2021/7/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <iostream>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds {
	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
	void Menu::setDefault()
	{
		m_text = nullptr;
		m_noOfSel = -1;
	}
	Menu::Menu()
	{
		setDefault();
	}
	Menu::Menu(const Menu& I) :m_text(nullptr), m_noOfSel(-1)
	{
		if (I.m_text)
		{
			m_text = new char[strLen(I.m_text) + 1];
			strCpy(m_text, I.m_text);
		}
		m_noOfSel = I.m_noOfSel;

	}
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		setDefault();
		if (MenuContent) {
			m_text = new char[strLen(MenuContent) + 1];
			strCpy(m_text, MenuContent);
		}
		if (NoOfSelections >= 0)
			m_noOfSel = NoOfSelections;
	}
	Menu::~Menu()
	{
		delete[] m_text;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
		return Selection;
	}

	//Menu& Menu::operator=(const Menu& Ro)
	/*{
		if (this != &Ro) {
			delete[] m_text;
			if (Ro.m_text)
			{
				m_text = new char[strLen(Ro.m_text) + 1];
				strCpy(m_text, Ro.m_text);
			}
			else m_text = nullptr;
			m_noOfSel = Ro.m_noOfSel;
		}
		return *this;
	}*/

}