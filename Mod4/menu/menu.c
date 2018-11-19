#include <stdio.h>
#include <stdlib.h>

#include "../dataManager/dataManager.h"
#include "../dataPrinter/dataPrinter.h"
#include "../features/features.h"
#include "menu.h"

//contient fonctions pour afficher menus

void displayMenu(DataFlow flow) {

    int operation = 0, triChoice = 0, researchChoice = 0, displayChoice = 0;
    int size = flow.size;

    do {
        printf("Voulez vous effectuer un tri, une recherche ou un affichage de donn‚es?\n");
        printf("tri : 1\nrecherche : 2\naffichage : 3\nsortir : 0\n");
        scanf("%d", &operation);
        printf("\n");

    } while (operation < 0 || operation > 3);

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
            } while(triChoice > 3 || triChoice < 0);

            Data * arrData = calloc((size_t) size, sizeof(Data));

            if(triChoice == 1)
                unpullAll(&flow, arrData, CRESCENT, NONE);

            if (triChoice == 2 || triChoice == 3)
            {
                int timePulse;

                do
                {
                    printf("Que voulez vous trier ?\n");
                    printf("le temps : 1\nle pouls : 2\n");
                    scanf("%d", &timePulse);
                    printf("\n");

                } while(timePulse < 1 || timePulse > 2);

                unpullAll(&flow, arrData, triChoice == 2 ? CRESCENT : DECRESCENT, timePulse == 1 ? TIME : PULSE);
            }

            printDataArray(arrData, size);

            break;
        case 2:

            do {
                printf("Veuillez choisir le type de recherche … effectuer\n");
                printf("Rechercher les donn‚es pour un temps particulier : 1\n");
                printf("Rechercher les donn‚es pour un pouls particulier : 2\n");
                printf("Rechercher le pouls maximum : 3\n");
                printf("Rechercher le pouls minimum : 4\n");
                printf("Quitter: 0\n");
                scanf("%d", &researchChoice);
                printf("\n");
            } while (researchChoice > 4 || researchChoice < 0);

            Data data = {0};
            int line, value;

            if(researchChoice == 1 || researchChoice == 2)
            {
                printf("Enter the value you want to research.");
                scanf("%d", &value);
                line = getData(&flow, &data, researchChoice == 1 ? TIME : PULSE, value);
            }
            else
                line = getExtremePulse(&flow, &data, researchChoice == 3 ? MAX : MIN);

            printf("==========================================\nA data has been found !\n==========================================\n");
            printData(data);
            printf("At line %d", line);

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

                Data * onIntervalData = calloc(0, sizeof(Data));
                int intervalSize = getDataInInterval(&flow, onIntervalData, timeMin, timeMax);

                double averagePulse = getAveragePulse(onIntervalData, intervalSize);
                printf("Average pulse from %d up to %d ms : %lf", timeMin, timeMax, averagePulse);
            }
            else
                printf("Number of line: %d.", size);

            break;
        case 0:
            exit(EXIT_SUCCESS);
    }
}