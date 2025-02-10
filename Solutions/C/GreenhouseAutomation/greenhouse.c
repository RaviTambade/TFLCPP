#include "greenhouse.h"


void control_temperature(struct Greenhouse *env) {
    if (env->temperature_sensor.value < env->desired_temperature) {
        // Turn on heater if temperature is lower than desired
        env->heater.status = 1;
    } else if (env->temperature_sensor.value > env->desired_temperature) {
        // Turn off heater if temperature is higher than desired
        env->heater.status = 0;
    }
}

void control_humidity( struct Greenhouse *env) {
    if (env->humidity_sensor.value < env->desired_humidity) {
        // Turn on water pump or humidifier if humidity is lower than desired
        env->water_pump.status = 1;
    } else if (env->humidity_sensor.value > env->desired_humidity) {
        // Turn off water pump if humidity is higher than desired
        env->water_pump.status = 0;
    }
}

void control_light(Greenhouse *env) {
    if (env->light_sensor.value < 1000) {
        // Turn on light if light level is below 1000 lux
        env->light.status = 1;
    } else {
        // Turn off light if light level is above 1000 lux
        env->light.status = 0;
    }
}

void control_soil_moisture(Greenhouse *env) {
    if (env->soil_moisture_sensor.value < 30.0) {
        // Turn on water pump if soil moisture is low
        env->water_pump.status = 1;
    } else {
        // Turn off water pump if soil moisture is sufficient
        env->water_pump.status = 0;
    }
}
