/*Pour trouver les bons angles pour gérer une aiguille avec un servo-moteur et arduino
Attention le servo doit à 90° être situé dans l'intervalle de l'aiguille au risque sinon de tout casser
Assurez vous donc quand vous le placez d'être à 90° et après vous pourrez chercher les angles adéquats
*/

import processing.serial.*;

int angle = 1500;
boolean x = false;
Serial myport;

void setup(){
  myport = new Serial(this, "/dev/ttyUSB0", 9600);
  size(300,300);
  background(255);
  stroke(0); 
  
  //Texte d'explications
  fill(0);
  
  text("Programme pour trouver les angles du servo", 15, 15);
  text("pour Arduino", 15, 30);
  text("Lisez tout d'abord les recommandations", 15, 60);
  text("dans le README", 15, 75);
  text("Assurez-vous surtout que le servo a un", 15, 90);
  text("angle de 90° après pose !", 15, 105);
  text("Cliquez pour changer les angles", 15, 135);
  text("et trouver les bons", 15, 150);
  text("Presser c pour continuer", 15, 180);
  
}

void draw(){
  if(key == 'c' || x == true){
    x = true;
    background(255);
    
    //Texte de mise en place du prog
    text("Trouvez les angles du servo", 75, 15);
    text(angle, 130, 60);
    noFill();
    rect(15, 85, 100, 100);
    rect(15, 190, 100, 100);
    rect(150, 85, 100, 100);
    rect(150, 190, 100, 100);
    text("-10", 55, 135);
    text("-1", 55, 240);
    text("+10", 190, 135);
    text("+1", 190, 240);
  } 
}

void mousePressed(){
  //rectangle de -10 et commande par z
  if(mouseX>15 && mouseX<115 && mouseY>85 && mouseY<185){
    angle = angle-10;
    myport.write('z');
  }
  
  //rectangle de -1 et commande par r
  if(mouseX>15 && mouseX<115 && mouseY>190 && mouseY<290){
    angle = angle-1;
    myport.write('r');
  }
  
  //rectangle de +10 et commande par a
  if(mouseX>150 && mouseX<250 && mouseY>85 && mouseY<185){
    angle = angle+10;
    myport.write('a');
  }
  
  //rectangle de +1 et commande par e
  if(mouseX>150 && mouseX<250 && mouseY>190 && mouseY<290){
    angle = angle+1;
    myport.write('e');
  }
}


