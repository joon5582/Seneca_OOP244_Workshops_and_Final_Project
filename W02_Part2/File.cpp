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

    bool read(char* postal) {
        if (fscanf(fptr, "%[^,],", postal) != 0) {
            return 1;
        }
        return 0;
    }

    bool read(int& amount) {
        if (fscanf(fptr, "%d\n", &amount) != 0) {
            return 1;
        }
        return 0;
    }
}

