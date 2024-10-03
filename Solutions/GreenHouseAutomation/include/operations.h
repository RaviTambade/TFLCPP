#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <time.h>
#include "./climate.h"
//Function prototypes
struct Climate * getClimateData();
void displayClimateData(struct Climate* ptr);
void controlFan( struct Climate * ptr, bool status);
#endif
