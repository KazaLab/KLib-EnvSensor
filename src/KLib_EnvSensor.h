#ifndef KLIB_ENVSENSOR_H
#define KLIB_ENVSENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME680.h>

#define SEALEVELPRESSURE_HPA (1013.25)

struct EnvSensorValues {
    float temperature;
    float humidity;
    float pressure;
    float gas_resistance;
    float altitude;
};

class KLib_EnvSensor {
private:
    Adafruit_BME680 bme;
    bool sensorAvailable;

public:
    KLib_EnvSensor();
    bool begin();
    EnvSensorValues read();
};

#endif