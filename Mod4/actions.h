

#ifndef MOD4_ACTIONS_H
#define MOD4_ACTIONS_H

//displayCSVorder

#define TAILLE_MAX 1000
void displayCsvOrder();

// end displayCSVorder

//crescentSort

void timeCrescentSort();
void pulseCresentSort();

//end crescentSort

void timeDecrescentSort();



typedef struct data {
    int timestamp;
    int pulse;
} Data;

#endif //MOD4_ACTIONS_H
