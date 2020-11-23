/*
 * DEBER #1 PUERTOS DIGITALES
 * Codigo: Puetos digitales configurados como E/S
 * OBJETIVOS: Uso de switchs para la activación de juegos de luces
*/

const int ledW1=6;
const int ledW2=7;
const int ledW3=8;
const int ledW4=9;
const int ledW5=10;
const int ledW6=11;
const int ledB1=12;
const int ledB2=13;
const int ledB3=14;
const int ledB4=15;
const int ledB5=16;
const int ledB6=17;
const int sw1=2;
const int sw2=3;
const int sw3=4;
const int sw4=5;

int i=0;
int j=0;

void setup() {
  pinMode(ledW1,OUTPUT); // pin 6 como salida
  pinMode(ledW2,OUTPUT); // pin 7 como salida
  pinMode(ledW3,OUTPUT); // pin 8 como salida
  pinMode(ledW4,OUTPUT); // pin 9 como salida
  pinMode(ledW5,OUTPUT); // pin 10 como salida
  pinMode(ledW6,OUTPUT); // pin 11 como salida
  pinMode(ledB1,OUTPUT); // pin 12 como salida
  pinMode(ledB2,OUTPUT); // pin 13 como salida
  pinMode(ledB3,OUTPUT); // pin 14 como salida
  pinMode(ledB4,OUTPUT); // pin 15 como salida
  pinMode(ledB5,OUTPUT); // pin 16 como salida
  pinMode(ledB6,OUTPUT); // pin 17 como salida
  pinMode(sw1,INPUT); // pin 2 como entrada
  pinMode(sw2,INPUT); // pin 3 como entrada
  pinMode(sw3,INPUT); // pin 4 como entrada
  pinMode(sw4,INPUT); // pin 5 como entrada
}

void loop() {
  // enciende el primer juego de leds mediante la activación del switch 1
     
    if(digitalRead(sw1)==HIGH){
      while(i<10){ 
      i++;
      digitalWrite(ledW1,LOW);
      digitalWrite(ledW3,LOW);
      digitalWrite(ledW5,LOW);
      digitalWrite(ledW2,HIGH);
      digitalWrite(ledW4,HIGH);
      digitalWrite(ledW6,HIGH);
      delay(300);
      digitalWrite(ledW2,LOW);     
      digitalWrite(ledW4,LOW);            
      digitalWrite(ledW6,LOW);
      delay(300);
    }
    }
    else{
      digitalWrite(ledW1,LOW);
      digitalWrite(ledW2,LOW);
      digitalWrite(ledW3,LOW);
      digitalWrite(ledW4,LOW);
      digitalWrite(ledW5,LOW);
      digitalWrite(ledW6,LOW);
    }
      
       
    if(digitalRead(sw2)==HIGH){
      while(j<10){ 
      j++;
      digitalWrite(ledW2,LOW);
      digitalWrite(ledW4,LOW);
      digitalWrite(ledW6,LOW);
      digitalWrite(ledW1,HIGH);
      digitalWrite(ledW3,HIGH);
      digitalWrite(ledW5,HIGH);
      delay(300);
      digitalWrite(ledW1,LOW);     
      digitalWrite(ledW3,LOW);            
      digitalWrite(ledW5,LOW);
      delay(300);
    }
  }
  else{
      digitalWrite(ledW1,LOW);
      digitalWrite(ledW2,LOW);
      digitalWrite(ledW3,LOW);
      digitalWrite(ledW4,LOW);
      digitalWrite(ledW5,LOW);
      digitalWrite(ledW6,LOW);
  }
      
    if(digitalRead(sw3)==HIGH){
      digitalWrite(ledB1,HIGH);
      delay(200);
      digitalWrite(ledB1,LOW);
      delay(200);
      digitalWrite(ledB2,HIGH);
      delay(200);
      digitalWrite(ledB2,LOW);
      delay(200);
      digitalWrite(ledB3,HIGH);
      delay(200);
      digitalWrite(ledB3,LOW);
      delay(200);
      digitalWrite(ledB4,HIGH);
      delay(200);
      digitalWrite(ledB4,LOW);
      delay(200);
      digitalWrite(ledB5,HIGH);
      delay(200);
      digitalWrite(ledB5,LOW);
      delay(200);
      digitalWrite(ledB6,HIGH);
      delay(200);
      digitalWrite(ledB6,LOW);
      delay(200);     
    }
    else{
      digitalWrite(ledB1,LOW);
      digitalWrite(ledB2,LOW);
      digitalWrite(ledB3,LOW);
      digitalWrite(ledB4,LOW);
      digitalWrite(ledB5,LOW);
      digitalWrite(ledB6,LOW);
    }

    if(digitalRead(sw4)==HIGH){
      digitalWrite(ledB1,HIGH);
      delay(300);
      digitalWrite(ledB2,HIGH);
      delay(300);
      digitalWrite(ledB3,HIGH);      
      delay(300);
      digitalWrite(ledB4,HIGH);      
      delay(300);
      digitalWrite(ledB5,HIGH);      
      delay(300);
      digitalWrite(ledB6,HIGH);
      delay(300);
      digitalWrite(ledB6,LOW);
      delay(300);
      digitalWrite(ledB5,LOW);
      delay(300);
      digitalWrite(ledB4,LOW);
      delay(300);
      digitalWrite(ledB3,LOW);
      delay(300);
      digitalWrite(ledB2,LOW);
      delay(300);
      digitalWrite(ledB1,LOW);    
      delay(300);
    }
    else{
      digitalWrite(ledB1,LOW);
      digitalWrite(ledB2,LOW);
      digitalWrite(ledB3,LOW);
      digitalWrite(ledB4,LOW);
      digitalWrite(ledB5,LOW);
      digitalWrite(ledB6,LOW);
    }
}
