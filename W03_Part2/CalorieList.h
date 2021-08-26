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
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* m_foods;
        int m_noOfFoods;
        int m_foodsAdded;
        int totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfFoods);
        bool add(const char* food_name, int calorie, int mealcode);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
