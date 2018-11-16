#include <stdio.h>

#include "../errors.h"
#include "../dataManager/dataManager.h"
#include "features.h"

int sortData(DataFlow *flow, Data *dest, int order, int orderType) {

    FILE *file = NULL;
    char line[TAILLE_MAX] = "";
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file == NULL)
        return ERROR;

    unpullAll(flow, dest, order, orderType);

    /*while (fgets(line, TAILLE_MAX, file) != NULL) {
        printf("%s", line);
    }*/

    fclose(file);

    return SUCCESS;
}

