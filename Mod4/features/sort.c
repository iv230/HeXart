#include <stdio.h>

#include "../errors.h"
#include "../dataManager/dataManager.h"
#include "features.h"

int sortData(DataFlow *flow, Data *dest, int order, int orderType)
{
    unpullAll(flow, dest, order, orderType);

}

