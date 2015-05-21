
void setup(){
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
   int evaluacion = analogRead(0);
   
   Serial.println(evaluacion);
   delay(10);
   
   if(analogRead(0) > 265 && analogRead(0) < 270){
     digitalWrite(13,HIGH);
     delay(2000);
   }else{
     digitalWrite(13,LOW);
   }
}
