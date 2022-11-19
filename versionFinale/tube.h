/*Fichier créé et édité par Bouvier et Delagrange*/

#ifndef TUBE_H
#define TUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
Permet de créer :
        - Un tube retour utilisé par tous les joueurs pour remonter l'info au père.
        - Autant de tubes entre frères qu'il y a de joueurs qui sont stockés dans tabTubesAnneau.
        - Les tubes du père vers chaque fils qui sont stockés dans tabTubesPere.
*/
void creerLesTubes(int nbJoueurs, int *tubeRetour, int **tabTubesAnneau, int **tabTubesPere);

/*
Ferme les descripteur de fichier que les fils n'utilisent pas.
*/
void fermerTubes(int *tubeRetour, int *tubeEnvoieFrere, int *tubeRecuperePere, int *tubeRecoisFrere);

/*
Ferme les descripteur de fichier que le pere n'utilise pas.
*/
void fermerTubesPere(int **tabTubesAnneau, int **tabTubesPere,int *tubeRetour, int nbJoueurs);



#endif