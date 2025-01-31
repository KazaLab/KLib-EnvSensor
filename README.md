# KLib-EnvSensor

KLib-EnvSensor is a library for reading environmental data from a BME680 sensor. It provides temperature, humidity, pressure, and gas resistance readings.

## Installation
### Using PlatformIO

Add the following to `platformio.ini`:

```ini
lib_deps = https://github.com/KazaLab/KLib-EnvSensor.git
```

### Usage

```cpp
#include <KLib_EnvSensor.h>

KLib_EnvSensor sensor;

void setup() {
    Serial.begin(115200);
    sensor.begin();
}

void loop() {
    EnvSensorValues values = sensor.read();
    Serial.print("Temperature: ");
    Serial.println(values.temperature);
    delay(2000);
}
```
