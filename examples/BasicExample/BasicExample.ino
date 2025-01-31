#include <KLib_EnvSensor.h>

KLib_EnvSensor sensor;

void setup() {
    Serial.begin(115200);
    if (!sensor.begin()) {
        Serial.println("Failed to initialize sensor.");
    }
}

void loop() {
    EnvSensorValues values = sensor.read();

    Serial.print("Temperature: ");
    Serial.print(values.temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(values.humidity);
    Serial.println(" %");

    Serial.print("Pressure: ");
    Serial.print(values.pressure);
    Serial.println(" hPa");

    delay(2000);
}
