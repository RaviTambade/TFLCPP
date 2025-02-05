#ifndef DATETIME_H
#define DATETIME_H

#include "./date.h"
#include "./climatetime.h"

struct DateTime{
    struct Time time;
    struct Date date;
};

#endif