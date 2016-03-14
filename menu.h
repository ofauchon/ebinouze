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
#ifndef MENU_H
#define MENU_H
#include <stdint.h>
#include <LiquidCrystal.h>


class Menu
{
  public: 
  Menu(LiquidCrystal *lcd); 
  void mComputeMenu(void);
  void mUpdateLcd(void);
  void mKeypress(char bt);
  LiquidCrystal *_lcd; 

 private:
  char mline1[17];
  char mline2[17];  
  uint16_t mpos=0; 

 };

#endif
