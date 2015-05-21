#include <RFID.h>
#include <SPI.h>
#define SS_PIN 53
#define RST_PIN 5
#define PinServo 12
int numero_serie[4];

RFID rfid(SS_PIN, RST_PIN);
int card[]={37,170,134,229,236}; //14
int  key[]={236,115,201,85,3};   //12
bool comprobacion = false;


void setup() {
  Serial.begin(9600);
  pinMode(PinServo, OUTPUT);
  SPI.begin(); 
  rfid.init();
}

void loop() {
  leer_usuario();
}


void leer_usuario()
{
int contador = 0;
    if (rfid.isCard())
    {
           if (rfid.readCardSerial())
            {
                Serial.print("Numero usuario: "); // guardamos el numero del usuario
                for(int i=0; i<=4 ; i++)
                {
                Serial.print(numero_serie[i] = rfid.serNum[i]);
                }
                Serial.println(" "); // esto es para que quede más bonito y el " usuario correcto " o " usuario incorrecto " aparezcan debajo y no pegados
                delay(500); // para que no se imprima constantemente el mismo numero
                contador = 1;
               comprobar_usuario();
             }
    }
    rfid.halt();
};

void comprobar_usuario()  // con este bucle miramos si alguno de nuestros usuarios coincide con el array rfid.serNUM ( el numero que está para comprobar)
{
for(int i=0; i<1; i++) // numero de digitos de nuestro tag
 {
   if(card[i] == numero_serie[i] && card[(i+1)] == numero_serie[(i+1)] && card[(i+2)] == numero_serie[(i+2)] && card[(i+3)] == numero_serie[(i+3)]){
     comprobacion=true;
   }else{
     comprobacion=false;
   }
 }
 
 if(comprobacion==true){
   Serial.println("Es correcto");
   digitalWrite(12,HIGH);
   delay(100);
 }else{
   Serial.println("Es incorrecto");
 }
 
}
