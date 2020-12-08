#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13,12,11,10,9,8);
const int alarma =7;  // led de alarma en pin 7

int segundos=0;
int minutos=0;
int horas=0;
int on=0;
String dato;
int valor;
int alm=1;
int alh=0;

void setup() {
  lcd.begin(16,2);
  pinMode(alarma,OUTPUT);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  attachInterrupt(0,hora,LOW);
  attachInterrupt(1,minuto,LOW);
  Serial.begin(9600);
  Serial.println("Ingrese la hora de alarma(MM-HH): ");

}

void loop() {
  if(Serial.available()>0){
    switch(on){
      case 0:
        dato=Serial.readString();
        valor=dato.toInt();
        alm=valor;
        on++;
      break;
       case 1:
         dato=Serial.readString();
         valor=dato.toInt();
         alh=valor;
         on=0;
       break;
      }
   }
   activacion();
}

void activacion(){
    if(horas==alh && minutos==alm){
        digitalWrite(alarma,HIGH);
     }
     else {
        digitalWrite(alarma,LOW);
      }  
}

void hora(){
    if(horas<23)
      horas++;
    else 
    horas=0;
}

void minuto(){
    if(minutos<59)
      minutos++;
    else 
    minutos=0;
}

void reloj(){
if(segundos<59)  
  segundos++;
  else{
    segundos=0;
    if(minutos<59)
      minutos++;
    else {
      minutos=0;
      if(horas<23)
        horas++;
       else
       horas=0;
      }
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
    lcd.setCursor(0,1);
    lcd.print(String("Alarma: ")+String(alh)+String(":")+String(alm));
}
