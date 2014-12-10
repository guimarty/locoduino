/*Module chenillard pour les feux de virage. Les broches se suivent, dans l'hypothèse d'un changement, il faudra changer la broche de début (broche_debut_chenillard), mais qu'elles se suivent toujours et ceci absolument.
=> Chenillard sur les broches de 6 à 11 : 6 LED

*/

//Partie déclaration

//Pour le chenillard
const byte broche_debut_chenillard = 6; //à changer si changement de broches du chenillard
byte broche_chenillard = broche_debut_chenillard;//gérer l'état des broches du chenillard en fonction d'une incrémentation
byte etat_temps_chenillard = 0;//compter le nombre du temps de 50ms passées
//Variabe pour stocker le temps
unsigned long temps_chenillard = 0;
//Variable d'état du chenillard
boolean etat_chenillard = 0;

//Variable de boucle for dans le setup
byte i;

//Partie setup
void setup()
//Déclaration des broches du feu, du chenillard et de l'enseigne en boucle
{
  for (i=broche_debut_chenillard ; i<broche_debut_chenillard+6 ; i++)
  {
    pinMode(i, OUTPUT);
  }
//Extinction des LED
  eteindre_chenillard();
}

//Partie loop
void loop()
{
  //Fonction i2c pour récolter les différents états des modules envoyé par l'arduino maître
  // met etat_chenillard à 0 ou 1
  
  //fonction du chenillard selon son état
  switch(etat_chenillard){
    case: 0
      eteindre_chenillard();
      break
    case: 1
      if (millis()-temps_chenillard > 50)//Utilisation d'un temps de 50ms multiple de 50 et 500ms
      {
	etat_temps_chenillard++;//On incrémente le compteur pour les 50ms
	fonction_chenillard(etat_temps_chenillard);//On exécute la fonction du chenillard en fonction du compteur
	temps_chenillard = millis();//On stocke la nouvelle valeur du temps pour en quelque sorte remettre à zéro la condition du if précédent
	break
      }
  }
}
	
//Partie fonctions

/*
Définition de la fonction du chenillard en fonction du compteur commençant par 5, le compteur définissant aussi la broche de sortie pour l'allumage
des différentes LED toutes les 50ms puis un retour au début du cycle après 500ms soit 10 cycles
*/

void fonction_chenillard(byte t)
{
  switch(t)
  {
    case 1:
    digitalWrite(broche_chenillard, 1);
    break;

    case 4:
    digitalWrite(broche_chenillard, 0);
    break;

    case 5:
    broche_chenillard++;
    if (broche_chenillard == broche_debut_chenillard+6)//arrivée au bout du chenillard
    {
      etat_temps_chenillard = 6;//pour établir un délai entre chaque chenillard
      broche_chenillard = broche_debut_chenillard; //on remet à zéro pour une nouvelle boucle de chenillard après attente
    }
    else
    {
      etat_temps_chenillard = 0;//on remet à zéro pour un changement d'allumage/extinction de LED
    }
    break;

    case 20://pour patienter un peu 750ms
    etat_temps_chenillard = 0;
    break;
  }
}

void eteindre_chenillard()
{
  for (i=broche_debut_chenillard ; i<broche_debut_chenillard+6 ; i++)
  {
    digitalWrite(i, 0);
  }
}