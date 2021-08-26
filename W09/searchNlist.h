/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	==================================================
	Workshop #9 (Part-1):
	==================================================
	Name   : Junwoo Lee
	ID     : 124395203
	Email  : jlee648@myseneca.ca
	Section: NAA
*/
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
namespace sdds {

	template <typename T1, typename T2>
	bool search(Collection<T1>& object, T1 arr[], int numOfElements, T2 key)
	{
		bool isFound = false;
		for (int i = 0; i < numOfElements; i++)
		{
			if (arr[i] == key)
			{
				isFound = true;
				object.add(arr[i]);
			}
		}
		return isFound;
	}

	template <typename T>
	void listArrayElements(const char* title, const T arr[], int numOfElements)
	{
		if (title) std::cout << title << std::endl;
		for (int i = 0; i < numOfElements; i++)
		{
			std::cout << i + 1 << ": " << arr[i] << std::endl;
		}

	}



}




#endif