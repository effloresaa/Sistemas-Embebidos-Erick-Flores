int matriz[14][2]={
{170,67},
{180,80},
{170,65},
{178,75},
{160,55},
{163,60},
{165,63},
{170,70},
{164,62},
{176,77},
{164,60},
{170,76},
{170,56},
{168,60},
};

int col=0;    //moverse en columnas
int fil=0;    //moverse en fila
int Ex=0;     //sumatoria de x
float Ey1=0;     //sumatoria de y' donde y'=ln(y)
float Exy1=0;   //sumatoria de xy'
long int Ex2=0;   //sumatoria de x^2
long int Ex_2=0;  //(Ex)^2
int n=14;         //tam de muestras
float Bo;         //ordenada en el origen
String dato;      //recibir estatura
int estatura;     //convertir dato
float peso;     
float Ai;         //A'=ln(A)
float A;
float aux;
float nB;     //auxiliar de B
float nD;     //auxiliar de B

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
      Ex=Ex+matriz[fil][0];
      Ey1=Ey1+log(matriz[fil][1]);
      Exy1=Exy1+(matriz[fil][0]*log(matriz[fil][1]));
      Ex2=Ex2+pow(matriz[fil][0],2);
     }
   Ex_2=pow(Ex,2);
   //para la regresión exponencial B=(n(Exy')-Ex*Ey')/nEx^2-(Ex)^2
   nB=(n*Exy1)-(Ex*Ey1);
   nD=(n*Ex2-Ex_2);
   Bo=float(nB/nD);
   //Para la regresion exponencial se usa el modelo y=A*e^Bx
   //A=e^A' porque -> A'=ln(A)
   //A'= (Ey'/n)-B*(Ex/n)
   Ai=float(Ey1/n)-float(Bo*(Ex/n));
   A=exp(Ai);
   Serial.println("El modelo es: ");
   Serial.println(String("y= ")+String(A)+String(" * e^")+String(Bo)+String("x"));
   Serial.println("Ingrese su estatura: ");

}

void loop() {
  if(Serial.available()>0){
      dato=Serial.readString();
      estatura=dato.toFloat();
      aux=Bo*estatura;
      peso=A*exp(aux);
      Serial.println(" ");
      Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
      Serial.println("Ingrese su estatura: ");
    }

}
