#ifndef CSVLIBRARYTEST_FEATURES_H
#define CSVLIBRARYTEST_FEATURES_H

typedef struct
{
    int size;
    char ** columnsNames;

} CSVHeader;

typedef struct
{
    int size;
    void ** values;

} CSVLine;

typedef struct
{
    CSVHeader columns;
    CSVLine * lines;
    int size;
    FILE ** file;

} CSVFile;

void initCSVFile(CSVFile * csv, FILE ** file, char * path);

void freeCSVFile(CSVFile * csv);

void initCSVHeader(CSVHeader * header, int size, char ** columnsNames);

void freeCSVHeader(CSVHeader * header);

void addCSVLine(CSVFile * csv, void ** values);


void writeCSVFile(CSVFile * csv);







#endif //CSVLIBRARYTEST_FEATURES_H
