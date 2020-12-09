#include <EEPROM.h>

int psswd=4563;
int updtpsswd;
String dato;

void setup() {
  Serial.begin(9600);
  EEPROM.get(0,updtpsswd);
  if(updtpsswd!=psswd && psswd>0){
    psswd=updtpsswd;
  }
}

void loop() {
  updtpsswd=password();
  EEPROM.put(0,updtpsswd);
  psswd=updtpsswd;
  Serial.println(psswd);
}

int password(void){
  int pass;
  if(Serial.available()>0){
    dato=Serial.readString();
    pass=dato.toInt();
    }
  else {
      pass=psswd; 
  }
  return(pass);
}
