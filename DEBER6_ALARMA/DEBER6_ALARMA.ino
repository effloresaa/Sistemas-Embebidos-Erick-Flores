const int A=8; //decodificador
const int B=9; //decodificador
const int C=10; //decodificador
const int D=11; //decodificador
const int Ah=2; //decodificador
const int Bh=3; //decodificador
const int Ch=4; //decodificador
const int Dh=5; //decodificador
const int alarma =14;

const int unidades=12;
const int decenas=13;
const int unidades1=6;
const int decenas1=7;
int uni=0;
int dec=0;
int uni1=0;
int dec1=0;
int minutos=0;
int segundos=0;
int horas=0;
int on=0;
String dato;
int valor;
int alm=1;
int alh=0;

void setup() {
  pinMode(alarma,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  pinMode(Ah,OUTPUT);
  pinMode(Bh,OUTPUT);
  pinMode(Ch,OUTPUT);
  pinMode(Dh,OUTPUT);
  pinMode(unidades1,OUTPUT);
  pinMode(decenas1,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ingrese la hora de alarma(MM-HH): ");

}

void loop() {
  if(segundos<59)
    segundos++;
    else {
      segundos=0;
      if(minutos<59){
        minutos++;
        if(minutos<10)
          uni=minutos;
          else{
            dec=minutos/10;
            uni=minutos-dec*10;
            }
       }
       else{
        dec=0;
        minutos=0;
        if(horas<23){
          horas++;
          if(horas<10)
            uni1=horas;
            else{
              dec1=horas/10;
              uni1=horas-dec1*10;
              }
          }
          else{
            dec1=0;
            horas=0;
            }
       }
         digitalWrite(unidades1,HIGH);
         digitalWrite(decenas1,LOW);
         contador1(uni1);
         delay(200);
         digitalWrite(unidades1,LOW);
         digitalWrite(decenas1,HIGH);
         contador1(dec1);
         delay(200);
       
    }
    digitalWrite(unidades,HIGH);
    digitalWrite(decenas,LOW);
    contador(uni);
    delay(200);
    digitalWrite(unidades,LOW);
    digitalWrite(decenas,HIGH);
    contador(dec);
    delay(200);

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

void contador (int i){
  switch(i){
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

void contador1 (int j){
  switch(j){
    case 0:
          digitalWrite(Ah,LOW);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,LOW);
        break;
        case 1:
          digitalWrite(Ah,HIGH);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,LOW);
        break;
        case 2:
          digitalWrite(Ah,LOW);
          digitalWrite(Bh,HIGH);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,LOW);
        break;
        case 3:
          digitalWrite(Ah,HIGH);
          digitalWrite(Bh,HIGH);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,LOW);
        break;
        case 4:
          digitalWrite(Ah,LOW);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,HIGH);
          digitalWrite(Dh,LOW);
        break;
        case 5:
          digitalWrite(Ah,HIGH);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,HIGH);
          digitalWrite(Dh,LOW);
        break;
        case 6:
          digitalWrite(Ah,LOW);
          digitalWrite(Bh,HIGH);
          digitalWrite(Ch,HIGH);
          digitalWrite(Dh,LOW);
        break;
        case 7:
          digitalWrite(Ah,HIGH);
          digitalWrite(Bh,HIGH);
          digitalWrite(Ch,HIGH);
          digitalWrite(Dh,LOW);
        break;
        case 8:
          digitalWrite(Ah,LOW);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,HIGH);
        break;
        case 9:
          digitalWrite(Ah,HIGH);
          digitalWrite(Bh,LOW);
          digitalWrite(Ch,LOW);
          digitalWrite(Dh,HIGH);
        break;   
}    
  
}
