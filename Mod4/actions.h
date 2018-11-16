

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

//création de la file
typedef struct DataLine DataLine;
struct DataLine
{
    int time;
    int pulse;
    DataLine *next;
};

typedef struct
{
    DataLine *first;
}DataFlow;

void pullDataFlow(DataFlow * flow, DataLine * data);
void pass (DataFlow * flow);

#endif //MOD4_ACTIONS_H
