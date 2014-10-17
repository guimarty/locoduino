/*Module feux tricolores francais
Dans le programme, les feux sont reliés à certaines broches,
vous pouvez les changer mais elles doivent se suivre absolument.
=> feu vert 1 et 2 sur broche 0 et 1, orange 1 et 2 sur 2 et 3
et rouge 1 et 2 sur 4 et 5

Il sera nécessaire de placer une condition avant si on veut activer ou non l'animation
*/

//Partie déclaration
//Déclaration des broches de feu
const int feu_vert = 0;
const int feu_orange = 2;
const int feu_rouge = 4;

//temps pour le feu
unsigned long temps_feu = 0; //pour le feu tricolore
//Variable temps écoulé
byte etat_temps_feu = 0;
//Gérer la route
boolean feu = 0;

//Variable pour les boucles du setup
byte i;

//Partie setup
void setup()
//Déclaration des broches du feu, du chenillard et de l'enseigne en boucle
{
  for (i=0 ; i<6 ; i++)
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
}

//Partie loop
void loop(){
  if (millis() - temps_feu > 2000) //Utilisation d'un temps de 2s multiple de 2 et 10
  {
    etat_temps_feu++;//On incrémente le compteur pour les 2s
    fonction_feu(etat_temps_feu);//On exécute la fonction du feu en fonction du compteur
    temps_feu = millis();//On stocke la nouvelle valeur du temps pour en quelque sorte remettre à zéro la condition du if précédent
  }
}

//Partie fonctions
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
