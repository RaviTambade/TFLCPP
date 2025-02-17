#include "sensor.h"
#include "actuator.h"

struct Greenhouse{
    struct Sensor temperatureSensor;
    struct Sensor humiditySensor;
    struct Sensor lightSensor;
    struct Sensor soilMoistureSensor;
    

    struct Actuator fan;
    struct Actuator light;
    struct Actuator waterPump;
    struct Actuator heater;
};