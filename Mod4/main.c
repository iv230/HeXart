#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "dataManager/dataManager.h"
#include "file/file.h"
#include "features/features.h"
#include "dataPrinter/dataPrinter.h"

int main() {
  //menu();
  //displayCsvOrder();
  //timeCrescentSort();
  //pulseCresentSort();
  //timeDecrescentSort();

    DataFlow flow = {0};
    readFile("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", &flow);

    int size = flow.size;

    Data * arrData = calloc(0, sizeof(Data));
    sortData(&flow, arrData, DECRESCENT, TIME);
    printData(arrData, size);

    return 0;
}