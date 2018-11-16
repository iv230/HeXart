/*#include <stdio.h>
#include <stdlib.h>
#include "features/features.h"

int displayTimeOrder(int order) {

    FILE *file = NULL;
    char line[TAILLE_MAX] = "";
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file == NULL)
        return ERROR;



    while (fgets(line, TAILLE_MAX, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return SUCCESS;
}*/