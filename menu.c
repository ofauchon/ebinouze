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

void up_key(uint8_t bt){
	switch (mpos){
		1:	
			if (bt == 2) mpos=2;
			if (bt == 5) mpos=11;
			break; 
		2:	
			if (bt == 2) mpos=0;
			if (bt == 5) mpos=21;
			break; 
	}
}
	

void gmenu(){
	switch (mpos){
		1:	
			lcd.setCursor(0,0); lcd.print("Configuration");
			break;
		2:
			lcd.setCursor(0,0); lcd.print("Information");
			break; 
		21:
			lcd.setCursor(0,0); lcd.print("Temp1:");
			break; 


	}
}


