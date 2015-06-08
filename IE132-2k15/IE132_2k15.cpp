/*
	Libreria IE-132_2k15
	Librería creada con fines educativos
	Version:0.001
	Lanzado bajo licencia---
*/

#include <arduino.h>
#include <IE132_2k15.h>

	led::led(int entrada, int io, int milisegs){
		_entrada = entrada;
		_milisegs = milisegs;
		_io = io;
		if(_io == 0){
			pinMode(_entrada, OUTPUT);
		}else if(_io == 1){
			pinMode(_entrada, INPUT);
		}else{
			Serial.print("Error 1");
		}
		
	}

	led::led(int entrada, int io){
		_entrada = entrada;
		_io = io;
		if(_io == 0){
			pinMode(_entrada, OUTPUT);
		}else if(_io == 1){
			pinMode(_entrada, INPUT);
		}else{
			Serial.print("Error 1");
		}
		
	}

	void led::parpadeo(){
		digitalWrite(_entrada, HIGH);
		delay(_milisegs);
		digitalWrite(_entrada, LOW);
		delay(_milisegs);
	}

	
	void led::leerAnalog(){
		if( (analogRead(_entrada) >= (_milisegs - 65)) && (analogRead(_entrada) <= (_milisegs)) ){
			Serial.print( analogRead(_entrada) );
		}
	}