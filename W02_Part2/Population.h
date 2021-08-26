#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char* postal;
        int amount;
    };
    void display();
    void display(Population& data, int num);
    void sort();
    bool load(Population& data);
    void deallocateMemory();
    bool load(const char filename[]);
}

#endif
