/*Fichier créé et édité par Bouvier et Delagrange*/

#include "projet_1.h"
#include "tube.h"
#include "partie.h"
#include "plateau.h"
#include "jeu.h"


void presentation(int *nbJoueurs);

int main(int argc, char **argv){
    int nbJoueurs;
    presentation(&nbJoueurs);
    projet_1(nbJoueurs);
    return 0;
}


void presentation(int *nbJoueurs){
    fprintf(stdout,"########################################### Bonjour à vous !! ###########################################\n");
    fprintf(stdout, " Bienvenue dans notre jeu de petits chevaux !!\n");
    fprintf(stdout,"Dans ce jeu vous serez uniquement spectateur. Il vous suffit juste de nous donner le nombre de joueur que vous voulez faire jouer\n");
    do {
        fprintf(stdout,"\n\n\nEntrez donc un nombre de joueurs. Il doit être entre 2 et 4 : ");
    
        scanf("%d",nbJoueurs);
    }while(*nbJoueurs <= 1);
    fprintf(stdout, "\n\n\nNous allons lancer le jeu maintenant. Vous verrez le numéro du joueur qui a gagné ainsi que son nombre de coups\n\n\n");

}