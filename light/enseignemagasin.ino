/*
Programme pour arduino uno
Pour locoduino.org
Licence GNU GPLv3
Ce programme réalise le clignotement d'une enseigne publicitaire.
Il fait clignoter selon un certain rythme six LED reliées aux sorties 4 à 9.
Il utilise des fonctions pour alterner les rythmes.

Utilisation de 6 LED branchées sur les broches de 4 à 9 avec en série de chaque une résistance. L'autre coté est relié à la masse.
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
  for (byte i = 4 ; i <= 9 ; i++) 
  {
    digitalWrite (i, LOW) ; // Ã©teint la LED reliée Ã  la broche i
  }
  
  // Séquence N°1 ; chenillard
  sequence_Un () ;
  delay (500) ; //délai de 500 millisecondes
  // Séquence N° 2 : cumul sur la gauche du mouvement de LED
  sequence_Deux () ;
  delay (500) ;  // délai de 500 millisecondes
  
  // Séquence N°3 : clignotement de l'ensemble 3 fois
  sequence_Trois () ;
  delay (2000) ;  // délai de 2 secondes
  // Séquence 4 : extinction successive de la gauche vers la droite
  sequence_Quatre () ;
  delay (2000) ; 
  
  // Recommence la séquence
}
void sequence_Un ()
{
  // Séquence N°1 ; chenillard
  
  for (byte n = 0 ; n <= 2 ; n++)
  {
    for (byte i = 4 ; i <= 9 ; i++)
    {
      digitalWrite (i, HIGH) ;    // allume la LED sur broche i
      delay (100) ;               // durée du flash 150 millisecondes
      digitalWrite (i, LOW) ;     // éteint la LED
      delay (50) ;
    }
  }
}
void sequence_Deux ()
{
  // Séquence NÂ° 2 : cumul sur la gauche du mouvement de LED
  
  for (byte n = 0 ; n <= 5 ; n++)
  {
    for (byte i = 4 ; i <= (9-n) ; i++)
    {
      digitalWrite (i, HIGH) ; // allume la LED sur broche i
      delay (150) ; // durée du flash 150 millisecondes
      digitalWrite (i, LOW) ; // Ã©teint la LED
    }
    digitalWrite ( (9 - n) , HIGH ) ; //dernière LED reste allumÃ©e
  }
}
void sequence_Trois ()
{
  // Séquence NÂ°3 : clignotement de l'ensemble 3 fois
  
  for (byte j = 1 ; j <= 3 ; j++) 
  {
    for (byte k = 4 ; k <= 9 ; k++) 
    {
      digitalWrite (k , LOW) ;
    }
    delay (500) ;
    for (byte l = 4 ; l <= 9 ; l++) 
    {
      digitalWrite (l, HIGH) ;
    }
    delay (500) ;
  }
}
void sequence_Quatre ()
{
  // Séquence 4 : extinction successive de la gauche vers la droite
  
  for (byte i = 9 ; i >= 4 ; i--) 
  {
    digitalWrite (i, LOW) ;
    delay (150);
  }
}