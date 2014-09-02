/*
Programme pour arduino uno
Pour locoduino.org
Version 1
Licence GNU GPLv3
Ce programme fait fonctionner des feux tricolores.
Six LED (vertes, oranges et rouge) sont reliées aux sorties 4 à  9
Les sorties 4 à 6 forment le feu A1
Les sorties 7 à 9 forment le feu B1

Utilisation de 6 LED (3 couleurs au total) branchées sur les broches de 4 à 9 avec en série de chaque une résistance. L'autre coté est relié à la masse.
*/
     
// Initialisation des variables
const byte A1V = 4 ;
const byte A1O = 5 ;
const byte A1R = 6 ;
const byte B1V = 7 ;
const byte B1O = 8 ;
const byte B1R = 9 ;
     
// Initialisation des lignes 4 à 9 en sortie
void setup () {
  pinMode (A1V, OUTPUT) ;
  pinMode (A1O, OUTPUT) ;
  pinMode (A1R, OUTPUT) ;
  pinMode (B1V, OUTPUT) ;
  pinMode (B1O, OUTPUT) ;
  pinMode (B1R, OUTPUT) ;
}
     
// Fonction loop
void loop () {
  // Extinction de toutes les LED au départ
  digitalWrite (A1V, LOW) ;
  digitalWrite (A1O, LOW) ;
  digitalWrite (A1R, LOW) ;
  digitalWrite (B1V, LOW) ;
  digitalWrite (B1O, LOW) ;
  digitalWrite (B1R, LOW) ;
     
  // Allumage de A1V et B1R
  digitalWrite (A1V, HIGH) ;
  digitalWrite (B1R, HIGH) ;
     
  // Début de cycle
   
  // Concerne le feu A1
  delay (30000) ; // Feu vert A1V pendant 30 secondes
  digitalWrite (A1V, LOW) ; // Extinction de A1V
  digitalWrite (A1O, HIGH) ; // et allumage de A1O
  delay (5000) ; //durée 5 secondes
  digitalWrite (A1O, LOW) ; // Extinction de A1O
  digitalWrite (A1R, HIGH) ; // et allumage de A1R
  delay (2000) ; // Temporisation du chauffard !
     
  // Concerne l'autre feu B1
  digitalWrite (B1R, LOW) ; // Extinction de B1R
  digitalWrite (B1V, HIGH) ; // et allumage de B1V
  delay (30000) ; // Feu vert B1V pendant 30 secondes
  digitalWrite (B1V, LOW) ; // Extinction de B1V
  digitalWrite (B1O, HIGH) ; // et allumage de B1O
  delay (5000) ; // durée 5 secondes
  digitalWrite (B1O, LOW) ; // Extinction de B1O
  digitalWrite (B1R, HIGH) ; // et allumage de B1R
  delay (2000) ; // Temporisation du chauffard !
  digitalWrite (A1V, HIGH) ; // On est revenu au point de dÃ©part
     
  // Feu A1 vert et feu B1 rouge : le cycle peut recommencer
}