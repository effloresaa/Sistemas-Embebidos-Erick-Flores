# include <avr/power.h>
# include <avr/sleep.h>
# include <avr/wdt.h>
# include <EEPROM.h>

int dato;
int on = 0;
//int mode=0;

void setup() {
  Serial.begin(9600);
  //EEPROM.write(0,0); // establecer valor inicial en la memoria 
  dato = EEPROM.read(0);
  opcion(dato);
  delay(1000);
  attachInterrupt(0, activacion, LOW);  
}

void loop() {
   if (on==1) {
    dato=analogRead(0); 
    dato=map(dato,0,1023,1,10);
    delay(1000); 
    EEPROM.update(0,dato);
    Serial.println(dato); 
    opcion(dato);
    delay(1000);
  }
}


void activacion() {
  switch (on) {
    case 0:
      Serial.println("ACTIVACION");
      on++;
      break;
    case 1:
      Serial.println("Elija las opciones de tiempo de configuracion de reinicio"); 
      on++;
      break;
      case 2:
      on=0;  
      break; 
  }
}
  
 void opcion(int mode) {
  switch (mode) {
    case 1:
      Serial.println("Tiempo de reinicio: 15Ms"); 
      wdt_enable(WDTO_15MS);
      delay(1000);
    break;
    case 2:
      Serial.println("Tiempo de reinicio: 30Ms");
      wdt_enable(WDTO_30MS);
    break;
    case 3:
      Serial.println("Tiempo de reinicio: 60Ms");
      wdt_enable(WDTO_60MS);
    break;
    case 4:
      Serial.println("Tiempo de reinicio: 120Ms");
      wdt_enable(WDTO_120MS);
    break;
    case 5:
      Serial.println("Tiempo de reinicio: 250Ms");
      wdt_enable(WDTO_250MS);
    break;
    case 6:
      Serial.println("Tiempo de reinicio: 500Ms");
      wdt_enable(WDTO_500MS);
    break;
    case 7:
      Serial.println("Tiempo de reinicio: 1S");
      wdt_enable(WDTO_1S);
    break;
    case 8:
      Serial.println("Tiempo de reinicio: 2S");
      wdt_enable(WDTO_2S);
    break;
    case 9:
      Serial.println("Tiempo de reinicio: 4S");
      wdt_enable(WDTO_4S);
    break;
    case 10:
      Serial.println("Tiempo de reinicio: 8S");
      wdt_enable(WDTO_8S);
    break;
  }
}
