#include <stdio.h>
#include <stdlib.h>

#include "dataManager.h"

/**
 * Enqueue function
 * @param flow The queue we want to enqueue in
 * @param data The data we want to enqueue
 */
void pullDataFlow(DataFlow * flow, Data data)
{
    if(flow == NULL) {
        return;
    }

    DataLine * line = calloc(1, sizeof(DataLine)); // We initalize and fill the element which will contain the data we want to add to the queue.
    line->data = data;
    line->next = NULL; // This line is very important : if we don't initialize this pointer to null, an empty DataLine will be created and make not our follow while loop working.


    if(flow->first != NULL) // If the queue isn't empty, we need to get the last element of the queue.
    {

        DataLine *currDataLine = flow->first; // We get the first element of the queue

        int i = 0;

        while (currDataLine->next != NULL) // Then we loop over the elements of the queue until the end.
        {
            currDataLine = currDataLine->next;
            i++;
        }

        currDataLine->next = line; // Then we insert the line in the last element of the queue.
    }
    else
        flow->first = line; // If the queue is empty, we only have to insert the line in the first element of the list.

    flow->size++; // We increment the value of the size of the queue.

}

/**
 * Dequeue function
 * @param flow The queue we want to dequeue in
 * @return The data we just dequeued
 */
Data unpullDataLine (DataFlow * flow)
{
    Data data = {0};

    if (flow == NULL) {
        return data;
    }

    DataLine line = {0};

    if (flow->first != NULL) {
        line = *flow->first; // We get the first element of the queue
        flow->first = line.next; // And move the second one to the first element of the list.

        data = line.data;

    }

    flow->size--; // We decrement the value of the size of the queue

    return data;
}

/**
 * Dequeue all the datas of the function according to the order wished
 * @param flow The queue we want to dequeue
 * @param data The data array we want to store the data in
 * @param order The order (crescent of decrecent)
 * @param orderType The type we want to order by (time or pulse)
 */
void unpullAll(DataFlow * flow, Data * data, int order, int orderType)
{
    int size = 0;

    while(flow->first != NULL)
    {
        size++; // We increment the size of the array

        if(order == NONE)
            data[size - 1] = unpullDataLine(flow); // We dequeue one time and store the data in the array without sorting if we don't want to sort anything.
        else
        {
            Data currData = (unpullDataLine(flow)); // Else we only get the data...
            insertData(data, &currData, size, order, orderType); // And insert it in the array according to the order parameters.
        }

    }
}

void insertData(Data * arrData, Data * data, int size, int order, int orderType)
{
    if(size == 1)
    {
        arrData[0] = *data;
    }
    else
    {
        int i = size - 2;
        Data prevData = arrData[i];

        int comparison = dataCompare(prevData, *data, order, orderType);

        while(i >= 0 && (comparison == GREATER || comparison == EQUAL))
        {
            arrData[i + 1] = arrData[i];
            i--;
            prevData = arrData[i];
            comparison = dataCompare(prevData, *data, order, orderType);
        }
        arrData[i + 1] = *data;
    }
}

int dataCompare(Data data1, Data data2, int order, int orderType)
{
    if(order == NONE)
        return 1;

    int parameter1 = orderType == TIME ? data1.timestamp : data1.pulse;
    int parameter2 = orderType == TIME ? data2.timestamp : data2.pulse;

    int returns[2];

    if(order == CRESCENT)
    {
        returns[0] = GREATER;
        returns[1] = LOWER;
    }
    else
    {
        returns[0] = LOWER;
        returns[1] = GREATER;
    }


    return (parameter1 > parameter2)
           ? returns[0]
           : (parameter1 < parameter2)
           ? returns[1]
           : EQUAL;
}