Squelette de l'article

# Introduction

Utilisation de l'arduino dans son ensemble sans apport d'autre matériel externe "intelligent" type ordi, smartphone et autres. 
Du tout DIY.
Système complet avec utilisation du numérique ou de l'analogique. Rétrosignalisation et tout le reste.

# Architecture
Qu'importe les Arduinos utilisés.
Reliés par un bus CAN. Exit wire, i2c spi et consort (mettre explications). A moins de faire une commande arduino sans fil mais cela se fera ensuite, quand tout sera bouclé.

# Débouchés
je marque ce que j'estime dans mon réseau (je mets aussi le suivant, probablement en HOm toujours analogique mais avec rétrosignalisation et automatisme)
Le 1er : bas de gamme simple, d'un coté une plaque tournante sans moteur ou autre desservant 3 voies dont 1 rejoint l'autre coté barré par une coulisse de type pont transbordeur. Il reste seulement la possibilité de mettre une autre voie de garage mais rien de plus.
Soit avec un Arduino : une gestion de la marche du train avec la gestion de 3 voir 4 cantons (les coulisses sont alimentées par les cantons via des languettes) ainsi que la gestion des animations (cycle jour nuit, lampadaires, lumières maisons, poste soudure) Je pense faire un mode automatique des animations en fonction du cycle jour/ nuit mais aussi un mode manuel.
Pour le TCO si physique, je pense à un potentionmètre avec un bouton de marche arrière avant ou encodeur, avec bouton et led pour fixer les choses. Mais dans le mode manuel lumière je me dis que les boutons seront nombreux donc peut être un TCO virtuel sur écran (je n'ai pas reçu le mien, saleté de voleur)

Pour le 2ème réseau, toujours analogique, mais réseau bouclé avec possibilité de circulations automatiques, l'apport de la bibliothèque de jean luc sera indéniable pour permettre plusieurs circulations en même temps.
La version 0.01 de la pré ébauche donne un réseau en 8 avec une gare visible et une gare caché en dessous : 2-3 voies chacunes ou plus pour la gare cachée. Ceci dans le but d'avoir un décor plus complet qu'en module. Le pb étant le transport après vu que l'on déménagera et si ca se trouve même avant qu'il soit commencé. Sinon simple réseau bouclé en module. Mais bon cela reste loin.
C'est pour te montrer que pour moi aucun souci pour faire les autres trucs.

De toute façon, mon HO est numérique. J'ai en projet un mini dépôt pour voir tout de même évoluer un peu mes machines. Après je ne sais pas quoi faire comme réseau.
