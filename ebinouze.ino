

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
*/
#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

#include "misc.h"
#include "menu.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Menu menu(&lcd);


void setup() 
{
  EEPROM[5]++; 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(53, OUTPUT); 
  menu.mComputeMenu();
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





void loop() {
  // Turn off the display:
  //lcd.noDisplay();
  // Turn on the display:
  lcd.display();
  menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('D'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('D'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('R'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('L'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('D'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('R'); menu.mUpdateLcd(); 
  delay(1000); menu.mKeypress('L'); menu.mUpdateLcd(); 



  
}

