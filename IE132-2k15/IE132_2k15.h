/*
	Libreria IE-132_2k15
	Librería creada con fines educativos
	Version:0.001
	Lanzado bajo licencia---
*/

#ifndef IE132_2k15_h
#define IE132_2k15_h
#include "arduino.h"

	class led
	{
		public:
			led(int entrada, int io );
			led(int entrada, int io, int milisegs);
			void parpadeo();
			void leerAnalog();
			
		private:
			int _entrada;
			int _io;
			int _milisegs;
	};

	class lcd
	{
		public:
			lcd(int entrada, int io );
			lcd(int entrada, int io, int milisegs);
			void parpadeo();
			void leerAnalog();
			
			//void parpadeo();
		private:
			int _entrada;
			int _io;
			//int _salida;
			int _milisegs;
	};

#endif