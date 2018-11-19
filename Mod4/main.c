#include <stdio.h>
#include <stdlib.h>
#include "dataManager/dataManager.h"
#include "file/file.h"
#include "errors.h"
#include "features/features.h"
#include "dataPrinter/dataPrinter.h"
#include "menu/menu.h"

#define FILE_PATH "../../processing_data/Battements.csv"

int main(int argc, char * argv[])
{
    DataFlow flow = {0};
    if(readFile(FILE_PATH, &flow) == ERROR)
    {
        printf("Fatal error: can't open file: %s", FILE_PATH);
        return 1;
    }

    int follow = 0;

    do
    {
        displayMenu(flow);

        printf("\n==========================================\nVoulez-vous continuer ?\n 0: Non.\n 1: Oui.");
        scanf("%d", &follow);

    } while(follow == 1);

    /*int size = flow.size;

    Data * arrData = calloc((size_t) size, sizeof(Data));
    sortData(&flow, arrData, CRESCENT, TIME);

    printDataArray(arrData, size);*/

   /* Data data = {0};
    int line = getData(&flow, &data, PULSE, 70) + 1;
    printf("==========================================\nA data has been found !\n==========================================\n");
    printData(data);
    printf("At line %d", line);*/

   Data *  arrdata = calloc(0, sizeof(Data));
   int size = getDataInInterval(&flow, arrdata, 500, 3000);
   printDataArray(arrdata, size);

   double pulse = getAveragePulse(arrdata, size);
   printf("Average pulse: %lf", pulse);

    return SUCCESS;
}