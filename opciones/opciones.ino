#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int ran=0;
int contador=0;
char comdata = ' ';
bool b=true;
String a[]={"opc-1","opc-2","opc-3","opc-4"};

void setup()
{ 
  lcd.init();                      // incia el lcd 
  lcd.backlight();
  Serial.begin(9600);
  lcd.print(a[ran]); //16 espacios horizontas de la matriz 16x2
}

void loop()
{
  comdata = Serial.read();
  switch(comdata){//no cerrado
    case '1':
      bajaMenu();
    break;
  
    case '2':
        subeMenu();
    break;
    }
    // delay(300);
}

void bajaMenu(){
  if((ran>=0) && (ran<=3) && (a[ran] != '\0')){
            lcd.clear();
            ran++;
            if(ran>3){
              ran=3;
            }
            lcd.print(a[ran]);
            //delay(300);
            comdata = char(Serial.read());
            Serial.println(comdata);
        }else{
          lcd.clear();
          ran--;
          lcd.print(a[ran]);
          comdata = char(Serial.read());
        }
};

void subeMenu(){
  if(ran>=0 && ran<=3 && a[ran] != '\0'){
              lcd.clear();
              ran--;
              if(ran<0){
              ran=0;
              }
              lcd.print(a[ran]);
              //delay(300);
              comdata = char(Serial.read());
              Serial.println(comdata);
          }
          else{
          lcd.clear();
          ran++;
          lcd.print(a[ran]);
          comdata = char(Serial.read());
        }
}
