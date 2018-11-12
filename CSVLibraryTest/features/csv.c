#include <stdio.h>
#include <stdlib.h>

#include "features.h"

void initCSVFile(CSVFile * csv, FILE ** file, char * path)
{
    *file = fopen(path, "r+");

    csv->file = file;
}

void freeCSVFile(CSVFile * csv)
{
    fclose(*(csv->file));

    freeCSVHeader(&(csv->columns));

    for(int i = 0; i < csv->size; i++)
    {
        free(csv->lines[i].values);
    }
}

void initCSVHeader(CSVHeader * header, int size, char ** columnsNames)
{
    header->size = size;
    header->columnsNames = columnsNames;
}

void freeCSVHeader(CSVHeader * header)
{
    free(header->columnsNames);
}

void addCSVLine(CSVFile * csv, void ** values)
{
    CSVLine line = {0};

    line.size = csv->columns.size;
    line.values = values;

    csv->size++;
    csv->lines = realloc(csv->lines, csv->size * sizeof(CSVLine));
    csv->lines[csv->size - 1] = line;
}
