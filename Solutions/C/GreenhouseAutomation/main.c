#include "greenhouse.h"
#include <stdio.h>
#include <stdlib.h>
int main(){

    struct Greenhouse ghPathar;

    ghPathar.temperatureSensor.value=34.5;
    ghPathar.temperatureSensor.status=1;
    ghPathar.humiditySensor.value=56.7;
    ghPathar.humiditySensor.status=1;
    ghPathar.lightSensor.value=1000;
    ghPathar.lightSensor.status=1;
    ghPathar.soilMoistureSensor.value=45;
    ghPathar.soilMoistureSensor.status=1;

    ghPathar.fan.status=1;
    ghPathar.fan.targetValue=100;
    ghPathar.light.status=1;
    ghPathar.light.targetValue=100;
    ghPathar.waterPump.status=1;
    ghPathar.waterPump.targetValue=100;
    ghPathar.heater.status=1;
    ghPathar.heater.targetValue=100;

    printf("Temperature Sensor Value: %f\n",ghPathar.temperatureSensor.value);
    printf("Humidity Sensor Value: %f\n",ghPathar.humiditySensor.value);
    printf("Light Sensor Value: %f\n",ghPathar.lightSensor.value);
    printf("Soil Moisture Sensor Value: %f\n",ghPathar.soilMoistureSensor.value);

    printf("Fan Status: %d\n",ghPathar.fan.status);
    printf("Light Status: %d\n",ghPathar.light.status);
    printf("Water Pump Status: %d\n",ghPathar.waterPump.status);
    printf("Heater Status: %d\n",ghPathar.heater.status);



    struct Greenhouse ghLakshayacheMaal;
    
    ghLakshayacheMaal.temperatureSensor.value=32.5;
    ghLakshayacheMaal.temperatureSensor.status=01;
    ghLakshayacheMaal.humiditySensor.value=66.7;
    ghLakshayacheMaal.humiditySensor.status=1;
    ghLakshayacheMaal.lightSensor.value=1000;
    ghLakshayacheMaal.lightSensor.status=1;
    ghLakshayacheMaal.soilMoistureSensor.value=45;
    ghLakshayacheMaal.soilMoistureSensor.status=1;

    ghLakshayacheMaal.fan.status=1;
    ghLakshayacheMaal.fan.targetValue=100;
    ghLakshayacheMaal.light.status=1;
    ghLakshayacheMaal.light.targetValue=100;
    ghLakshayacheMaal.waterPump.status=1;
    ghLakshayacheMaal.waterPump.targetValue=100;
    ghLakshayacheMaal.heater.status=1;
    ghLakshayacheMaal.heater.targetValue=100;

    printf("Temperature Sensor Value: %f\n",ghLakshayacheMaal.temperatureSensor.value);
    printf("Humidity Sensor Value: %f\n",ghLakshayacheMaal.humiditySensor.value);
    printf("Light Sensor Value: %f\n",ghLakshayacheMaal.lightSensor.value);
    printf("Soil Moisture Sensor Value: %f\n",ghLakshayacheMaal.soilMoistureSensor.value);

    printf("Fan Status: %d\n",ghLakshayacheMaal.fan.status);
    printf("Light Status: %d\n",ghLakshayacheMaal.light.status);
    printf("Water Pump Status: %d\n",ghLakshayacheMaal.waterPump.status);
    printf("Heater Status: %d\n",ghLakshayacheMaal.heater.status);

    return 0;
}
