

#Les servos-moteurs

##Pourquoi des servos ?
De part l'envie d'utiliser un Arduino et afin d'ajouter du mouvement sur le réseau, il est licite de penser en premier lieu à l'utilisation des servos dans l'animation du réseau par un Arduino. La documentation est très riche dans le domaine de la robotique avec Arduino. La commande est aussi aisée car le servo est nativement "reconnue" par l'Arduino. Il est utile par contre de rappeler qu'un Arduino ne peut alimenter tout un tas de servos de par son ampérage total faible, alimenter par une source extérieure les servos sera donc indispensable.  
Le second point positif est son prix. En effet, que l'on compare face à un moteur solénoïde ou un moteur lent, la facture en sera diminuée.

##Que commanderaient les servos ?
La première fonction de ces servos serait de commander les aiguilles. Rappelons que les servos sont des moteurs dont la course est limitée entre un point A et un point B, ils ne peuvent tourner indéfiniment ; ils ne pourront donc pas être utilisées dans une animation tournante tel un moulin.  
Par contre, ils peuvent être utilisés dans l'animation d'un PN. Nous verrons cela au cas par cas, si celui-ci se présente. Nous avons probablement fait qu'effleurer la possibilité d'animations avec les servos.

##Quel est le mouvement d'une aiguille ?
La réalité dicte un mouvement lent qui permet la visualisation du changement d'état de l'aiguille.  
Cependant, la miniaturisation n'est pas aussi précise. Nous avons déjà parlé des deux types de moteurs qui co-existent. Il y a donc 2 types de mouvement en miniature :

* mouvement rapide d'un solénoïde avec une aiguille qui possède un ressort de plaquage (a deux positions de base pour voie déviée et voie droite). Là, le ressort qui va faire rester l'aiguille dans la position définie. Si la tige du moteur bouge un peu, l'aiguille reviendra à sa position grâce au ressort.
* mouvement lent d'un moteur lent avec une aiguille n'ayant pas de ressort de plaquage (n'a pas de position de base), c'est le moteur par sa tige qui va faire rester l'aiguille dans la position définie.

Le mouvement du servo est maniable. Il peut donc copier ces deux types de mouvement. Dans le cas d'un réseau déjà en fonctionnement, il pourra remplacer nimporte lequel. Notez que l'Arduino n'est pas seulement capable de commander des servos mais les moteurs solénoïdes et lents sont aussi commandables par l'Arduino, mais ce ne sera pas l'objet de cet article.

##Pré-requis
Avant de pouvoir écrire le code, il faut définir les angles du servo qui correspondent aux deux états de la voie. Il faut donc installer le servo et commander le servo par la console ou un autre programme pour chercher à tatillons les meilleurs valeurs des deux positions.
Lien de l'article à mettre quand il sera prêt.

##Comment coder le mouvement d'un servo ?
Nous nous référerons aux articles de Jean Luc qui expliquent parfaitement les différents mouvements possibles d'un servo. Nous utilserons 2 méthodes dans chacun des mouvements différents. Pour cela, reprenons les commandes servis par le référentiel Arduino : [Servos](http://arduino.cc/en/Reference/Servo).  
Deux commandes vont être utilisées, chacune dans un des cas suivants :

* `.write()` pour le premier cas
* `.writeMicroseconds()` pour le deuxième cas

En ce qui concerne la partie réception, nous reviendrons dessus après puisqu'importe le mouvement défini, il faut que la commande soit la même. Le code est donc partagé en deux parties :

* une partie réception qui sera combinée avec la réception des autres données. L'Arduino ne sera probablement pas dévolue seulement à l'action des servos.
* une partie action que nous allons détailler ci-après.

##Mouvement rapide de solénoïde
Cette partie sera la plus facile à coder. En effet, du fait du mouvement rapide, il n'y a qu'à rentrer dans le code, la position déviée ou droite de l'aiguille pour actionner le servo dans le bon sens. Entre la partie communication et la partie action, il sera nécessaire d'utiliser une variable pour entraîner ou non le mouvement de l'aiguille. Du fait des deux positions possibles, la plus petite variable utilisable est une variable booléenne : 0 ou 1.

Du coté du code, le squelette initial sera du type :
```
if(variable==1){  
servo.write(130);  
}  
else  
{
servo.write(80);  
}
```

80 définit l'angle de la position déviée de l'aiguille et 130 la position droite. Ce n'est qu'un squelette de code, il nous faudra définir la variable, histoire d'avoir une uniformité dans toutes les variables de servos. De plus, ce bout de code sera probablement empaquetée dans une fonction, afin que l'écriture et l'ajout en soit facilitée.

##Mouvement lent d'un moteur de même nom
La difficulté de cette partie résulte du mouvement lent. Le mouvement d'un servo comme démontré par Jean Luc est saccadé avec l'instruction `.write`. Nous allons donc utiliser l'autre instruction, mais il nous faut d'abord contourner le problème de la boucle et du `delay()` présenté dans l'article des servos. En effet, utiliser une boucle avec le code `delay()` pour bouger le servo d'un mouvement lent rend totalement sourd l'Arduino aux instructions qu'il peut recevoir ou envoyer. Si, un signal d'alerte est à envoyer ou reçu et à traiter, cela attendra la fin de la boucle. Dans ce cas, le résultat pourra être catastrophique.

##Suite
Après définition du protocole de communication
