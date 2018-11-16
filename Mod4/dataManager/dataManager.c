#include <stdio.h>
#include <stdlib.h>

#include "dataManager.h"

void pullDataFlow(DataFlow * flow, Data data)
{
    if(flow == NULL) {
        return;
    }

    DataLine * line = calloc(1, sizeof(Data));
    line->data = data;
    line->next = NULL;


    if(flow->first != NULL)
    {

        DataLine *currDataLine = flow->first;

        int i = 0;

        while (currDataLine->next != NULL)
        {
            currDataLine = currDataLine->next;
            i++;
        }

        currDataLine->next = line;
    }
    else
        flow->first = line;

    flow->size++;

}

Data unpullDataLine (DataFlow * flow)
{
    Data data = {0};

    if (flow == NULL) {
        return data;
    }

    DataLine line = {0};

    if (flow->first != NULL) {
        line = *flow->first;
        flow->first = line.next;

        data = line.data;

    }

    flow->size--;

    return data;
}

void unpullAll(DataFlow * flow, Data * data, int order, int orderType)
{
    int size = 0;

    while(flow->first != NULL)
    {
        size++;
        data = realloc(data, size * sizeof(Data));

        if(order == NONE)
            data[size - 1] = unpullDataLine(flow);
        else
        {
            Data currData = (unpullDataLine(flow));
            insertData(data, &currData, size, order, orderType);
        }

    }
}

void insertData(Data * arrData, Data * data, int size, int order, int orderType)
{
    if(size == 1)
    {
        arrData[0] = *data;
    }
    else
    {
        int i = size - 2;
        Data prevData = arrData[i];

        int comparison = dataCompare(prevData, *data, order, orderType);

        while(i >= 0 && (comparison == GREATER || comparison == EQUAL))
        {
            arrData[i + 1] = arrData[i];
            i--;
            prevData = arrData[i];
            comparison = dataCompare(prevData, *data, order, orderType);
        }
        arrData[i + 1] = *data;
    }
}

int dataCompare(Data data1, Data data2, int order, int orderType)
{
    if(order == NONE)
        return 1;

    int parameter1 = orderType == TIME ? data1.timestamp : data1.pulse;
    int parameter2 = orderType == TIME ? data2.timestamp : data2.pulse;

    int returns[2];

    if(order == CRESCENT)
    {
        returns[0] = GREATER;
        returns[1] = LOWER;
    }
    else
    {
        returns[0] = LOWER;
        returns[1] = GREATER;
    }


    return (parameter1 > parameter2)
           ? returns[0]
           : (parameter1 < parameter2)
           ? returns[1]
           : EQUAL;
}