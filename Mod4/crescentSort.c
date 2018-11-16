/*#include <stdio.h>
#include <stdlib.h>
#include "features/features.h"


void timeCrescentSort(){
    Data Datas[55];
    FILE *file = NULL;
    char line[TAILLE_MAX] = "";
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file != NULL) //test
    {
        int index=0;
        while (fgets(line, TAILLE_MAX, file) != NULL) {
            int i =0;
            while(line[i]!=','){
                i++;
            }
            char *timestamp = calloc(20, sizeof(char));
            for(int j=0; j<i; j++) {
                timestamp[j]=line[j];
            }

            char *pulse = calloc(20, sizeof(char));
            for(int j=0; j<i; j++) {
                pulse[j]=line[j+(i+1)];
            }
            Datas[index].timestamp =  atoi(timestamp);
            Datas[index].pulse = atoi(pulse);
            if(index==0) {
                printf("timestamp(ms),pulse\n");
            } else {
            printf("%d,%d\n",Datas[index].timestamp,Datas[index].pulse);
            }
            index ++;
        }
        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier ");
    }
}

void pulseCresentSort(){
    Data Datas[55];
    FILE *file = NULL;
    char line[TAILLE_MAX] = "";
    file = fopen("D:\\GitHub\\GitHub2\\GitHub\\HeXart\\Mod4\\Battements.csv", "r+");

    if (file != NULL) //test
    {
        int index=0;
        while (fgets(line, TAILLE_MAX, file) != NULL) {
            int i =0;
            while(line[i]!=','){
                i++;
            }
            char *timestamp = calloc(20, sizeof(char));
            for(int j=0; j<i; j++) {
                timestamp[j]=line[j];
            }

            char *pulse = calloc(20, sizeof(char));
            for(int j=0; j<i; j++) {
                pulse[j]=line[j+(i+1)];
            }
            Datas[index].timestamp =  atoi(timestamp);
            Datas[index].pulse = atoi(pulse);
            if(index==0) {
                printf("pulse, timestamp(ms)\n");
            } else {
                printf("%d,%d\n",Datas[index].pulse,Datas[index].timestamp);
            }
            index ++;
        }
        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier ");
    }
}*/