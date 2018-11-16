#include <stdio.h>
#include <string.h>

#include "features.h"

void writeCSVFile(CSVFile * csv)
{
    FILE * file = *(csv->file);

    for(int i = 0; i < csv->columns.size; i++)
    {
        fprintf(file, "%s,", csv->columns.columnsNames[i]);
    }

    fprintf(file, "\n");

    for(int i = 0; i < csv->size; i++)
    {
        for(int j = 0; j < csv->columns.size; j++)
        {
            char format[5];
            strcpy(format, csv->columns.formats[j]);

            if(strcmp(format, "%c") == 0)
                fprintf(file, format, *(char *)(csv->lines[i][j]));
            else if(strcmp(format, "%d") == 0 || strcmp(format, "%i") == 0)
                fprintf(file, format, *(int *)(csv->lines[i][j]));
            else if(strcmp(format, "%e") == 0 || strcmp(format, "%lf") == 0)
                fprintf(file, format, *(double *)(csv->lines[i][j]));
            else if(strcmp(format, "%f") == 0 || strcmp(format, "%e") == 0)
                fprintf(file, format, *(float *)(csv->lines[i][j]));
            else if(strcmp(format, "%p") == 0)
                fprintf(file, format, csv->lines[i][j]);
            else if(strcmp(format, "%s") == 0)
                fprintf(file, format, (char *)(csv->lines[i][j]));
            else if(strcmp(format, "%u") == 0)
                fprintf(file, format, *(short *)(csv->lines[i][j]));
            else
                printf("Error while scanning CSV Column format.");
            fprintf(file, ",");
        }

        fprintf(file, "\n");
    }
}

