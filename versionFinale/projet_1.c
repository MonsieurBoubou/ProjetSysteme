/*Fichier créé et édité par Bouvier et Delagrange*/


#include "projet_1.h"



void projet_1(int nbJoueurs){
    //Déclaration des variables
    int avanceCheval;
    int nbTour = 0;
    int index = 1;
    Partie p;
    Plateau plateau;
    char *aToiDeJouer = malloc(10*sizeof(char));
    char *msgRecuParPere = malloc(10*sizeof(char));

    //Déclaration et allocation mémoire des tableaux de tubes et du tube retour
    int *tubeRetour = (int *)malloc(2*sizeof(int));
    int **tabTubesAnneau = (int **)malloc(nbJoueurs*sizeof(int)*2);
    int **tabTubesPere =(int**)malloc(nbJoueurs * sizeof(int)*2);



    //Initialisation et allocation mémoire des variables plateau et p
    plateau.taillePlateau = 56;
    plateau.nbJoueurs = nbJoueurs;
    plateau.positionCheval1 = (int *)malloc(nbJoueurs*sizeof(int));
    plateau.positionCheval1Ecurie = (int *)malloc(nbJoueurs*sizeof(int));
    for (int i = 0; i < nbJoueurs; i++)
    {
        plateau.positionCheval1Ecurie[i] = 6;
        plateau.positionCheval1[i] = -1;
    }
    p.gagnant = -1;
    p.termine = 0;
    
    //Création des nbJoueurs fils
    creerLesTubes(nbJoueurs, tubeRetour, tabTubesAnneau, tabTubesPere);


    //Lancement des protocoles fils
    lancementFils(nbJoueurs, tubeRetour, tabTubesAnneau, tabTubesPere, &p);
    

    //Fermeture des tubes inutilisés par le père
    fermerTubesPere(tabTubesAnneau,tabTubesPere,tubeRetour, nbJoueurs);
    do
    {   
        sprintf(aToiDeJouer, "%d", index);                                          //Conversion en char de l'entier index
        envoieATousLesFils(nbJoueurs, tabTubesPere, aToiDeJouer);                   //Envoie du numéro du fils qui doit jouer ce tour
        attendreRead(tubeRetour[0],msgRecuParPere);                                 //Attends que le tour soit fini
        avanceCheval = atoi(msgRecuParPere);                                        //Conversion en int du message perçu par le père
        
        miseAJourJeu(&plateau, avanceCheval, index, nbJoueurs, &p);                 //Mise a jour du plateau en fonctions des règles définies
        if (avanceCheval != 6){
            index++;
        }                                                          
        if (index >= nbJoueurs){                                                    //Permet de passer de savoir quel fils jouera le tour suivant
            index = 0;
            nbTour++;                                       
        }        
    } while (gagnant(&p) == -1);                                                    //Tant que le gagnant n'est pas défini ou modifié par miseAJourJeu, le jeu continue
    if (index == 0)
    {
        index = nbJoueurs-1;                                                        
    }
    
    printf("Partie terminée, le joueur %d a gagné en %d tours\n",index-1, nbTour -1);
    montrerEtatJoueurs(nbJoueurs, plateau.positionCheval1, plateau.positionCheval1Ecurie);
} 



void lancementFils(int nbJoueurs, int *tubeRetour, int **tabTubesAnneau, int **tabTubesPere, Partie *p){
    for (int i = 0; i  < nbJoueurs ; i++){

        int process = fork();                                                                       

        if (process == 0){                                                       //Test pour savoir quel tube donner a quelle processus
            if (i == 0)
            {
                joueur(i, nbJoueurs, tubeRetour, tabTubesAnneau[i], tabTubesAnneau[nbJoueurs - 1], tabTubesPere[i], p);
            }else {
                joueur(i, nbJoueurs, tubeRetour, tabTubesAnneau[i], tabTubesAnneau[i-1],tabTubesPere[i], p);    
            }
        }
        else if(process == -1){
            fprintf(stderr, "Probleme dans la création des fils\n");
        }
    }
}



void envoie(int tube, char *buf){
    
    if(write(tube, buf, sizeof(buf)) == -1){                                    //Test du retour du write
        fprintf(stderr, "Erreur avec le write de envoie()\n");
        exit(-1);
    }
}


void envoieATousLesFils(int nbJoueurs, int **tabTubesPere, char *buf){          
    for (int i = 0; i < nbJoueurs ; i++){
        envoie(tabTubesPere[i][1], buf);
    }
}

void attendreRead(int tube, char* buf){
    while(read(tube, buf, 10)<=0);                              //Permet d'attendre sur un read()
}

