#include <stdio.h>
#include <stdlib.h>

#include "../errors.h"
#include "../dataManager/dataManager.h"
#include "features.h"

int getData(DataFlow * flow, Data * dest, int type, int value)
{
    Data * arrData = calloc((size_t)flow->size, sizeof(Data));

    int finished = 0;
    int start = 0, middle = 0, end = flow->size;

    unpullAll(flow, arrData, CRESCENT, type);

    while(!finished && end - start > 1)
    {
        middle = (start + end) / 2;

        *dest = arrData[middle];

        int currValue = type == TIME
                        ? dest->timestamp
                        : dest->pulse;

        finished = currValue == value;

        if(value < currValue)
            end = middle;
        else
            start = middle;
    }

    return middle;
}

int getDataInInterval(DataFlow * flow, Data * dest, int valueMin, int valueMax)
{
    int arrSize = flow->size;
    Data * arrData = calloc((size_t)flow->size, sizeof(Data));
    unpullAll(flow, arrData, CRESCENT, TIME);

    int size = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(arrData[i].timestamp >= valueMin && arrData[i].timestamp <= valueMax)
        {
            size++;
            dest = realloc(dest, size * sizeof(Data));
            dest[size - 1] = arrData[i];
        }

    }

    return size;
}

double getAveragePulse(Data * arrData, int size)
{
    double amount = 0;

    for(int i = 0; i < size; i++)
        amount += arrData[i].pulse;

    return amount / (double) size;
}

int getExtremePulse(DataFlow * flow, Data * dest, int extreme)
{
    int arrSize = flow->size;
    Data * arrData = calloc((size_t)flow->size, sizeof(Data));
    unpullAll(flow, arrData, CRESCENT, PULSE);

    if(extreme == MIN)
        *dest = arrData[0];
    else
        *dest = arrData[arrSize - 1];

    return extreme == MIN ? 0 : arrSize - 1;
}