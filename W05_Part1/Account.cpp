/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else if (~*this) {
			cout << "  NEW  |         0.00 ";
		}
		else {
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	Account::operator bool() const
	{
		return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
	}
	Account::operator int() const
	{
		return m_number;
	}
	Account::operator double() const
	{
		return m_balance;
	}
	bool Account::operator ~() const
	{
		return m_number == 0;
	}

	Account& Account::operator=(int accountNumber)
	{
		if (~*this)
		{
			if (accountNumber >= 10000 && accountNumber <= 99999)
				m_number = accountNumber;
			else
			{
				m_number = -1;
				m_balance = 0;
			}

		}
		return *this;
	}

	Account& Account::operator=(Account& otherAccount)
	{
		if (~*this)
		{
			if (otherAccount)
			{
				m_number = otherAccount.m_number;
				m_balance = otherAccount.m_balance;
				otherAccount.m_number = 0;
				otherAccount.m_balance = 0;
			}
		}
		return *this;
	}

	Account& Account::operator+=(double amount)
	{
		if (*this && amount > 0)
		{
			m_balance += amount;
		}
		return *this;
	}

	Account& Account::operator-=(double amount)
	{
		if (*this && amount > 0 && m_balance - amount >= 0)
		{
			m_balance -= amount;
		}
		return *this;
	}

	Account& Account::operator<<(Account& otherAccount)
	{
		if (*this && otherAccount && otherAccount.m_number != m_number)
		{
			m_balance += otherAccount.m_balance;
			otherAccount.m_balance = 0.0;
		}
		return *this;
	}

	Account& Account::operator>>(Account& otherAccount)
	{
		if (*this && otherAccount && otherAccount.m_number != m_number)
		{
			otherAccount.m_balance += m_balance;
			m_balance = 0;
		}
		return *this;
	}



	double operator+(const Account& account1, const Account& account2)
	{
		double result;
		if (account1 && account2)
		{
			result = account1.operator double() + account2.operator double();
		}
		else
			result = 0;
		return result;
	}

	double operator+=(double& amount, const Account& account)
	{
		if (account)
		{
			amount += account.operator double();
		}
		return amount;
	}

}