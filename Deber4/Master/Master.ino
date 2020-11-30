#include <Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //RS,E,D4,D5,D6,D7

char c;
int tam; 
String dato;
String mensaje = "";

void setup() {
  Wire.begin();       //cx i2c
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("P. Codificada: ");
  lcd.setCursor(0,1);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
      Serial.println("Ingrese mensaje a codificar");
      dato=Serial.readString();
      tam=dato.length()+1;
      char p[tam];
      dato.toCharArray(p,tam);
      Wire.beginTransmission(4);
      Wire.write(p, tam);
      Serial.println(" ");
      Serial.println(String("Enviando: ")+String(p));
      Wire.endTransmission();
      delay(1000);
      Wire.requestFrom(4, tam); 
      Serial.println("Mensaje recibido:");
      while (Wire.available()) {
          c = Wire.read();
          lcd.print(c); 
          Serial.print(c);
      }
      tam=0;
    }
}
