/*Fichier créé et édité par Bouvier et Delagrange*/

#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct Plateau
{   
    int taillePlateau;                              //Contient la taille du plateau
    int nbJoueurs;                                  
    int *positionCheval1;                           //Tableau des positions du cheval de chaque joueur sur le plateau
    int *positionCheval1Ecurie;                     //Tableau des position du cheval de chaque joueur dans l'écurie

}Plateau;



#endif