#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {
  public:
    void begin(int pin, DallasTemperature sensors);
    float readTemperatureCelsius(DallasTemperature sensors);
  private:
    int _pin;
    DeviceAddress deviceAddress;
};

#endif