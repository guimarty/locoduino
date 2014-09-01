/*
Programme pour arduino uno
Pour locoduino.org
Licence GNU GPLv3

Ce programme réalise un chenillard.
Il fait flasher successivement six LED oranges relées aux sorties 4 à 9
Puis il réalise une pause de 500 millisecondes avant de recommencer

Utilisation de 6 LED (3 couleurs au total) branchées sur les broches de 4 à 9 avec en série de chaque une résistance. L'autre coté est relié à la masse.
*/

// Initialisation des lignes 4 à 9 en sortie
void setup () {
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
  pinMode (7, OUTPUT) ;
  pinMode (8, OUTPUT) ;
  pinMode (9, OUTPUT) ;
}

// Fonction loop
void loop () {
  // Extinction de toutes les LED au départ du programme
  for (byte i = 4 ; i <= 9 ; i++) {
    digitalWrite (i, LOW) ; // éteint la LED reliée à la broche i
  }
  
  // Boucle pour faire flasher les LED
  for (byte i = 4 ; i <= 9 ; i++) {
    digitalWrite (i, HIGH) ; // allume la LED sur broche i
    delay (50) ; // durée du flash 50 millisecondes
    digitalWrite (i, LOW) ; // éteint la LED
  }
  
  // délai de 500 millisecondes
  delay (500) ;
  
  // Recommence la séquence
}