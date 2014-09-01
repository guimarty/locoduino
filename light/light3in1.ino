/*-------------------------------------------------------
Programme pour arduino uno
Pour locoduino.org
Licence GNU GPLv3

Multi-anim lumineuses
Ce programme fait fonctionner une enseigne lumineuse,
un chenillard et des feux tricolores, en même temps.
Six LED rouges sont reliées aux sorties 2 à 7 et 
forment l'enseigne.
Six LED jaunes sont reliées aux sorties 8 à 13 et
forment le chenillard.
Les sorties analogiques sont utilisées comme sorties 
numériques et sont numérotées 14 à 19.
Les sorties 14 à 16 forment le feu A1.
Les sorties 17 à 19 forment le feu B1.
T2 est la durée d'un flash du chenillard en ms.
La durée du chenillard est 6 fois T2 en ms.
Pour que le chenillard soit déclenché toutes les secondes, 
il faut que (T1 + 6 fois T2) soit égal à 1000 ms
En jouant sur T1 et/ou T2, on dynamise le rythme
Par exemple, pour T1 = 700 et T2 = 50, on a :
Vert : 22 secondes
Orange : 4 secondes
Rouge : 27 secondes (car temporisation du chauffard 1 sec)

Ne pas oublier les résistances.
--------------------------------------------------------*/
// Initialisation des variables
const byte A1V = 14 ;
const byte A1O = 15 ;
const byte A1R = 16 ;
const byte B1V = 17 ;
const byte B1O = 18 ;
const byte B1R = 19 ;
const int T1 = 700 ; // Fixe le rythme de déclenchement du chenillard
const int T2 = 50 ; // Durée du flash du chenillard
// T1 + 6 fois T2 doit être égal à 1000 !
void setup ()
{
  // Initialisation de toutes les lignes en sortie
  for (byte i = 2 ; i <= 19 ; i++)
  {
    pinMode (i, OUTPUT) ;
  }
  
  // Extinction de toutes les LED au départ
  for (byte j = 2 ; j <= 19 ; j++)
  {
    digitalWrite (j, LOW) ;
  }
  
  // Allumage de A1V et B1R
  digitalWrite (A1V, HIGH) ;
  digitalWrite (B1R, HIGH) ;
  
}
// Fonction loop
void loop ()
{
  // Début de cycle ; le feu A1 est vert et le feu B1 est rouge
  // L'enseigne cumule vers la gauche
  for (byte n = 0 ; n <= 5 ; n++)
  {
    for (byte m = 2 ; m <= (7 - n) ; m++)
    {
      digitalWrite (m, HIGH) ;
      delay (T1) ;
      chenillard () ;
      digitalWrite (m, LOW) ;
    }
    digitalWrite ((7 - n), HIGH) ;
  }
  delay (T1) ;
  chenillard () ;
  // On est à 22 secondes
  // Feu A1 passe à orange
  digitalWrite (A1V, LOW) ;
  digitalWrite (A1O, HIGH) ;
  // Enseigne clignote dans sa totalité deux fois
  for (byte j = 1 ; j <= 2 ; j++)
  {
    for (byte k = 2 ; k <= 7 ; k++)
    {
      digitalWrite (k, LOW) ;
    }
    delay (T1) ;
    chenillard () ;
    for (byte l = 2 ; l <= 7 ; l++)
    {
      digitalWrite (l, HIGH) ;
    }
    delay (T1) ;
    chenillard () ;
  }
  // On est à quatre secondes
  // Feu A1 passe au rouge
  digitalWrite (A1O, LOW) ;
  digitalWrite (A1R, HIGH) ;
  // Enseigne s'éteint de la gauche vers la droite
  // Le temps nécessaire pour cela constitue la temporisation du chauffard
  for (byte i = 7 ; i >= 2 ; i--)
  {
    digitalWrite (i, LOW) ;
    delay (T1/6) ;
  }
  chenillard () ;
  // On est à une seconde, le rouge a donc duré 22 + 4 + 1 = 25 sec
  // Feu B1 passe au vert
  digitalWrite (B1R, LOW) ;
  digitalWrite (B1V, HIGH) ;
  // Le feu A1 est rouge et le feu B1 est vert
  // L'enseigne cumule vers la gauche
  for (byte n = 0 ; n <= 5 ; n++)
  {
    for (byte m = 2 ; m <= (7 - n) ; m++)
    {
      digitalWrite (m, HIGH) ;
      delay (T1) ;
      chenillard () ;
      digitalWrite (m, LOW) ;
    }
    digitalWrite ((7 - n), HIGH) ;
  }
  delay (T1) ;
  chenillard () ;
  // Feu B1 passe à l'orange
  digitalWrite (B1V, LOW) ;
  digitalWrite (B1O, HIGH) ;
  // Enseigne clignote dans sa totalité deux fois
  for (byte j = 1 ; j <= 2 ; j++)
  {
    for (byte k = 2 ; k <= 7 ; k++)
    {
      digitalWrite (k, LOW) ;
    }
    delay (T1) ;
    chenillard () ;
    for (byte l = 2 ; l <= 7 ; l++)
    {
      digitalWrite (l, HIGH) ;
    }
    delay (T1) ;
    chenillard () ;
  }
  // Feu B1 passe au rouge
  digitalWrite (B1O, LOW) ;
  digitalWrite (B1R, HIGH) ;
  // Enseigne s'éteint de la gauche vers la droite
  // Le temps nécessaire pour cela constitue la temporisation du chauffard
  for (byte i = 7 ; i >= 2 ; i--)
  {
    digitalWrite (i, LOW) ;
    delay (T1/6) ;
  }
  chenillard () ;
  // Feu A1 passe au vert
  digitalWrite (A1R, LOW) ;
  digitalWrite (A1V, HIGH) ;
  // Le feu A1 est vert, le feu B1 est rouge, le cycle peut recommencer
}
  
void chenillard ()
{
  // Boucle pour faire flasher les LED du chenillard, durée 300 ms
  for (byte i = 8 ; i <= 13 ; i++)
  {
    digitalWrite (i, HIGH) ; // allume la LED sur broche i
    delay (T2) ; // durée du flash 50 millisecondes
    digitalWrite (i, LOW) ; // éteint la LED
  }
  return ;
}