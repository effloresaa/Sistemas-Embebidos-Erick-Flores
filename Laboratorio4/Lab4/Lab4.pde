import processing.serial.*;

Serial port; 
int aux;
float dato,h,w;
int i=0;
int j =0;

void setup(){
size(800,600);
background(#B3D4D6);
port= new Serial(this, "COM10",9600);
textSize(20);
fill(0);
text("MODELO DE REGRESIÓN LINEAL",260,50);
textSize(15);
text("y=1.18x-133.39",355,80);
text("PESO",15,330);
text("90",75,150);
text("80",75,195);
text("70",75,240);
text("60",75,285);
text("50",75,330);
text("40",75,375);
text("30",75,420);
text("20",75,465);
text("10",75,510);
text("ESTATURA",350,570);
text("155",75,530);
text("160",175,530);
text("165",275,530);
text("170",375,530);
text("175",475,530);
text("180",575,530);
text("185",675,530);
}

void draw (){
  stroke(0);
  strokeWeight(2);
  noFill();
  rect(100,150,600,360);    //(100,300,600,450)
  for(;i<7;i++){
      stroke(#9B9999);
      strokeWeight(1);
      line(100+(i*100),150,100+(i*100),510);
  }
  for(;j<9;j++){
      stroke(#9B9999);
      strokeWeight(1);
      line(100,150+(j*45),700,150+(j*45));
  }
  
  while(port.available()>0){
    if(aux==0){
      h=port.read();
      println("Estatura");
      println(h);
      aux++;
    }
    else if(aux==1){
      w=port.read();
      println("Peso");
      println(w);
      aux=0;
    }
    //stroke(255,0,0);
    //fill(255,0,0);
    //ellipse(100+(20*(h-155)),517-(4*w),5,5);  //h,w,5,5
  }
    stroke(#28985D);
    fill(#28985D);
    ellipse(100+(20*(h-155)),517-(4*w),5,5);  //h,w,5,5
  
  //datos de estatura y peso
  stroke(#2C268B);
  fill(#2C268B);
  ellipse(100+(20*(170-155)),517-(4*67),5,5);  //170,67,5,5
  ellipse(100+(20*(180-155)),517-(4*80),5,5);  //180,80,5,5
  ellipse(100+(20*(170-155)),517-(4*65),5,5);  //170,65,5,5
  ellipse(100+(20*(178-155)),517-(4*75),5,5);  //178,75,5,5
  ellipse(100+(20*(160-155)),517-(4*55),5,5);  //160,55,5,5
  ellipse(100+(20*(163-155)),517-(4*60),5,5);  //163,60,5,5
  ellipse(100+(20*(165-155)),517-(4*63),5,5);  //165,63,5,5
  ellipse(100+(20*(170-155)),517-(4*70),5,5);  //170,70,5,5
  ellipse(100+(20*(164-155)),517-(4*62),5,5);  //164,62,5,5
  ellipse(100+(20*(176-155)),517-(4*77),5,5);  //176,77,5,5
  ellipse(100+(20*(164-155)),517-(4*60),5,5);  //164,60,5,5
  ellipse(100+(20*(170-155)),517-(4*76),5,5);  //170,76,5,5
  ellipse(100+(20*(170-155)),517-(4*56),5,5);  //170,56,5,5
  ellipse(100+(20*(168-155)),517-(4*60),5,5);  //168,60,5,5
  //línea de tendencia
  stroke(#FF6771);
  strokeWeight(0.5);
  line(100+(20*(160-155)),517-(4*55),100+(20*(180-155)),517-(4*80));
}
