/*Fichier créé et édité par Bouvier et Delagrange*/

#ifndef PROJET_1_H
#define PROJET_1_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include "plateau.h"
#include "partie.h"
#include "tube.h"
#include "jeu.h"

/*
Cette fonction est la fonction principale du programme. Il y a d'abord une phase de déclaration de variables, d'allocation mémoire et d'initialisation des variables.
Ensuite la fonction créer les fils et le protocole démarre.
Ensuite il y a le protocole que le père doit faire tant que le jeu n'est pas terminé qui inclut la mise a jour du plateau.
*/
void projet_1(int nbJoueurs);


/*
Cette fonction créer les fils et lance le protocole de chaque fils avec les tubes que chaque fils utilisera.
*/
void lancementFils(int nbJoueurs, int *tubeRetour, int **tabTubesAnneau, int **tabTubesPere, Partie *p);


/*
Envoie avec un write le message buf dans le tube tube.
*/
void envoie(int tube, char *buf);


/*
Envoie le message buf a tous les fils via les tubesPereFils stockés dans le tableau tabTubesPere.
*/
void envoieATousLesFils(int nbJoueurs, int **tabTubesPere, char *buf);

/*
Cette fonction permet au processus qui l'appelle de rester "bloqué" sur un read() tant que le nombre d'octets qu'il lit est inférieur ou égal a 0.
*/
void attendreRead(int tube, char* buf);



#endif