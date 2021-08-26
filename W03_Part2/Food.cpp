/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
	const int FoodNameSpaces = 30;
	
	
	void Food::setName(const char* name)
	{
		if (name == nullptr)
			strCpy(m_foodName, "");
		else
			strnCpy(m_foodName, name, FoodNameSpaces);
	}
	void Food::setEmpty()
	{
		strCpy(m_foodName, "");
		m_calorie = 0;
		m_mealcode = 0;
	}
	void Food::set(const char* name, int calorie, int mealcode)
	{
		setName(name);
		m_calorie = calorie;
		m_mealcode = mealcode;
	}
	void Food::display() const
	{
		if(isValid())
		{
			cout.setf(ios::left);
			
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout<< m_foodName;	
			cout.unsetf(ios::left);
			cout << " | ";
			cout.setf(ios::right);
			cout.width(4);
			cout.fill(' ');
			cout << m_calorie;
			cout<< " | ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(10);
			if (m_mealcode == 1)
			{
				cout <<"Breakfast";
			}
			if (m_mealcode == 2)
			{
				cout <<"Lunch";
			}
			if (m_mealcode == 3)
			{
				cout << "Dinner";
			}
			if (m_mealcode == 4)
			{
				cout <<"Snack";
			}
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
			else
			{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
			}
	}
	bool Food::isValid() const
	{
		return strCmp(m_foodName, "") && m_calorie > 0 && m_calorie<=3000 && m_mealcode>0 && m_mealcode<5;
	}

	int Food::calorie() const
	{
		return m_calorie;
	}
	
	

		
	
}