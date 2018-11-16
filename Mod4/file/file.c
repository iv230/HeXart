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

    int index = 0;

    fscanf(file, "%s %s", line, line);

    while(!feof(file))
    {
        Data data = {0};

        fscanf(file, "%d,%d", &(data.timestamp), &(data.pulse));

        pullDataFlow(flow, data);
    }

    /*while (fgets(line, MAX_SIZE, file) != NULL) {
        int i =0;
        while(line[i]!=','){
            i++;
        }
        char *timestamp = calloc(20, sizeof(char));
        for(int j=0; j<i; j++) {
            timestamp[j]=line[j];
        }

        char *pulse = calloc(20, sizeof(char));
        for(int j=0; j<i; j++) {
            pulse[j]=line[j+(i+1)];
        }
        data[index].timestamp =  atoi(timestamp);
        data[index].pulse = atoi(pulse);
        if(index==0) {
            printf("timestamp(ms),pulse\n");
        } else {
            printf("%d,%d\n",data[index].timestamp,data[index].pulse);
        }
        index ++;
        }*/

        fclose(file);
}

