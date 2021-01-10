
int x=100;
int y=100;

void setup() {
  size(600,600);   //(ancho,alto)
  background(#96C9B6);    //color de fondo RGB #96C9B6
}

void draw() {
  move_keyboard();
}

void move_keyboard() {
  fill(#F06F7A);
  ellipse(x,y,100,100);
  if(keyPressed){
    switch(keyCode){
    case 37:    //izquierda
      background(#96C9B6);
      x-=2;
    break;
    case 38:    //arriba
      background(#96C9B6);
      y-=2; 
    break;
    case 39:    //derecha
      background(#96C9B6);
      x+=2;
    break;
    case 40:    //abajo
      background(#96C9B6);
      y+=2;
    break;
    }
  
  }
}
