/*Fichier créé et édité par Bouvier et Delagrange*/

#include "jeu.h"


char *avancerChevaux(){
    unsigned int tmp;
    getrandom(&tmp, sizeof(unsigned int),GRND_NONBLOCK) == -1 ?
        perror("getrandom") : "";
    int avancer = tmp % 6 + 1;
    char *res = malloc(10*sizeof(char));
    sprintf(res, "%d", avancer);
    return res;
}


void miseAJourJeu(Plateau *plateau, int avanceCheval, int index, int nbJoueurs, Partie *p){
    int indexVoisin = index + 1 ;
    if (plateau->positionCheval1[index] == -1){
        
        if (plateau->positionCheval1Ecurie[index] == avanceCheval){
            if(plateau->positionCheval1Ecurie[index] == 1){
                plateau->positionCheval1[index] = 1;
                plateau->positionCheval1Ecurie[index] = 1;
            }else{
                plateau->positionCheval1Ecurie[index] = avanceCheval-1;
            }
        }
    }else{
        if(plateau->positionCheval1[index] == -2){
            if(avanceCheval == plateau->positionCheval1Ecurie[index]){
                if(plateau->positionCheval1Ecurie[index] == 6){
                    p->gagnant = index;
                    p->termine = 1;
                }
                plateau->positionCheval1Ecurie[index] = avanceCheval + 1;
            }
        }else{

            if(plateau->positionCheval1[index] + avanceCheval > 56){
                int depassement = plateau->positionCheval1[index] + avanceCheval - 56;
                plateau->positionCheval1[index] = 56 - depassement;
            }else if(plateau->positionCheval1[index] + avanceCheval == 56){
                plateau->positionCheval1[index] = -2;
            }else{
                plateau->positionCheval1[index] += avanceCheval;
            }
        }
    }
}




int gagnant(Partie *p){
    return  p->gagnant;
}

void joueur(const int index, int nbJoueurs, int *tubeRetour, int *tubeEnvoieFrere, int *tubeRecoisFrere, int *tubeRecuperePere, Partie *p){
    fermerTubes(tubeRetour, tubeEnvoieFrere, tubeRecuperePere, tubeRecoisFrere);
    char *aQuiDeJouer = malloc(10 * sizeof(char));
    char *aEnvoyerAuPere = malloc(10 * sizeof(char));
    char *msgDuFrere = malloc(10*sizeof(char));
    do{

        attendreRead(tubeRecuperePere[0], aQuiDeJouer);
        
        int aQuiDeJouerInt = atoi(aQuiDeJouer);
        
        if(aQuiDeJouerInt == index){
            aEnvoyerAuPere = avancerChevaux();
            write(tubeEnvoieFrere[1], aQuiDeJouer, sizeof(aQuiDeJouer));
        }
        attendreRead(tubeRecoisFrere[0],msgDuFrere);
        if(atoi(msgDuFrere) == index){
            envoie(tubeRetour[1], aEnvoyerAuPere);
        }else{
            envoie(tubeEnvoieFrere[1], msgDuFrere);
        }
    }while(gagnant(p) == -1);
    exit(-1);
}




void montrerEtatJoueurs(int nbJoueurs, int *positionCheval1, int *positionCheval1Ecurie){
    for (int i = 0; i< nbJoueurs; i++){
        if (positionCheval1[i]==-1){
            printf("Le joueur %d a encore son cheval dans l'écurie, il essaie de sortir. Il est a la case %d\n", i, positionCheval1Ecurie[i]);
        } else if (positionCheval1[i] == -2)
        {   
            if(positionCheval1Ecurie[i] == 7){
                printf("Le joueur %d  a gagné\n", i);
            }
            else {
                printf("Le joueur %d a son cheval dans l'écurie il essaie de remonter pour finir le jeu. Il est a la case %d\n", i, positionCheval1Ecurie[i]);
            }
        }else{
            printf("Le joueur %d est sur le plateau à la case %d\n",i, positionCheval1[i]);
        }
    }
}