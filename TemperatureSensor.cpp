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

char TemperatureSensor::encodeTemperatureToChar(float temperature) {
    const char ZERO_CHAR = 'A';
    const char ONE_CHAR = 'B';
    const char TWO_CHAR = 'C';
    const char THREE_CHAR = 'D';
    const char FOUR_CHAR = 'E';
    const char FIVE_CHAR = 'F';
    const char TEN_CHAR = 'G';
    const char FIFTEEN_CHAR = 'H';
    const char TWENTY_CHAR = 'I';
    const char TWENTY_FIVE_CHAR = 'J';
    const char THIRTY_CHAR = 'K';
    const char THIRTY_FIVE_CHAR = 'L';
    const char FORTY_CHAR = 'M';
    const char GREATER_FORTY_CHAR = 'N';
    const char UNREAD_TEMPERATURE = 'Z';

    
    char character = 'A';
    bool negative_temperature = false;


    if (temperature == -127.00) 
    {
      character = UNREAD_TEMPERATURE;
    }
    else 
    {
      if (temperature < 0){
        temperature = temperature * -1;
        negative_temperature = true;
      }

      int i_temperature = (int) temperature;
        if (i_temperature == 0){
          character = ZERO_CHAR;
        }
        else if (i_temperature <= 1) {
          character = ONE_CHAR;
        }
        else if (i_temperature <= 2) {
          character = TWO_CHAR;
        }
        else if (i_temperature <= 3) {
          character = THREE_CHAR;
        }
        else if (i_temperature <= 4) {
          character = FOUR_CHAR;
        }
        else if (i_temperature <= 5) {
          character = FIVE_CHAR;
        }
        else if (i_temperature <= 10) {
          character = TEN_CHAR;
        }
        else if (i_temperature <= 15) {
          character = FIFTEEN_CHAR;
        }
        else if (i_temperature <= 20) {
          character = TWENTY_CHAR;
        }
        else if (i_temperature <= 25) {
          character = TWENTY_FIVE_CHAR;
        }
        else if (i_temperature <= 30) {
          character = THIRTY_CHAR;
        }
        else if (i_temperature <= 35) {
          character = THIRTY_FIVE_CHAR;
        }
        else if (i_temperature <= 40) {
          character = FORTY_CHAR;
        }
        else if (i_temperature > 40) {
          character = GREATER_FORTY_CHAR;
        }

      if (negative_temperature == true) {
        // This should pull up the ASCII value to make the letter lowercase
        // Which is the encoding used to decide if the value is negative
        character += 32;
      }

    }
    return character;
}