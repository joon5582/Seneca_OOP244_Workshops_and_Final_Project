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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* employeeName);
   bool read(int& employeeNumber);
   bool read(double& employeeSalary);

}
#endif // !SDDS_FILE_H_
