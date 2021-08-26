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
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calorie;
        int m_mealcode;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int claorie, int mealcode);
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}

#endif // !SDDS_SUBJECT_H
