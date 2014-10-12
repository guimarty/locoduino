#Les servos-moteurs

##Pourquoi des servos ?
De part l'envie d'utiliser un Arduino et afin d'ajouter du mouvement sur le réseau, il est licite de penser en premier lieu à l'utilisation des servos dans l'animation du réseau par un Arduino. La documentation est très riche dans le domaine de la robotique avec Arduino.  
Le second point positif est son prix. En effet, que l'on compare face à un moteur solénoïde ou un moteur lent, il est indéniable que la facture sera encore moindre.

##Que commanderaient les servos ?
La première fonction de ces servos serait de commander les aiguilles. Rappelons que les servos sont des moteurs dont la course est limitée entre un point A et un point B, ils ne peuvent tourner indéfiniment ; ils ne pourront pas être utilisées dans une animation tournante tel un moulin.  
Par contre, ils peuvent être dans l'animation d'un PN. Nous verrons cela au cas par cas, si celui-ci se présente.

##Quel est le mouvement d'une aiguille ?
La réalité dicte un mouvement lent qui permet la visualisation du changement d'état de l'aiguille.  
Cependant, la miniaturisation n'est pas aussi précise. Nous avons déjà parlé des deux types de moteurs qui co-existent. Il y a donc 2 types de mouvement en miniature :

* mouvement rapide d'un solénoïde avec une aiguille qui possède un ressort de plaquage (a deux positions de base pour voie déviée et voie droite)
* mouvement lent d'un moteur lent avec une aiguille n'ayant pas de ressort de plaquage (n'a pas de position de base)

Le mouvement du servo est maniable. Il peut donc copier ces deux types de mouvement. Dans le cas d'un réseau déjà en fonctionnement, il pourra remplacer nimporte lequel. Notez que l'Arduino n'est pas seulement capable de commander des servos mais les moteurs solénoïdes et lents sont aussi commandables par l'Arduino, mais ce ne sera pas l'objet de cet article.

##Pré-requis
Avant de pouvoir écrire le code, il faut définir les angles du servo qui correspondent aux deux états de la voie. Il faut donc installer le servo et commander le servo par la console ou un autre programme pour chercher à tatillons les meilleurs valeurs des deux positions.
Lien de l'article à mettre quand il sera prêt.

##Comment coder le mouvement d'un servo ?
Nous nous référerons aux articles de Jean Luc qui expliquent parfaitement les différents mouvements possibles d'un servo

##Mouvement rapide de solénoïde
Cette partie est la plus facile à coder.

##Mouvement lent d'un moteur de même nom
Après tests persos

##Suite
Après définition du protocole de communication