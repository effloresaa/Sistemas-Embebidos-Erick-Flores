/*
 * DEBER #2 PUERTOS DIGITALES
 * Codigo: manejo de display de 7 segmentos decodificador 7447
 * OBJETIVOS: Representar los números primos hasta el 99
*/

const int A=8; //decodificador
const int B=9; //decodificador
const int C=10; //decodificador
const int D=11; //decodificador
const int btn=7; 
const int unidades=12;
const int decenas=13;
int uni=0;
int dec=0;
int cont=0;

void setup() {
  pinMode(A,OUTPUT); // pin 8 como salida
  pinMode(B,OUTPUT); // pin 9 como salida
  pinMode(C,OUTPUT); // pin 10 como salida
  pinMode(D,OUTPUT); // pin 11 como salida
  pinMode(btn,INPUT); // pin 7 como entrada
  pinMode(unidades,OUTPUT); // pin 12 como salida
  pinMode(decenas,OUTPUT); // pin 13 como salida
}

void loop() {
    if(digitalRead(btn)==HIGH){
        delay(300); 
        for (byte cont=1; cont<99; cont++){ //contador hasta el número 99
              bool primo=true;
              for (byte i=2;i<cont;i++){ 
                    if(cont%i ==0){ // condición de ser divisible y si el resto es igual a 0
                        primo=false;
                      }
                   }
              if(cont<10)
                uni=cont;
              else{
                dec=cont/10;
                uni=cont-dec*10;
                }
        
        if(primo){
          //Aquí se imprimen los números primos
          digitalWrite(unidades,HIGH);
          digitalWrite(decenas,LOW);
          contador(uni);
          delay(300);
          digitalWrite(unidades,LOW);
          digitalWrite(decenas,HIGH);
          contador(dec);
          delay(300);     
        }
    }
  }
}


void contador (int j){
  switch(j){
    case 0:
          digitalWrite(A,LOW);
          digitalWrite(B,LOW);
          digitalWrite(C,LOW);
          digitalWrite(D,LOW);
        break;
        case 1:
          digitalWrite(A,HIGH);
          digitalWrite(B,LOW);
          digitalWrite(C,LOW);
          digitalWrite(D,LOW);
        break;
        case 2:
          digitalWrite(A,LOW);
          digitalWrite(B,HIGH);
          digitalWrite(C,LOW);
          digitalWrite(D,LOW);
        break;
        case 3:
          digitalWrite(A,HIGH);
          digitalWrite(B,HIGH);
          digitalWrite(C,LOW);
          digitalWrite(D,LOW);
        break;
        case 4:
          digitalWrite(A,LOW);
          digitalWrite(B,LOW);
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);
        break;
        case 5:
          digitalWrite(A,HIGH);
          digitalWrite(B,LOW);
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);
        break;
        case 6:
          digitalWrite(A,LOW);
          digitalWrite(B,HIGH);
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);
        break;
        case 7:
          digitalWrite(A,HIGH);
          digitalWrite(B,HIGH);
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);
        break;
        case 8:
          digitalWrite(A,LOW);
          digitalWrite(B,LOW);
          digitalWrite(C,LOW);
          digitalWrite(D,HIGH);
        break;
        case 9:
          digitalWrite(A,HIGH);
          digitalWrite(B,LOW);
          digitalWrite(C,LOW);
          digitalWrite(D,HIGH);
        break;   
}    
  
}
