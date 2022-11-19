/*Fichier créé et édité par Bouvier et Delagrange*/

#include "tube.h"

void creerLesTubes(int nbJoueurs, int *tubeRetour, int **tabTubesAnneau, int **tabTubesPere){
    for (int i = 0; i < nbJoueurs; i++){
        tabTubesAnneau[i] = (int *)malloc(2 * sizeof(int));                                     //Allocation mémoire dans chaque case des tableaux 
        tabTubesPere[i] = (int *)malloc(2*sizeof(int));                                         //tabTubesAnneau et tabTubesPere
        if(pipe(tabTubesAnneau[i]) == -1 || pipe(tabTubesPere[i]) == -1){                       //Création des pipes
            fprintf(stderr, "Probleme avec la création du tube\n");
            exit(-1);
        }
    }

    if(pipe(tubeRetour)==-1){
        fprintf(stderr,"Probleme avec la création du tube\n");
        exit(-1);
    }
}


void fermerTubes(int *tubeRetour, int *tubeEnvoieFrere, int *tubeRecuperePere, int *tubeRecoisFrere){
    close(tubeRetour[0]);
    close(tubeEnvoieFrere[0]);
    close(tubeRecuperePere[1]);
    close(tubeRecoisFrere[1]);
}

void fermerTubesPere(int **tabTubesAnneau, int **tabTubesPere,int *tubeRetour, int nbJoueurs){
    for (int i = 0; i < nbJoueurs; i++){
        close(tabTubesAnneau[i][0]);
        close(tabTubesAnneau[i][1]);
        close(tabTubesPere[i][0]);
    }
    close(tubeRetour[1]);
}


