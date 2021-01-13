#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <MsTimer2.h>


int on=0;
int cont=0;
//int tiempo;

//reset por líneas de programación
void(* resetFunc)(void)=0;
 
void setup() {
  
  Serial.begin(9600);
  Serial.println("MODO SLEEP");
  MsTimer2::set(1000, reloj);
  MsTimer2::start();
  //wdt_enable(WDTO_8S);
  set_sleep_mode(SLEEP_MODE_STANDBY);
  sleep_enable();

}


void loop() {
  if(cont==60)
    resetFunc();
  else
  sleep_enable();
    
}

void reloj() {
  cont++;
  power_adc_disable();
  if(cont==60){
    sleep_disable();
    power_adc_enable();
    delay(10);
    Serial.println(analogRead(0));
    cont=0;
   }
}
