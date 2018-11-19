#ifndef MOD4_ACTIONS_H
#define MOD4_ACTIONS_H

enum{ MIN, MAX };

int sortData(DataFlow * flow, Data * dest, int order, int orderType);

int getData(DataFlow * flow, Data * dest, int type, int value);

double getAveragePulse(Data * arrData, int size);

int getDataInInterval(DataFlow * flow, Data * dest, int valueMin, int valueMax);

int getExtremePulse(DataFlow * flow, Data * dest, int extreme);

#endif //MOD4_ACTIONS_H
