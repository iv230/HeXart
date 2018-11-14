#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

void displayCsvOrder() {
    FILE *fichier = NULL;
    char chaine[TAILLE_MAX] = "";
    fichier = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (fichier != NULL) //test
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            printf("%s", chaine);
        }

        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier ");
    }
}