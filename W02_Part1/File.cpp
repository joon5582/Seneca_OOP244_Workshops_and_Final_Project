/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    ==================================================
    Workshop #2 (Part-1):
    ==================================================
    Name   : Junwoo Lee
    ID     : 124395203
    Email  : jlee648@myseneca.ca
    Section: NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   
  
   bool read(char* empName) {
       return fscanf(fptr, "%[^\n]\n", empName) == 1;
   }
   bool read(int& empNum) {
      return fscanf(fptr, "%d,", &empNum) == 1;
   }
   bool read(double& empSal) {
      return fscanf(fptr, "%lf,", &empSal) == 1;
   }
   
}