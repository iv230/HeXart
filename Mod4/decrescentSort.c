/*#include <stdio.h>
#include <stdlib.h>
#include "features/features.h"

void timeDecrescentSort() {
    FILE *file = NULL;
    char *lines[TAILLE_MAX];
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file != NULL) //test
    {
        int y=0;
        while (fgets(lines[y], TAILLE_MAX, file) != NULL) {
            y++;
       }
       printf("%d", y);

          for (int i = 1; i <= y; i++) {

              printf("%s", lines[y- i]);
              printf("i =%d",i);
          }

        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier ");
    }
}*/