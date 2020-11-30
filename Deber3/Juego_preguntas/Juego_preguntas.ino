/*
 * DEBER #3 COMUNICACION SERIAL
 * OBJETIVOS: 
 *            Elegir una respuesta si/no 
 *            Visualizar el puntaje de aciertos en un display *          
*/

const int A=8; //decodificador
const int B=9; //decodificador
const int C=10; //decodificador
const int D=11; //decodificador

String answer;
int randomN;
int i=0;
int j;
int k;
int score=0;
int cont=0;
String resp;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  Serial.begin(9600);
  Serial.println("Preguntas: Si/No");
  Serial.println("Presione cualquier letra");
}

void loop() {
   if(Serial.available()>0){
    delay(200);
      if(cont<5){
        randomN=random(0,8);
        i=randomN;
        questions(i);
        delay(200);
        answer=Serial.readString(); 
        answer.toLowerCase(); 
        checkanswer(i, answer);
        cont++;
        }           
        contador(score); 
        cont=0; 
     }
        
}

void questions (int i){
  switch(i){
    case 1:
      Serial.println(" ");
      Serial.println("La cartografia es la ciencia que estudia los mapas?");
      break;
    case 2:
      Serial.println(" ");
      Serial.println("La capital de Ecuador es Quito?");
      break;
    case 3:
      Serial.println(" ");
      Serial.println("El cobre fue el primer metal usado por el ser humano?");
      break;
    case 4:
      Serial.println(" ");
      Serial.println("La segunda guerra mundial comenzo en 1911?");
    case 5:
      Serial.println(" ");
      Serial.println("La bateria es un dispositivo de almacenamiento?");
      break;
    case 6:
      Serial.println(" ");
      Serial.println("Brasil gano el mundial del 2014?");
      break;
    case 7:
      Serial.println(" ");
      Serial.println("La campana de Gauss se usa en el calculo de probabilidades?" );
      break;
    case 8:
      Serial.println(" ");
      Serial.println("Los primeros amplificadores fueron hechos con transistores?");
      break;
    }
  }
  void checkanswer(int k , String resp) {
   switch (k) {
    case 1:
      resp="si";
      break;
    case 2:
      resp="si";
      break;
    case 3:
      resp="si";
      break;
    case 4:
      resp="no";
      break;
    case 5:
      resp="si";
      break;
    case 6:
      resp="no";
      break;
    case 7:
      resp="si";
      break;
    case 8:
      resp="no";
      break;
  }
  if (answer == resp) {
    score=score+1;
  }    
  return score;
}
  
void contador (int j) {
  switch (j) {
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    case 4:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
  }
}
