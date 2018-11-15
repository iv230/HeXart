#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

//contient fonctions pour afficher menus

void menu () {
 int operation =0,triChoice =0, researchChoice =0, displayChoice =0;
    do {
        printf("Voulez vous effectuer un tri, une recherche ou un affichage de donn‚es?\n");
        printf("tri : 1\nrecherche : 2\naffichage : 3\nsortir : 0\n");
        scanf("%d", &operation);
        printf("\n");

        switch (operation){
            case 1:
                do {
                    printf("Veuillez choisir la maniŠre de trier les donn‚es souhait‚e\n");
                    printf("Afficher dans l'ordre d'acquisition des donn‚es : 1\n");
                    printf("Afficher les donn‚es dans l'ordre croissant : 2\n");
                    printf("Afficher les donn‚es dans l'ordre d‚croissant : 3\n");
                    printf("Quitter: 0\n");
                    scanf("%d", &triChoice);
                    printf("\n");
                } while(triChoice >3 || triChoice <0);
                if (triChoice == 2 || triChoice == 3)
                {
                    int timePulse;
                    printf ("Que voulez vous trier ?\n");
                    printf ("le temps : 1\nle pouls : 2\n");
                    scanf ("%d", timePulse);
                    printf("\n");
                }
                break;
            case 2:
                do {
                    printf("Veuillez choisir le type de recherche … effectuer\n");
                    printf("Rechercher les donn‚es pour un temps particulier : 1\n");
                    printf("Rechercher le pouls maximum : 2\n");
                    printf("Rechercher le pouls minimum : 3\n");
                    printf("Quitter: 0\n");
                    scanf("%d", &researchChoice);
                    printf("\n");
                } while (researchChoice > 3 || researchChoice < 0);
                break;
            case 3:
                do {
                    printf("Quel affichage voulez-vous effectuer?\n");
                    printf("Afficher la moyenne de pouls dans une plage de temps donn‚ :1\n");
                    printf("Afficher le nombre de lignes actuellement en m‚moire : 2\n");
                    printf("Quitter: 0\n");
                    scanf("%d", &displayChoice);
                    printf("\n");
                } while (displayChoice < 0 || displayChoice > 2);
                if (displayChoice == 1) {
                    printf("Choisir la plage de temps\n");
                    int timeMin, timeMax;
                    printf("Entrez le temps minimum de la plage souhait‚e\n");
                    scanf("%d", &timeMin);
                    printf("\n");
                    printf("Entrez le temps maximum de la plage souhait‚e\n");
                    scanf("%d", &timeMax);
                    printf("\n");
                }
        }
    } while (operation !=0);
}