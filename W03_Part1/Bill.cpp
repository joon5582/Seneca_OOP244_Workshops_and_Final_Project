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
#include "Bill.h"
using namespace std;
namespace sdds {
	const int billTitleSpaces = 36;
	double Bill::totalTax() const
	{
		int i;
		double totalTax = 0.0;
		for (i = 0; i < m_noOfItems; i++)
		{
			if (m_items[i].isValid())
				totalTax += m_items[i].tax();
		}
		return totalTax;
	}
	double Bill::totalPrice() const
	{
		int i;
		double totalPrice = 0.0;
		for (i = 0; i < m_noOfItems; i++)
		{
			if (m_items[i].isValid())
				totalPrice += m_items[i].price();
		}
		return totalPrice;
	}
	void Bill::Title() const
	{
		cout << "+--------------------------------------+" << endl;
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout<< m_title << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}
	void Bill::footer() const
	{
		
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())
		{
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::right);
			cout << "|                Total Tax: ";
			cout.width(10);
			cout<< totalTax() << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout<< totalPrice() << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout<< totalTax() + totalPrice() << " |" << endl;		
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
		}
		else
			cout << "| Invalid Bill                         |" << endl;

		cout << "+--------------------------------------+" << endl;
		
	}
	void Bill::setEmpty()
	{
		strCpy(m_title, "");
		m_items = nullptr;
	}
	bool Bill::isValid() const
	{
		int i, flag=0;
		bool res = true;
		if (!strCmp(m_title, "") || (m_items == nullptr))
			res = false;
		else
		{
			for (i = 0; i < m_noOfItems && flag ==0; i++)
			{
				if (!m_items[i].isValid())
				{
					res = false;
					flag = 1;
				}
			}
		}
		return res;
	}
	void Bill::init(const char* title, int noOfItems)
	{
		if (title == nullptr || noOfItems <= 0)
			setEmpty();
		else
		{
			int i;
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, billTitleSpaces);
			m_items = new Item[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}
	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool res = false;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			res = true;
		}
		return res;
	}
	void Bill::display() const
	{
		int i;
		Title();
		for (i = 0; i < m_noOfItems; i++)
		{
			m_items[i].display();
		}
		footer();
	}
	void Bill::deallocate()
	{
		delete[] m_items;
	}
}