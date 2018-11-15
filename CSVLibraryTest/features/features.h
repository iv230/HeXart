#ifndef CSVLIBRARYTEST_FEATURES_H
#define CSVLIBRARYTEST_FEATURES_H

typedef struct
{
    int size;
    char ** columnsNames;
    char ** formats;

} CSVHeader;

typedef void ** CSVLine;

typedef struct
{
    CSVHeader columns;
    CSVLine * lines;
    int size;
    FILE ** file;

} CSVFile;

/**
 * Init a CSVFile object.
 * @param csv The CSVFile to init
 * @param file An empty file to init
 * @param path The path of the csv file to read or write.
 */
void initCSVFile(CSVFile * csv, FILE ** file, char * path);

/**
 * Free a CSVFile object.
 * @param csv The CSVFile to free
 */
void freeCSVFile(CSVFile * csv);

/**
 * Init a CSVHeader object.
 * @param header The CSVHeader to init
 * @param size The number of columns wished
 * @param columnsNames The title of each column
 * @param formats The format of each column
 */
void initCSVHeader(CSVHeader * header, int size, char ** columnsNames, char * formats[5]);

/**
 * Free a CSVHeader object.
 * @param header The CSVHeader to free
 */
void freeCSVHeader(CSVHeader * header);

/**
 * Add a CSVLine to add to a CSVFile object.
 * @param csv the CSVFile to add a line to
 * @param values the CSVLine you want to add
 */
void addCSVLine(CSVFile * csv, void ** values);

/**
 * Write the CSVFile
 * @param csv
 */
void writeCSVFile(CSVFile * csv);







#endif //CSVLIBRARYTEST_FEATURES_H
