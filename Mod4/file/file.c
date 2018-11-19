#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../dataManager/dataManager.h"
#include "file.h"
#include "../errors.h"

int readFile(char * path, DataFlow * flow)
{
    FILE *file = fopen(path, "r");;
    char line[MAX_SIZE] = "";

    if(file == NULL)
        return ERROR;

    fscanf(file, "%s", line);

    while(!feof(file))
    {
        Data data = {0};

        fscanf(file, "%d;%d", &(data.timestamp), &(data.pulse));

        pullDataFlow(flow, data);
    }

    fclose(file);
}

