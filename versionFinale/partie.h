/*Fichier créé et édité par Bouvier et Delagrange*/

#ifndef PARTIE_H
#define PARTIE_H

typedef struct Partie
{
    int termine;                    //Contient 0 si la partie est toujours en cours et 1 si la partie est terminée
    int gagnant;                    //Contient -1 tant que la partie continue et l'index du joueur qui a gagné à la fin de la partie
}Partie;


#endif