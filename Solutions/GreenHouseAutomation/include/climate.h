#include<stdbool.h>
#include "./datetime.h"
#ifndef CLIMATE_H
#define CLIMATE_H

struct Climate{
    struct DateTime* ptrDateTime;
    float temp;
    int humadity;
    int light;
   // bool fanstatus;
};
#endif