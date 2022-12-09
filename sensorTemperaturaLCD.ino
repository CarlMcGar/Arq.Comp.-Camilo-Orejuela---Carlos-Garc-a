//
//    FILE: dht11_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 1.0.0
// PURPOSE: DHT library test sketch for DHT11 && Arduino
//     URL: https://github.com/RobTillaart/DHTstable
//
//  HISTORY:
//  1.0.0   2021-05-26  class name changed to DHTStable  (breaking change)
//
//  0.2.0   use getHumidity() and getTemperature()
//  0.1.2   add URL in header


#include "DHTStable.h"
#include <LiquidCrystal.h>

DHTStable DHT;

#define DHT11_PIN 22

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float temperatura;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHTSTABLE_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}


void loop()
{
  // READ DATA
  int chk = DHT.read11(DHT11_PIN);
  temperatura =DHT.getTemperature();
  if(temperatura>29)
    Serial.print("LED_RED = ON \n");
  else if (temperatura <26)
    Serial.print("LED_BLUE = ON \n");
  else if (temperatura<29 || temperatura>26)
    Serial.print("LED_GREEN = ON \n");     
  // DISPLAY DATA
  lcd.setCursor(0, 1);
  lcd.print(DHT.getHumidity());
  lcd.setCursor(0, 0);
  lcd.println(temperatura);

  delay(2000);
  lcd.clear();  
}

// -- END OF FILE --
