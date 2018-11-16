#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void pullDataFlow(DataFlow * flow, DataLine * data)
{
    if(flow == NULL || data == NULL) {
        return;
    }

    if(flow->first != NULL)
    {

        DataLine *currDataLine = flow->first;

        while (currDataLine->next != NULL)
            currDataLine = currDataLine->next;

        currDataLine->next = data;
    }
    else
        flow->first = data;
}

DataLine unpullDataLine (DataFlow * flow)
{
    DataLine data = {0};

    if (flow == NULL) {
        return data;
    }

    int nbFile = 0;

    if (flow->first != NULL) {
        DataLine *DataFile = flow-> first;

        nbFile = DataFile->time;
        nbFile = DataFile->pulse;
        flow->first = DataFile->next;
        free(DataFile);
    }
}