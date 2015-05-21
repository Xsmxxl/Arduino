char entradaDatoTeclado;

void setup(){
  Serial.begin(9600);
}

void loop(){
  entradaDatoTeclado = Serial.read();
  
  switch(entradaDatoTeclado){ //Inicio del switch
    
    case 'q':
    analogWrite(11,25);
    delay(150);
    analogWrite(11,24);
    delay(300);
    break;
    
    case 'w':
    analogWrite(11,50);
    delay(150);
    analogWrite(11,49);
    delay(300);
    break;
    
    case 'e':
    analogWrite(11,75);
    delay(150);
    analogWrite(11,74);
    delay(300);
    break;
    
    case 'r':
    analogWrite(11,100);
    delay(150);
    analogWrite(11,99);
    delay(300);
    break;
    
    case 't':
    analogWrite(11,125);
    delay(150);
    analogWrite(11,124);
    delay(300);
    break;
    
    case 'y':
    analogWrite(11,150);
    delay(150);
    analogWrite(11,149);
    delay(300);
    break;
    
    case 'u':
    analogWrite(11,25);
    delay(150);
    analogWrite(11,24);
    delay(300);
    break;
    
    case 'i':
    analogWrite(11,175);
    delay(150);
    analogWrite(11,174);
    delay(300);
    break;
    
    case 'o':
    analogWrite(11,200);
    delay(150);
    analogWrite(11,199);
    delay(300);
    break;
    
    case 'p':
    analogWrite(11,225);
    delay(150);
    analogWrite(11,224);
    delay(300);
    break;
    
    case 'a':
    analogWrite(11,230);
    delay(150);
    analogWrite(11,229);
    delay(300);
    break;
    
    case 's':
    analogWrite(11,235);
    delay(150);
    analogWrite(11,234);
    delay(300);
    break;
    
    case 'd':
    analogWrite(11,240);
    delay(150);
    analogWrite(11,239);
    delay(300);
    break;
    
    case 'f':
    analogWrite(11,245);
    delay(150);
    analogWrite(11,244);
    delay(300);
    break;
    
    case 'g':
    analogWrite(11,250);
    delay(150);
    analogWrite(11,249);
    delay(300);
    break;
    
    default:
      analogWrite(11,0);q
    break;
  } //Fin del switch
  
}
