#include <Servo.h>
#include <Wire.h>
#include <RFID.h>
#include <LiquidCrystal_I2C.h>
#include <RFID.h>
#include <SPI.h>


LiquidCrystal_I2C lcd(0x27,20,4);

#define SS_PIN 53
#define RST_PIN 5
#define PinServo 12


RFID rfid(SS_PIN, RST_PIN);

bool comprobacion=false;
bool comprobacion2=false;
int numero_serie[14];
int card[]={37,170,134,229,236}; //14
int key[]={236,115,201,85,3};   //12
int pos=180;

Servo motor;

void setup() {
  Serial.begin(9600); 
  lcd.init();                       // inicializa el lcd 
  lcd.backlight();
  SPI.begin(); 
  rfid.init();
  motor.attach(12);
  motor.write(pos);
  delay(1000);

  lcd.clear();
  lcd.print("     Bienvenido! ");
}

void loop() {
  /*Serial.print(analogRead(A0)); Serial.print(" ");    //756
  delay(500);
  Serial.println(analogRead(A15)); Serial.print(" "); //53
  delay(500);*/
  
  leer_usuario();
  if( (analogRead(A15)<25) && (comprobacion==true) && (pos==180) ){
    pos=90;
    motor.write(pos);
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Es correcto");
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
  }
  if( (analogRead(A0)<600) && (comprobacion2==false) && (pos==180) ){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Es incorrecto");
    // led y buzzer
    digitalWrite(11,HIGH);
    tone(6,257.66);
    delay(1000);
    noTone(6);
    digitalWrite(11,LOW);
    lcd.clear();
    lcd.print("     Bienvenido! ");
    comprobacion=false;
    comprobacion2=false;
  }
  if( (analogRead(A0) < 600) && (comprobacion==true) && (pos==90) ){
    pos=180;
    motor.write(pos);
    delay(1000);
     
    
    lcd.clear();
    lcd.print("     Bienvenido! ");
   comprobacion=false;
    comprobacion2=false;   
  } 
  
  
  leer_usuario();
  if( (analogRead(A0)<600) && (comprobacion2==true) && (pos==180) ){
    pos=90;
    motor.write(pos);
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Es correcto");
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW); 
  }
  if( (analogRead(A15)<25) && (comprobacion==false) && (pos==180) ){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Es incorrecto");
    // led y buzzer
    digitalWrite(11,HIGH);
    tone(6,267.66);
    delay(1000);
    noTone(6);
    digitalWrite(11,LOW);
    lcd.clear();
    lcd.print("     Bienvenido! ");
    comprobacion=false;
    comprobacion2=false;
    
  }
  if( (analogRead(A15) <25) && (comprobacion2==true) && (pos==90) ){
    pos=180;
    motor.write(pos);
    delay(1000); 
   
    
    lcd.clear();
    lcd.print("     Bienvenido! ");
    comprobacion=false;
    comprobacion2=false;  
  }
}//cierre void loop

void leer_usuario(){
int contador = 0;
    if(rfid.isCard()){
           if(rfid.readCardSerial()){
                lcd.clear();
                lcd.print("Hola usuario: "); // guardamos el numero del usuario
                for(int i=0; i<=4 ; i++){
                   Serial.print(numero_serie[i] = rfid.serNum[i]);
                }
                lcd.print(" "); // esto es para que quede más bonito y el " usuario correcto " o " usuario incorrecto " aparezcan debajo y no pegados
                delay(500); // para que no se imprima constantemente el mismo numero
                contador = 1;
               comprobar_usuario();
             }
    }
    rfid.halt();
    
}

void comprobar_usuario(){
for(int i=0; i<1; i++){
   if(card[i] == numero_serie[i] && card[(i+1)] == numero_serie[(i+1)] && card[(i+2)] == numero_serie[(i+2)] && card[(i+3)] == numero_serie[(i+3)]){
     comprobacion=true;
   }else{
     
     comprobacion2=true;
   }
 }
 
 if(comprobacion==true){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Tarjeta de entrada:");
 }else{
   lcd.clear();
   
    lcd.setCursor(0,0);
    lcd.print("Llave de salida:");
   
 }
}

