/*Fichier créé et édité par Bouvier et Delagrange*/

#ifndef JEU_H
#define JEU_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/random.h>
#include <string.h>
#include <time.h>
#include "plateau.h"
#include "partie.h"
#include "tube.h"
#include "projet_1.h"


/*
Cette fonction renvoie en char un entier compris entre 1 et 6 choisis pseudos aléatoirement par la fonction getrandom()
*/
char *avancerChevaux();


/*
Cette fonction met a jour le plateau de type structure plateau définie dans 'tableau.h', en avançant le cheval du joueur index de avanceCheval cases
et regarde si ce joueur a gagné et si la partie est terminée. Elle utilise les tableaux positionCheval1 et positionCheval1Ecurie de la structure plateau.
Ces tableaux contiennent les positions des chevaux des joueurs. Si positionCheval1[index] = -1 alors le cheval du joueur index est encore dans l'écurie et essaie de sortir.
Si positionCheval1[index] = -2 alors le cheval du joueur index est encore dans l'écurie et essaie de remonter pour gagner. Dans les autres cas, le chaval de index est sur 
le plateau. Les règles que nous avons choisi sont un peu différentes du jeu classique. Les règles choisies sont données dans le rapport.
*/
void miseAJourJeu(Plateau *plateau, int avanceCheval, int index, int nbJoueurs, Partie *p);

/*
Renvoie p.gagnant
*/
int gagnant(Partie *p);


/*
Fonction qui met en place le protocole que chaque joueur doit faire tant que la partie n'est pas finie
*/
void joueur(const int index, int nbJoueurs, int *tubeRetour, int *tubeEnvoieFrere, int *tubeRecoisFrere, int *tubeRecuperePere, Partie *p);


/*
Affiche a l'écran l'état de tous les joueurs sur le plateau
*/
void montrerEtatJoueurs(int nbJoueurs, int *positionCheval1, int *positionCheval1Ecurie);


#endif