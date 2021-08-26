#include "Population.h"
#include "cstring.h"
#include <iostream>
#include "File.h"

using namespace std;
namespace sdds {

    int areaCounter;
    Population* data;

    void sort() {
        Population temp;
        int i = 0;
        for (i = areaCounter - 1; i > 0; i--) {
            for (int x = 0; x < i; x++) {
                if (data[x].amount > data[x + 1].amount) {
                    temp = data[x];
                    data[x] = data[x + 1];
                    data[x + 1] = temp;
                }
            }
        }
    }

    bool load(Population& data) {
        data.postal = new char[4]{ '\0' };
        if (read(data.postal)) { if (read(data.amount)) { return true; } }
        return false;
    }

    bool load(const char filename[]) {
        int i = 0;
        bool ok = false;
        if (openFile("PCpopulationsComplete.csv")) {
            areaCounter = noOfRecords();
            data = new Population[areaCounter]{};
            i = 0;
            for (; i < areaCounter; i++) {
                if (!load(data[i])) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted\n";
                    closeFile();
                    return false;
                }
            }
            ok = true;
            closeFile();
        }
        else {
            cout << "Could not open data file: " << "PCpopulationsComplete.csv" << endl;
        }
        return ok;
    }

    void display(Population& data, int num) {
        cout << num + 1 << "- " << data.postal << ":  " << data.amount << endl;
    }

    void display() {
        int i = 0, amount = 0;
        sort();
        cout << "Postal Code: population\n-------------------------\n";
        for (; i < areaCounter; i++) {
            if (data[i].postal[0] != '\0') {
                amount += data[i].amount;
                display(data[i], i);
            }
        }
        cout << "-------------------------\nPopulation of Canada: " << amount << endl;
    }

    void deallocateMemory() {
        int i = 0;
        for (; i < areaCounter; i++) { delete[] data[i].postal; }
        delete[] data;
        data = NULL;
    }
}
