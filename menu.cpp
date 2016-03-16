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

m=0000   Hello
m=1000   Diagnose
m=2000   Configure
  m=2001    -> PROG x(1->9)
  ml=1 mp=        -> STEP y(1->9)
  1xy1         -> TEMP: 
  1xy2         -> DELAY: 
m=3000   Run Program
  m=3001   RUN INFO (STEP x\nTEMP:(CUR)->(TARGET)\nTIME:(ELAPSED)->(TOTAL)
m=4000   ABOUT
  m=4001   (c) ofauchon
*/
#include "menu.h"


Menu::Menu(LiquidCrystal *lcd, t_config *conf)
{
  _lcd=lcd;
  _conf=conf;
}

void Menu::mKeypress(char bt){
	switch (bt){
		case 'U':	
      if (mpos%1000==0 && mpos>0 ) mpos-=1000;
			break; 
    case 'D': 
      if (mpos%1000==0 && mpos<=4000) mpos+=1000;
      break; 
    case 'R': 
      if (mpos>0 && mpos%1000==0) mpos++;
      break; 
    case 'L': 
     if (mpos>0 && (mpos-1)%1000==0 ) mpos--;
      break; 
  }
  mComputeMenu();
}


void Menu::mComputeMenu(void){
  sprintf(mline1,"               ");
  sprintf(mline2,"               ");
  if (mpos==0) sprintf(mline1,    "e-binouze       "); 
  if (mpos==1000)  sprintf(mline1,"Diagnose        "); 
  if (mpos==1001)  sprintf(mline1,"Temp:%04d         ", (uint16_t)(_conf->curtemp*100)); 
  if (mpos==2000)  sprintf(mline1,"Configuration   "); 
  if (mpos==3000)  sprintf(mline1,"Run program     ");
  if (mpos==4000)  sprintf(mline1,"About           ");
  if (mpos>2000 && mpos<2010) {
        sprintf(mline1,"CFG: PROG %02d    ", mpos-2000);
        sprintf(mline2,">T:%03d  D:%03d  ", 100, 180);
  }
  if (mpos==4001) {sprintf(mline1,"About           "); sprintf(mline2,"(c)Fauchon 2016 ");} 
 
}

void Menu::mUpdateLcd(){
  _lcd->setCursor(0,0); _lcd->print(this->mline1);
  _lcd->setCursor(0,1); _lcd->print(this->mline2);
}




