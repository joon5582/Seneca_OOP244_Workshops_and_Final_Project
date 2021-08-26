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
#include "Label.h"
#include "cstring.h"
#define MAX_CHARS 70
using namespace std;
namespace sdds {
	
	void Label::setToDefault()
	{
		m_frame[0] = '\0';
		strCpy(m_frame, "+-+|+-+|");
		m_content = nullptr;
	}
	void Label::setFrame(const char* frameArg)
	{
		if (frameArg != nullptr)
			strnCpy(m_frame, frameArg, sizeof(m_frame) - 1);
	}
	Label::Label() {
		setToDefault();
	}
	Label::Label(const char* frameArg) {
		setToDefault();
		setFrame(frameArg);
	}
	Label::Label(const char* frameArg, const char* content) {
		setToDefault();
		setFrame(frameArg);
		if (content != nullptr)
		{
			if (strLen(content) > MAX_CHARS)
			{
				m_content = new char[MAX_CHARS + 1];
				strnCpy(m_content, content, 70);
			}
			else
			{
				m_content = new char[strLen(content) + 1];
				strCpy(m_content, content);
			}
		}

	}
	Label::~Label()
	{
		delete[] m_content;
	}

	void Label::readLabel()
	{
		char tempStr[MAX_CHARS+1];
		cout << "> ";
		cin.get(tempStr, 71);
		if (cin.fail())
			cin.clear();
		while (cin.get() != '\n');
		m_content = new char[strLen(tempStr) + 1];
		strCpy(m_content, tempStr);
	}
	std::ostream& Label::printLabel() const
	{
		if (m_content != nullptr)
		{
			//line1
			cout << m_frame[0];
			cout.width(strLen(m_content) + 2);
			cout.fill(m_frame[1]);
			cout << m_frame[1];
			cout << m_frame[2] << endl;
			//line2
			cout << m_frame[7];
			cout.width(strLen(m_content) + 2);
			cout.fill(' ');
			cout << ' ';
			cout << m_frame[3] << endl;
			//line3
			cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;
			//line4
			cout << m_frame[7];
			cout.width(strLen(m_content) + 2);
			cout.fill(' ');
			cout << ' ';
			cout << m_frame[3] << endl;
			//line5
			cout << m_frame[6];
			cout.width(strLen(m_content) + 2);
			cout.fill(m_frame[5]);
			cout << m_frame[5];
			cout << m_frame[4];
		}
		return cout;
	}
}