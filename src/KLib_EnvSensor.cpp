#include "KLib_EnvSensor.h"

KLib_EnvSensor::KLib_EnvSensor() : sensorAvailable(false) {}

/**
 * @brief Initialize the environmental sensor (BME680).
 * Configure the sensor settings for reading temperature, humidity, pressure, etc.
 */
bool KLib_EnvSensor::begin() {
    sensorAvailable = bme.begin();
    if (!sensorAvailable) {
        Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
        return false;
    }

    // Configure the BME680 sensor settings
    bme.setTemperatureOversampling(BME680_OS_16X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320°C for 150 ms

    return true;
}

/**
 * @brief Read the values from the environmental sensor.
 *
 * @return EnvSensorValues A structure containing the measured values: temperature, humidity, pressure, etc.
 */
EnvSensorValues KLib_EnvSensor::read() {
    EnvSensorValues result = {0, 0, 0, 0, 0};

    if (!sensorAvailable) {
        Serial.println(F("Sensor not available, skipping measurement."));
        return result;
    }

    unsigned long endTime = bme.beginReading();
    if (endTime == 0) {
    Serial.println(F("Failed to begin reading."));
    return result;  // If the reading failed, return default values
  }

  // Wait until the measurement is ready
    while (millis() < endTime);

    if (!bme.endReading()) {
        Serial.println(F("Failed to complete reading."));
        return result;
    }

    result.temperature = bme.temperature;
    result.humidity = bme.humidity;
    result.pressure = bme.pressure / 100.0;  // Convert to hPa
    result.gas_resistance = bme.gas_resistance / 1000.0; // Convert to kΩ
    result.altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

    return result;
}
