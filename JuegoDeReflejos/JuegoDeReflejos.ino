#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

bool a=false,b=false,c=false,d=true;


/*tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 349.23); delay(500); noTone(6); //fa
    tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 329.63); delay(350); noTone(6); //mi
    tone(6, 293.66); delay(350); noTone(6); //re*/

void setup() {
   pinMode(10,INPUT); //Entradas esperando 0 o 1, normalmente esperando 1
   pinMode(9,INPUT);
   pinMode(8,INPUT);
   pinMode(7,INPUT);
   
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   
   Serial.begin(9600);
   
   lcd.init ();
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print(" Reflejos V2.01 ");
}

void loop() {
  //acaba de iniciar?
  if(d==true){
    tone(6, 440.00, 500); delay(500); noTone(6); //la
    tone(6, 293.66); delay(500); noTone(6); //re
    tone(6, 349.23); delay(500); noTone(6); //fa
    tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 440.00, 500); delay(500); noTone(6); //la
    /*tone(6, 293.66); delay(500); noTone(6); //re
    tone(6, 349.23); delay(500); noTone(6); //fa
    tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 329.63); delay(500); noTone(6); //mi
    tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 349.23); delay(500); noTone(6); //fa
    tone(6, 329.63); delay(500); noTone(6); //mi
    tone(6, 392.00); delay(500); noTone(6); //sol
    tone(6, 261.63); delay(500); noTone(6); //do
    tone(6, 349.23); delay(500); noTone(6); //fa
    tone(6, 329.63); delay(500); noTone(6); //mi
    tone(6, 293.66); delay(500); noTone(6); //re*/
    d=false;
  }
  
  //leer 10 high 13
  if(digitalRead(10) == HIGH){
    //este player ya jugo
    if(a==false){
      lcd.clear();
          lcd.print("Jugador 1 gano !");
        digitalWrite(13,HIGH);
          tone(6, 261.63); delay(500); noTone(6); //do
        //delay(2000);
          
        a=true;   //ya no más
        b=true;
        c=true;
    }
  } 
  
  //leer 9 high 12
  if(digitalRead(9) == HIGH){
    //ya jugó este man?
    if(b==false){
      lcd.clear();
        lcd.print("Jugador 2 gano !");
      digitalWrite(12,HIGH);
         tone(6, 261.63); delay(500); noTone(6); //do
        //delay(2000); 
        
      b=true; //ya no juega más
      c=true;
      a=true;     
    }
  }
  
  //leer 8 high 11
  if(digitalRead(8) == HIGH){
    //ya jugó este man?
    if(c==false){
      lcd.clear();
         lcd.print("Jugador 3 gano !");
      digitalWrite(11,HIGH);
         tone(6, 261.63); delay(500); noTone(6); //do
         //delay(2000);
         
      c=true; //ya no juega más
      b=true;
      a=true;
    }
  } //else {
    //digitalWrite(11,LOW);
 // }
  
  //leer 7 reset
  if(digitalRead(7) == HIGH){
    //apagar leds
    lcd.clear();
    lcd.print(" Reflejos V2.01 ");
    
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    tone(6, 349.23); delay(150); noTone(6); //fa
    digitalWrite(11,HIGH); delay(200);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH); delay(250);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH); delay(300);
    digitalWrite(13,LOW);
    //volver variables a sin jugar
    a=false;
    b=false;
    c=false;
  }
}
