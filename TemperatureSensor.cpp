#include "TemperatureSensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

void TemperatureSensor::begin(int pin, DallasTemperature sensors) {
    this->_pin = pin;
    sensors.begin();
    if (!sensors.getAddress(this->deviceAddress, 0)) {
        Serial.println("Unable to find address for Device 0"); 
    }
    sensors.setResolution(this->deviceAddress, 9);
}

float TemperatureSensor::readTemperatureCelsius(DallasTemperature sensors) {
    sensors.requestTemperatures();
    float temperatureCelsius = -42.42;
    temperatureCelsius = sensors.getTempC(this->deviceAddress);
    return temperatureCelsius;
}