
#include<LiquidCrystal.h> //Incluimos la libreria LiquidCrystal
 
LiquidCrystal lcd(13,12,11,10,9,8);  // RS,E,D4,D5,D6,D7

String dato; // variable de recepción de strings
String psswd1="ad970323";   //Define Password 1 de Erick Flores
String psswd2="ca900813";   //Define Password 2 de Carlos Arias
String psswd3="aj881112";   //Define Password 3 de Andrés Juárez
String psswd4="ja890109";   //Define Password 4 de Javier Andrade
String rg;
String registro;
String pswd[100];
const int btn=7;
int i=0; 
int j=0;

void setup(){
  Serial.begin(9600);
  pinMode(btn,INPUT); // pin 7 como entrada
}

void loop(){
if(digitalRead(btn)==LOW){
  if(Serial.available()>0){
      dato=Serial.readString();   // lee el dato
      dato.toLowerCase();         //conversión a minúsculas
      pswd[i]=dato;
      i++;
      checkPassword(dato);        //validación de contraseñas      
  }
     
  lcd.setCursor(16,1);
  lcd.autoscroll();
  lcd.print(" ");
  delay(100);
}

  
  if(digitalRead(btn)==HIGH){
    delay(300);
        Serial.println("Registro de ingresos:");
          for(;j<i;j++){
          if(pswd[j]==psswd1){
            i++;
            Serial.println("Erick Flores ha ingresado");
            }
          else {
            Serial.println("Erick Flores no ha ingresado");
            }
          if(pswd[j]==psswd2){
            Serial.println("Carlos Arias ha ingresado");
            }
          else {
            Serial.println("Carlos Arias no ha ingresado");
            }          
          if(pswd[j]==psswd3){
            Serial.println("Andres Juarez ha ingresado");
            }
          else{
            Serial.println("Andres Juarez no ha ingresado");
            } 
          if(pswd[j]==psswd4){
            Serial.println("Javier Andrade ha ingresado");
            }
          else{
            Serial.println("Javier Andrade no ha ingresado");
            }
          }          
  }
}


void checkPassword (String dato){
  if(dato==psswd1){
          Serial.println(" ");
          Serial.println("Ingreso correcto ");
          lcd.begin(16,2);
          lcd.clear();
          lcd.setCursor(15,0);
          lcd.print("BIENVENIDO ERICK FLORES");
      }
      else if(dato==psswd2){
          Serial.println(" ");
          Serial.println("Ingreso correcto ");
          lcd.begin(16,2);
          lcd.clear();
          lcd.setCursor(15,0);
          lcd.print("BIENVENIDO CARLOS ARIAS");
          
      }
      else if(dato==psswd3){
          Serial.println(" ");
          Serial.println("Ingreso correcto ");
          lcd.begin(16,2);
          lcd.clear();
          lcd.setCursor(15,0);
          lcd.print("BIENVENIDO ANDRES JUAREZ");
      }
      else if(dato==psswd4){
          Serial.println(" ");
          Serial.println("Ingreso correcto ");
          lcd.begin(16,2);
          lcd.clear();
          lcd.setCursor(15,0);
          lcd.print("BIENVENIDO JAVIER ANDRADE");
      }  
      else{
        Serial.println(" ");
        Serial.println("Error..! Ingrese nuevamente el codigo");
        Serial.println(" ");
          Serial.println("Ingreso correcto ");
          lcd.begin(16,2);
          lcd.clear();
          lcd.setCursor(15,0);
          lcd.print("CONTRASEÑA INCORRECTA");
        }
  }
