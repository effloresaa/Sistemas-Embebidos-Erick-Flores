#include <Servo.h>

int on=0;     //int 0
Servo servo;   // objeto para servo 1
String dato;
int giro;

void setup() {
   Serial.begin(9600);
   attachInterrupt(0,activacion,LOW);

}

void loop() {
  if(on==2){
      if(Serial.available()>0){
      dato=Serial.readString();           // recibe dato en string
      giro=dato.toInt();                  // conversión a int
    }
    if(giro<180)
      servo.write(giro);
      else{
      Serial.println("dato erroneo");
      giro=0;}
    delay(20);
    }
}

void activacion(){
  switch(on){
     case 0:
      servo.attach(5);
      Serial.println("INICIO DE SISTEMA");
      on++;
     break;
     case 1:
      Serial.println("GIRO DE MOTOR");
      Serial.println("Ingrese valor del 0 al 180");
      on++;
     break;
     case 2:
      Serial.println("");
      Serial.println("SISTEMA APAGADO");
      on=0;
     break;
    }
}
