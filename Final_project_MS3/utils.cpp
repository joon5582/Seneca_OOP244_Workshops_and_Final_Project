/* Citation and Sources...
Final Project Milestone 3
Module: utils
Filename: utils.cpp
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
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {

	bool debug = false;  // made global in utils.h
	int getTime() {
		int mins = -1;
		if (debug) {
			Time t(0);
			cout << "Enter current time: ";
			do {
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin) {
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else {
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else {
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}

	int getInt(const char* prompt)
	{
		int val;
		int flag = 0;
		if (prompt)
			cout << prompt;
		do {
			cin >> val;
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				while (cin.get() != '\n');
			}
			else if (cin.get() != '\n')
			{
				cout << "Enter only an integer, try again: ";
				while (cin.get() != '\n');
			}
			else flag = 1;

		} while (flag == 0);
		return val;
	}

	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int val = getInt(prompt);
		while (val<min || val>max) {
			if (errorMessage || showRangeAtError)
			{
				if (errorMessage)
				{
					cout << errorMessage;
				}
				if (showRangeAtError)
				{
					cout << "[" << min << " <= value <= " << max << "]: ";
				}

				val = getInt();
			}
			else
				val = getInt(prompt);

		}
		return val;
	}

	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		int len = 0;
		int memorySize = 16;
		char* str = new char[memorySize];
		char* tempPtr = nullptr;
		char ch;

		if (prompt)
			cout << prompt;
		while ((ch = istr.get()) != delimiter && !istr.eof())
		{
			if (len >= memorySize - 1)
			{
				memorySize *= 2;
				tempPtr = str;
				str = new char[memorySize];
				for (int i = 0; i < len; i++)
					str[i] = tempPtr[i];
				delete[] tempPtr;
				tempPtr = nullptr;
			}
			str[len++] = ch;
		}
		str[len] = '\0';
		tempPtr = new char[strLen(str) + 1];
		strCpy(tempPtr, str);
		delete[] str;

		return tempPtr;
	}

	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		while ((*(des++) = *(src++)));
	}
	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i, flag = 0;
		for (i = 0; i < len && flag == 0; i++)
		{
			des[i] = src[i];
			if (des[i] == '\0')
				flag = 1;
		}
		if (flag == 0)
			des[i] = '\0';
	}
	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			s1++;
			s2++;
		}
		return *s1 - *s2;
	}
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int count = 0;
		while (count < len && *s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		{
			count++;
			if (count < len)
			{
				s1++;
				s2++;
			}
		}
		return *s1 - *s2;
	}
	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);
		return i;
	}
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int len = strLen(str2);
		int i, flag = 0;
		char* toReturn = nullptr;


		for (i = 0; str1[i] != '\0' && flag == 0; i++)
		{
			if (strnCmp(&str1[i], str2, len) == 0)
			{
				toReturn = (char*)&str1[i];
				flag = 1;
			}
		}
		return toReturn;
	}
	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		while (*(des))
		{
			des++;
		}
		while ((*(des++) = *(src++)));
	}
}