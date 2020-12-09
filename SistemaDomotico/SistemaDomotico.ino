
#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13,12,11,10,9,8);
const int luces[4]= {7,6,5,4};
const int sensores[4]= {14,15,16,17};

int on=0;     //int 0
int cont=1;   //int 1
int i;
int j=0;
int rndm;
int segundos=0;
int minutos=0;
int horas=0;
int conversor;  // variable para cad
int conversor1; // variable para cad

int conta=0;         // variable de timer 1
//sistema randómico
int caso1=0;
int caso2=0;
int caso3=0;
int caso4=0;
int caso5=0;

void setup() {
  for(i=0;i<4;i++){
      pinMode(luces[i],OUTPUT);
      pinMode(sensores[i],INPUT);
    } 
  lcd.begin(16,2);
  Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);
  attachInterrupt(1,modos,LOW);
}

void loop() {
  if(cont==2){
    subrutina();
    }
  
  if(cont==3){
    if(horas<23){    
      conversor=analogRead(4);      //lectura del cad 0
      horas=(conversor*23)/1023;
    }
    else{
      horas=0;
    }
    if(minutos<59){
      conversor1=analogRead(5);     //lectura del cad 1  
      minutos=(conversor1*59)/1023;
    }
    else{
      minutos=0;
    }       
   }

   if(cont==3){
     checksensor();
   }
}

void activacion(){
  switch(on){
     case 0:
      Serial.println("SISTEMA ENCENDIDO");
      MsTimer2::set(1000,reloj);
      MsTimer2::start();
      on++;
     break;
     case 1:
      Serial.println("SELECCION DE MODO");
      on++;
     break;
     case 2:
      Serial.println("SISTEMA APAGADO");
      on=0;
      cont=1;
      lcd.clear();
      MsTimer2::stop();
      for(i=0;i<4;i++){
         digitalWrite(luces[i],LOW);
      }
     break;
    }
}

void modos(){
  if(on==2){
    switch(cont){
        case 1:
          Serial.println("MODO 1: ACTIVACION DE LUCES");
          cont++;
        break;
        case 2:
          Serial.println("MODO 2: CAMBIO DE HORA");     
          cont++;
        break;
        case 3:
          Serial.println("MODO 3: SISTEMA DE SEGURIDAD");
          //cont=1;
        break;
    }  
          
  }
}

void reloj(){
    if(minutos<59)
      minutos++;
    else {
      minutos=0;
      if(horas<23)
        horas++;
       else
       horas=0;
      }    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String(horas)+String(":")+String(minutos));
}

void subrutina(){
   rndm=random(0,4);
   
   digitalWrite(luces[rndm], LOW);
  conta++;
  if(conta==caso1){
    digitalWrite(luces[rndm], HIGH);
    digitalWrite(luces[rndm], HIGH);
  }
  if(conta==caso2)
    digitalWrite(luces[rndm], LOW);
  if(conta==caso3)
    digitalWrite(luces[rndm], HIGH);
    digitalWrite(luces[rndm], LOW);
  if(conta==caso4)
    digitalWrite(luces[rndm], HIGH);
  if(conta==caso5){
    digitalWrite(luces[rndm], LOW);
    caso1=random(0,13);
    caso2=random(14,20);
    caso3=random(21,27);
    caso4=random(28,35);
    caso5=random(36,41);
    conta=0; 
   } 
}

void checksensor(){
    if(digitalRead(sensores[0])==HIGH){
      Serial.println("ALERTA! Sensor 1 activado");  
      }          
    if(digitalRead(sensores[1])==HIGH){
      Serial.println("ALERTA! Sensor 2 activado");  
      }          
    if(digitalRead(sensores[2])==HIGH){
      Serial.println("ALERTA! Sensor 3 activado");  
      }          
    if(digitalRead(sensores[3])==HIGH){
      Serial.println("ALERTA! Sensor 4 activado");  
      }
  }
