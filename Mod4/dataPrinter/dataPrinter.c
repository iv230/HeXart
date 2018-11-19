#include <stdio.h>

#include "../dataManager/dataManager.h"
#include "dataPrinter.h"

void printDataArray(Data * arrData, int size) // Il s'agit simplement de parcourir les valeurs du tableau de sorte à les afficher.
{
    for(int i = 0; i < size; i++)
       printData(arrData[i]);
}

void printData(Data data)
{
    printf("Timestamp: %d, Pulse: %d\n", data.timestamp, data.pulse);
}
