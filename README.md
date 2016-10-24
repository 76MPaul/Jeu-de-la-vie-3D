# Jeu-de-la-vie-3D

Création de 2011

Implémentation du jeu de la vie en 3D en C++ avec Irrlicht

Je n'ai malheureusement pu retrouver qu'un rassemblement de l'ensemble du code en un seul fichier (probablement créé pour une présentation à l'époque). Le code n'en reste pas moins fonctionnel mais l'ajout de fonction permettrait une bien meilleur lisibilité.

Voici les fonctionnalitées du programme :

Le programme gère le remplissage aléatoire de la grille, le remplissage manuel, le nombre d’étapes, la taille de la grille, le choix des conditions de vie et la recherche des figures d’invariances.

Le remplissage aléatoire de la grille se fais à partir du menu options.

    L’onglet Nombre de cases concernées gère le nombre de cases maximal affecté par le remplissage autour du centre de du cube. Il doit être compris entre 1 et 100.

Par exemple, pour une grille de taille 25, si on choisi 50 en valeur de Nombre de cases concernées, seules les 6 cases de part et d’autres du milieu du cube seront concernées par le remplissage.

    L’onglet Pourcentages de cases gère le pourcentage de cases qui seront remplies lors du passage de l’algorithme. Il doit être compris entre 1 et 100.

Par exemples, pour une grille de taille 25, si on choisi 50 en valeur de Pourcentages de cases, (25*25*25)/2  seront remplies soit 7812.

Le remplissage manuel s’effectue en appuyant sur « S ». Elle se fait en 2 étapes :

    Le choix de la tranche du cube que l’on vas modifier se fait par clique droit,
    le choix des cubes dont on veux changer la valeur se fait aussi par clique droit.

    Le retour à l’étape précédentes se fait par clique gauche.
    
Le choix des conditions de vie est possibles dans les options. De bases, les conditions sont 3/4/4/4.

    Les deux premiers chiffres correspondent aux conditions de survie de la cellule. C’est à dire qu’une cellule survivras (seras présente à l’étape suivante) si elle est entouré d’un nombre de cellule compris entre 3 et 4. L’ordre de ces conditions importe peu. On peut rentrer les conditions dans l’ordre 3/7 ou 7/3, l’inégalité  3< Nombre de cases alentour <7 seras conservé.

    Les deux derniers chiffres sont les conditions de naissance d’une cellule. Une cellule naitras d’une case vide si elle est entouré de ConditionVie1 cellules ou ConditionVie2 cellules. L’ordre n’as donc pas non plus d’importance.

Le choix du nombre d’étapes ce fais aussi par le menu option, rentrez un nombres et appuyer sur valider.

Le choix de la taille de la grille ce fais en cliquant sur le bouton Taille Grille dans le menu option. Cinq taille de grille sont proposées. Elle est à 25 par défauts.
Attention,  changer la taille de la grille peut fortement impacter sur les performances du programme.

La recherche des figures d’invariances s’effectue en cliquant sur le bouton Invariance. Celle-ci prend en compte les conditions de vie et de mort que vous choisissez. Cette recherche fonctionne jusqu’à ce qu’il trouve une figure d’invariance ou que vous l’arrêtiez.
