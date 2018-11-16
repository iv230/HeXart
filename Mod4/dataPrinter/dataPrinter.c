#include <stdio.h>

#include "../dataManager/dataManager.h"
#include "dataPrinter.h"

void printData(Data * arrData, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d, %d\n", arrData[i].timestamp, arrData[i].pulse);
}
