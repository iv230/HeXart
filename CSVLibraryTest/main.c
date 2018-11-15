#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "features/features.h"

int main() {

    CSVFile csv = {0};
    FILE * file = NULL;

    initCSVFile(&csv, &file, "test.csv");

    char * columns[255] = {"Nombres", "Strings", "Shorts"};
    char * formats[3] = {"%d", "%s", "%u"};;

    initCSVHeader(&(csv.columns), 3, columns, formats);

    void * values[5][3];

    int numbers[5] = {1, 2, 5, 6, 8};
    char * strings[5] = {"test1", "test2", "test4", "test8", "test15"};
    short shorts[5] = {1, 5, 8, 2, 4};

    for(int i = 0; i < 5; i++)
    {
        values[i][0] = (void *) &(numbers[i]);
        values[i][1] = (void *) strings[i];
        values[i][2] = (void *) &(shorts[i]);

        addCSVLine(&csv, values[i]);
    }

    writeCSVFile(&csv);

    freeCSVFile(&csv);

    return 0;
}