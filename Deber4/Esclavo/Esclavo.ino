#include <Wire.h>
char c;
int a;
String a1;
String palabra="";
char salida;
char vector[100];
int i=0;
char imp;
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}
void receiveEvent(int bytes) {
  while (Wire.available()) {;
    c = Wire.read();
    Serial.print(c);
    vector[i]=c;
    i++;
  }
  a=i;
  i=0;
  for (int j=0;j<a+1;j++) {
    imp=codificar(vector[j]);
    palabra=palabra+imp;
  }
  a1=palabra;
  palabra="";
}

void requestEvent() {
 Serial.println(" ");
 Serial.print("Mensaje codificado: ");
 Serial.print(a1);
 int tam=a1.length()+1;
 char vector1[tam];
 a1.toCharArray(vector1, tam);
 Wire.write(vector1, tam);
}

char codificar(char vocales) {
  switch (vocales) {
    case 'a':
      salida='@';
    break;
    case 'e':
      salida='#';
    break;
    case 'i':
      salida='!';
    break;
    case 'o':
      salida='*';
    break;
    case 'u':
      salida='$';
    break;
    default:
      salida=vocales;
    break;
  }
  return salida;
}
