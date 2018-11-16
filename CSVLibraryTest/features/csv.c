#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    free(csv->lines);
}

void initCSVHeader(CSVHeader * header, int size, char ** columnsNames, char ** formats)
{
    header->size = size;
    header->columnsNames = columnsNames;
    header->formats = formats;
}

void freeCSVHeader(CSVHeader * header)
{
    free(header->columnsNames);
}

void addCSVLine(CSVFile * csv, void ** values)
{
    csv->size++;
    csv->lines = realloc(csv->lines, csv->size * sizeof(CSVLine));
    csv->lines[csv->size - 1] = values;
}
