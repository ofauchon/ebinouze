


/*
    This file is part of E-Binouze.
    E-Binouze is a brewery control system

    Copyright (C) 2015 Olivier Fauchon 

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

Additionnal lib : 
http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip
http://www.hobbytronics.co.uk/datasheets/DallasTemperature_360.zip

Serial port: 

*/
#include <OneWire.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <DallasTemperature.h>

#include "misc.h"
#include "menu.h"


t_config myConfig; 
LiquidCrystal lcd(30, 31, 32, 33, 34, 35);
Menu menu(&lcd,&myConfig);

// DS18S20
OneWire oneWire(ONEWIRE_DS);
DallasTemperature sensors(&oneWire);



void setup() 
{
  // Increase boot counter
  EEPROM[EE_BOOT]++; 
  
  // Configure LCD
  lcd.begin(16, 2);
  lcd.display();


  // Configure output PIN
  //pinMode(PIN_LED, OUTPUT); 
  //digitalWrite(PIN_LED,HIGH); 

  // Initialize sensors
  sensors.begin();
  
  // Initial menu setup
  menu.mComputeMenu();

  // Serial port
  Serial.begin(115200);    // start serial port
  Serial.println("YourDuinoStarter Example: DS18B20 Temperature Sensor Reading");
}




int config_zero(t_config *pConf)
{
  pConf->firmware_version=99;
  for (uint8_t i=0; i<10;i++)
  {
    pConf->stage_duration[i]=0; 
    pConf->stage_finaltemp[i]=0;
  } 
  return 0; 
}

void config_flash(t_config *pConf)
{
  EEPROM.put(0,pConf->firmware_version); 
  EEPROM.put(2,pConf->stage_number); 
  for (uint8_t i=0; i<pConf->stage_number;i++){
     EEPROM.put(3 + i*2, pConf->stage_number); 
  }
}

void config_read(t_config *pConf)
{
  EEPROM.get(0,pConf->firmware_version); 
  EEPROM.get(2,pConf->stage_number); 
  for (uint8_t i=0; i< pConf->stage_number;i++){
     EEPROM.get(3 + i*2, pConf->stage_number); 
  }
}



//---------------------------------- 


void test()
{
  //Serial.print("Reading temperatures..."); 
  sensors.requestTemperatures();
  //Serial.println("Done");
  
  float t=sensors.getTempCByIndex(0);
  Serial.println(t,2);
  delay(1000);

  char c[10];
  sprintf(c,"%04d", (uint16_t)(t*100)); 
  lcd.setCursor(0,0); 
  lcd.print(c);
}



void loop() {
  //menu.mUpdateLcd();

  sensors.requestTemperatures();
  myConfig.curtemp=sensors.getTempCByIndex(0);

  uint8_t doo=1; 
  if (doo--){
    delay(1000); menu.mKeypress('D'); menu.mUpdateLcd(); 
    delay(1000); menu.mKeypress('R'); menu.mUpdateLcd(); 
  }
  

  
}

