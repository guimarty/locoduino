/*
Programme pour arduino uno
Pour locoduino.org
Licence GNU GPLv3
Multi-programme pour feu tricolore, enseigne et chenillard avec fonction millis
Schéma de branchement : 
=> feu vert 1 et 2 sur broche 0 et 1, orange 1 et 2 sur 2 et 3
et rouge 1 et 2 sur 4 et 5
=> Chenillard sur les broches de 6 à 11 : 6 LED
=> Enseigne sur les broches analogiques de 14 à 19 soit de A0 à A5
*/
//Déclaration des broches de feu
const int feu_vert = 0;
const int feu_orange = 2;
const int feu_rouge = 4;
//Il n'y a pas besoin de déclarer les variables des autres broches.
//Déclaration des différentes variables utilisées pour flécher les différentes étapes
byte i; //Variable utilisée pour les boucles. Cela évite de déclarer cette variable à chaque fois dans la boucle for.
//Pour le feu tricolore
byte etat_temps_feu = 0;//pour comptabiliser le nombre de fois où la valeur de temps choisie s'écoule. 
boolean feu = 0;//pour gérer la route où le feu doit fonctionner : 0 ou 1 dans le cas d'un croisement où 2 ou 4 feux (fonctionnant 2 par 2) sont présents
//Pour le chenillard
byte broche_chenillard = 6;//gérer l'état des broches du chenillard en fonction d'une incrémentation
byte etat_temps_chenillard = 0;//compter le nombre du temps de 50ms passées
//Pour les animations de l'enseigne
byte etat_temps_enseigne= 0;//compter le nombre du temps de 50ms passées
byte compteur_tour_enseigne = 0;//compter le nombre de boucles passées
byte broche_enseigne = 14; //gérer la broche de sorties lors des répétitions
long aleatoire;//gérer l'aléatoire dans le choix des animations
byte compte_LED_restantes = 5;//pour l'animation 3
//Déclaration des différents variables pour stocker le temps de l'arduino
unsigned long temps_feu = 0; //pour le feu tricolore
unsigned long temps_chenillard = 0; //pour le chenillard i.e. feux dans les virages
unsigned long temps_enseigne = 0;//pour l'enseigne
void setup()
//Déclaration des broches du feu, du chenillard et de l'enseigne en boucle
{
  for (i=0 ; i<12 ; i++)
  {
    pinMode(i, OUTPUT);
  }
  
  for(i=14 ; i < 20 ; i++)
  {
    pinMode(i, OUTPUT);
  }
//Mise des valeurs de base sur les broches : LOW à part les feux rouges
  for (i=0 ; i<4 ; i++)
  {
    digitalWrite(i, 0);
  }
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  for (i=6 ; i<12 ; i++)
  {
    digitalWrite(i, 0);
  }
  
  eteindre_enseigne();
  aleatoire=random(1, 4);//attribution à la variable d'un nombre entre 1 et 4 non inclus
}
//Boucle du programme
void loop()
{
//Etape de condition pour le feu. Si le temps passé est supérieur à 2s, on exécute le code après sinon on continue le loop.  
  if (millis() - temps_feu > 2000) //Utilisation d'un temps de 2s multiple de 2 et 10
  {
    etat_temps_feu++;//On incrémente le compteur pour les 2s
    fonction_feu(etat_temps_feu);//On exécute la fonction du feu en fonction du compteur
    temps_feu = millis();//On stocke la nouvelle valeur du temps pour en quelque sorte remettre à zéro la condition du if précédent
  }
//Etape de condition pour le chenillard. Si le temps passé est supérieur à 50ms, on exécute le code après sinon on continue le loop.  
  if (millis()-temps_chenillard > 50)//Utilisation d'un temps de 50ms multiple de 50 et 500ms
  {
    etat_temps_chenillard++;//On incrémente le compteur pour les 50ms
    fonction_chenillard(etat_temps_chenillard);//On exécute la fonction du chenillard en fonction du compteur
    temps_chenillard = millis();//On stocke la nouvelle valeur du temps pour en quelque sorte remettre à zéro la condition du if précédent
  }
  
//Etape de condition pour l'enseigne Si le temps passé est supérieur à 50ms, on exécute le code ci-après  
  if ((millis() - temps_enseigne) > 50 )
  {
    etat_temps_enseigne++;//On incrémente pour les 50ms passées
    switch(aleatoire)//on sélectionne l'animation que le random a défini.
    {//chaque animation est stockée dans une fonction
      case 1:
      enseigne1(etat_temps_enseigne);
      break;
      
      case 2:
      enseigne2(etat_temps_enseigne);
      break;
      
      case 3:
      enseigne3(etat_temps_enseigne);
      break;
    }
    temps_enseigne = millis();
  }
}
//Définition des différentes fonctions
/* Définition de la fonction du feu. L'allumage des LED se fait en fonction du temps passé 2s pour feu rouge et orange et 10s pour le feu vert soit 5 tours.
Pour changer de feu qui doit faire le cycle, on échange la valeur booléane feu.
*/
void fonction_feu(byte x)
{
  switch(x)
  {
    case 1:
    digitalWrite(feu_rouge + feu, 0);//On éteint le feu rouge
    digitalWrite(feu_vert + feu, 1);//On allume le feu vert
    break;
    
    case 6:
    digitalWrite(feu_vert + feu, 0);//On éteint le feu vert
    digitalWrite(feu_orange + feu, 1);//On allume le feu orange
    break;
    
    case 7:
    digitalWrite(feu_orange + feu, 0);//On éteint le feu orange
    digitalWrite(feu_rouge + feu, 1);//On allume le feu rouge
    etat_temps_feu = 0;//On remet à zéro pour refaire le cycle de la fonction
    feu = !feu; //on échange de croisement
    break;
  }
}
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
    if (broche_chenillard == 12)//arrivée au bout du chenillard
    {
      etat_temps_chenillard = 6;//pour établir un délai entre chaque chenillard
      broche_chenillard = 6; //on remet à zéro pour une nouvelle boucle de chenillard après attente
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
/*Définition des fonctions des animations de l'enseigne
3 fonctions au total
*/
//1ère animation : clignotement de l'ensemble des LED 3 fois
void enseigne1(byte z)
{
  switch(z)
  {
    case 1://allumage des LED
    for (i=14 ; i < 20 ; i++)
    {
      digitalWrite(i, 1);
    }
    break;
    
    case 11://extinction des LED
    eteindre_enseigne();
    break;
    
    case 20://pour patienter un peu 500ms
    compteur_tour_enseigne++;//on incrémente le compteur de tours
    etat_temps_enseigne =0;//on remet à zéro pour une nouvelle boucle
    if (compteur_tour_enseigne==3)//si 3 tours exécutés
    {
      compteur_tour_enseigne = 0;//on remet à zéro le compteur
      aleatoire = random(1, 4);//on change d'animation si aleatoire ne reste pas 1
    }
    break;
  }
}
//2ème animation : chenillard exécuté 2 fois
void enseigne2(byte t)
{
  switch(t)
  {
    case 1:
    digitalWrite(broche_enseigne, 1);//Allumage de la LED
    break;
    
    case 4:
    digitalWrite(broche_enseigne, 0);//Extinction de la LED 
    break;
    
    case 5:
    broche_enseigne++;//incrémentation de la broche pour changer de LED
    etat_temps_enseigne = 0;//RAZ pour revenir au début de la boucle
    if (broche_enseigne == 20)//quand le chenillard est fini
    {
      broche_enseigne = 14;//RAZ des broches pour revenir au début du chenillard
      compteur_tour_enseigne++;//Incrémentation du compteur
    }
    if (compteur_tour_enseigne == 2)//si 2 chenillards faits 
    {
      compteur_tour_enseigne = 0;//RAZ du compteur
      etat_temps_enseigne = 6;//pour faire patienter
    }
    break;
    
    case 25:
    etat_temps_enseigne = 0;
    aleatoire = random(1, 4);
    break;
  }
}
//3ème animation : chenillard de gauche à droite avec cumul des LED sur la droite et extinction de gauche à droite
void enseigne3(byte u)
{
  switch(u)
  {
    case 1:
    digitalWrite(broche_enseigne, 1);
    break;
    
    case 4:
    //Ensemble de conditions si fausses la boucle continue
    if (compteur_tour_enseigne == compte_LED_restantes) //tour complet 
    {
      compte_LED_restantes--;//décrémentation des LED restantes à allumer pour faire un tour moins complet
      etat_temps_enseigne = 0;//RAZ pour refaire la boucle
      broche_enseigne = 14;//RAZ de la broche de sortie
      compteur_tour_enseigne = 0;//RAZ des tours
      if (compte_LED_restantes == 0) //les 5 dernières LED sont allumées
      {
        digitalWrite(14, 1);//On allume la dernière LED
        broche_enseigne = 19; //On met à 19 pour l'extinction
        etat_temps_enseigne = 97;//On sort de la boucle
      }
    }
    else //On recommence le tour pour faire une boucle complete
    {
      digitalWrite(broche_enseigne, 0); //On éteint la LED
      broche_enseigne++; //On change de broche
      etat_temps_enseigne = 0; //On remet à 0 le temps
      compteur_tour_enseigne++; //on comptabilise le tour
    }
    break;
    
    case 100:
    digitalWrite(broche_enseigne, 0);//On éteint la LED
    break;
    
    case 103:
    broche_enseigne--;//on décrémente pour éteindre les LED
    if (broche_enseigne == 13) //Extinction de toutes les LED faites
    {
      etat_temps_enseigne = 104;// on fait sortir de cette boucle
    }
    else
    {
      etat_temps_enseigne = 97; //on continue l'extinction
    }
    break;
    
    case 114: //pour faire patienter
    //RAZ de toutes les valeurs utilisées
    aleatoire = random(1, 4);//choix d'une animation au hasard
    etat_temps_enseigne = 0;
    compteur_tour_enseigne = 0;
    broche_enseigne = 14;
    compte_LED_restantes = 5;
    break;
  }
}
//Extinction des LED de l'enseigne
void eteindre_enseigne()
{
  for(i=14 ; i < 20 ; i++)
  {
    digitalWrite(i, 0);
  }
}