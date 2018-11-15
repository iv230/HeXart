#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void displayCsvOrder() {
    FILE *file = NULL;
    char line[TAILLE_MAX] = "";
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file != NULL) //test
    {
        while (fgets(line, TAILLE_MAX, file) != NULL) {
            printf("%s", line);
        }

        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier ");
    }
}