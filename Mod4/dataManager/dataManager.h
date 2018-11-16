#ifndef MOD4_DATAMANAGER_H
#define MOD4_DATAMANAGER_H

enum { NONE, CRESCENT, DECRESCENT };
enum { TIME, PULSE };
enum { LOWER, EQUAL, GREATER };

typedef struct {
    int timestamp;
    int pulse;
} Data;

typedef struct DataLine DataLine;
struct DataLine
{
    Data data;
    DataLine *next;
};

typedef struct
{
    int size;
    DataLine *first;
}DataFlow;

void pullDataFlow(DataFlow * flow, Data data);
Data unpullDataLine (DataFlow * flow);
void unpullAll(DataFlow * flow, Data * data, int order, int orderType);

void insertData(Data * arrData, Data * data, int size, int order, int orderType);

int dataCompare(Data data1, Data data2, int order, int orderType);

#endif //MOD4_DATAMANAGER_H
