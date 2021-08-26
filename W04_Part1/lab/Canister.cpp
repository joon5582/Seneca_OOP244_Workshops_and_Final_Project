/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
	const double PI = 3.14159265;
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13;
		m_diameter = 10;
		m_contentVolume = 0.0;
		m_usable = true;

	}
	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr && m_usable)
		{
			delete[] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}


	}
	bool Canister::isEmpty() const
	{
		return m_contentVolume < 0.00001;
	}
	bool Canister::hasSameContent(const Canister& C) const
	{
		return false;
	}
	Canister::Canister()
	{
		setToDefault();
	}
	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}
	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();

		if (height < 10.0 || height > 40.0 || diameter < 10.0 || diameter >30 )
			m_usable = false;
		else
		{
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}

	}
	Canister::~Canister()
	{
		delete[] m_contentName;
	}
	Canister& Canister::setContent(const char* contentName)
	{
		if (contentName == nullptr)
			m_usable = false;
		else if (isEmpty())
			setName(contentName);
		else if (strCmp(m_contentName, contentName))
			m_usable = false;
		return *this;
	}
	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0 && m_contentVolume + quantity < capacity())
			m_contentVolume += quantity;
		else
			m_usable = false;
		return *this;
	}
	Canister& Canister::pour(Canister& from)
	{
		setContent(from.m_contentName);
		if (from.m_contentVolume > capacity() - m_contentVolume)
		{
			from.m_contentVolume -= capacity() - m_contentVolume;
			m_contentVolume = capacity();
		}
		else
		{
			pour(from.m_contentVolume);
			from.m_contentVolume = 0.0;
		}
		return *this;
	}
	double Canister::volume() const
	{
		return m_contentVolume;
	}
	std::ostream& Canister::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity();
		cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable)
			cout << " of Unusable content, discard!";
		else if (m_contentName != nullptr)
		{
			cout << " of ";
			cout.width(7);
			cout << m_contentVolume;
			cout << "cc   " << m_contentName;
		}
		return cout;
	}
	double Canister::capacity() const
	{
		return PI * (m_height - 0.267) * m_diameter / 2 * m_diameter / 2;
	}
	void Canister::clear()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}