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
#include "CalorieList.h"
using namespace std;
namespace sdds {
	const int CaltitleSpaces = 50;

	int CalorieList::totalCal() const
	{
		int i;
		int totalCal = 0;
		for (i = 0; i < m_noOfFoods; i++)
		{
			if (m_foods[i].isValid())
				totalCal += m_foods[i].calorie();
		}
		return totalCal;

	}
	void CalorieList::Title() const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (isValid())
		{
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	void CalorieList::footer() const
	{


		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())
		{
			cout.setf(ios::right);
			cout << "|    Total Calories for today:   ";
			cout.width(6);
			cout << totalCal();
			cout << " |            |" << endl;
			cout.unsetf(ios::right);
		}

		else
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		cout << "+----------------------------------------------------+" << endl;

	}
	void CalorieList::setEmpty()
	{
		m_foods = nullptr;
	}
	bool CalorieList::isValid() const
	{
		int i;
		bool res = true;
		if (m_foods == nullptr)
			res = false;
		else
		{
			for (i = 0; i < m_noOfFoods; i++)
			{
				if (!m_foods[i].isValid())
					res = false;
			}
		}
		return res;

	}
	void CalorieList::init(int noOfFoods)
	{
		if (noOfFoods <= 0)
			setEmpty();
		else
		{
			int i;
			m_noOfFoods = noOfFoods;
			m_foodsAdded = 0;

			m_foods = new Food[m_noOfFoods];
			for (i = 0; i < m_noOfFoods; i++)
			{
				m_foods[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* food_name, int calorie, int mealcode)
	{
		bool res = false;
		if (m_foodsAdded < m_noOfFoods)
		{
			m_foods[m_foodsAdded].set(food_name, calorie, mealcode);
			m_foodsAdded++;
			res = true;
		}
		return res;
	}

	void CalorieList::display() const
	{
		int i;
		Title();
		for (i = 0; i < m_noOfFoods; i++)
		{
			m_foods[i].display();
		}
		footer();
	}
	void CalorieList::deallocate()
	{
		delete[] m_foods;
	}
}