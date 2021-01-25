#import "datos.h"
#import "datosPrueba.h"

#include <ListLib.h>
List <int> list;

void setup() {
  Serial.begin(9600);

}

void loop() {
  Bayes(0.27);
}

void Bayes(double r) {
  double dist[100][2];
  double distancia;
  double numDatos1 = 0;
  double numDatos2 = 0;
  double prob1; 
  double prob2; 
  double distMayor = 0;
  
  int eti1 = 0;
  int eti2 = 0;
  double p_x = 0;
  for (int i = 0; i < 100; i++) {
    if (lectura[i][2] == 1) {
      numDatos1++;
    } if (lectura[i][2] == 2) {
      numDatos2++;
    }
  }
  //Serial.println(String(numDatos1)+String(",")+String(numDatos2));
  for (int j = 0; j < 30; j++) {
    for (int i = 0; i < 100; i++) {
      distancia = sqrt(pow(dtPrueba[j][0] - lectura[i][0], 2) + pow(dtPrueba[j][1] - lectura[i][1], 2));
      dist[i][0] = i;
      dist[i][1] = distancia;
    }
    // busco distancia mayor
    for (int n = 0; n < 100; n++) {
      if (dist[n][1] > distMayor) {
        distMayor = dist[n][1];
      }
    }//Normalizar distancias de la matriz
    for (int m = 0; m < 100; m++) {
      dist[m][1] = dist[m][1] / distMayor;
      if (dist[m][1] < r) {
        list.Add(m);
      }
    }
    for (int g = 0; g < list.Count(); g++) {
      if (lectura[list[g]][2] == 1) {
        eti1++;
      } else if (lectura[list[g]][2] == 2) {
        eti2++;
      }

    }
    p_x = double(list.Count()) / double(100);
    //Serial.println(eti2);
     prob1 = ((numDatos1 / 100) * (eti1 / numDatos1)) / p_x;
     prob2 = ((numDatos2 / 100) * (eti2 / numDatos2)) / p_x;
   // Serial.println(double(numDatos1/100));
    if (prob1 > prob2) {
      Serial.println(String(j) + String(".") + String("{") + String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(1) + String("},"));
    }
    if (prob2 > prob1) {
      Serial.println(String(j) + String(".") + String("{") + String(dtPrueba[j][0]) + String(",") + String(dtPrueba[j][1]) + String(",") + String(2) + String("},"));
    }
    list.Clear();
    eti1 = 0;
    eti2 = 0;
    prob1=0; 
    prob2=0; 
  }
}
