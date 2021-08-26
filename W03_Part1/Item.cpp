/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
	const int ItemNameSpaces = 20;
	const double taxRate = 0.13;

	void Item::setName(const char* name)
	{
		if (name == nullptr)
			strCpy(m_itemName, "");
		else
			strnCpy(m_itemName, name, ItemNameSpaces);
	}
	void Item::setEmpty()
	{
		m_price = 0.0;
		strCpy(m_itemName, "");
	}
	void Item::set(const char* name, double price, bool taxed)
	{
		setName(name);
		m_price = price;
		m_taxed = taxed;
	}
	void Item::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		if (isValid())
		{
			cout.setf(ios::left);
			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout<< m_itemName;			
			cout << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.width(7);
			cout.fill(' ');
			cout << m_price;
			cout << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
			cout.unsetf(ios::right);
			
		}
		else
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		cout.unsetf(ios::fixed);
	}
	bool Item::isValid() const
	{
		return strCmp(m_itemName, "") && m_price > 0.0;
	}
	double Item::price() const
	{
		return m_price;
	}
	double Item::tax() const
	{
		double res = 0.0;
		if (m_taxed)
			res = price() * taxRate;
		return res;
	}
}