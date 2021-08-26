/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    ==================================================
    Workshop #1 (Part-1):
    ==================================================
    Name   : Junwoo Lee
    ID     : 124395203
    Email  : jlee648@myseneca.ca
    Section: NAA
*/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include "ShoppingRec.h"
namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);


}



#endif // !SDDS_FILE_H_
