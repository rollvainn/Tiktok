PROJET MORPION
Le Projet est subdivise en 4 modules :
main consititue le point d'entrée et game s'occupe de la boucle principale du jeu et l'assembalge des autres modules
un board.h qui gére la grille et contient le sprinciaples fonctions du jeu dont intitboard print board, check win etc.
le log.h comme son nom l'indique s'occupe du journal, de l'historique
et enfin io.c se charge de la saisie
le teableau board est passé en parametres a chaque fonction
et le chrnonométre est basé sur clock() de la libraire <time.h>
Les fonctions principales sont
 
void initBoard(char board[3][3])
 Initialise toutes les cases a ' '
 
void printBoard(char board[3][3])
Affiche la grille ASCII avec indices de ligne/colonne
 
char checkWin(char board[3][3])
 Retourne 'X', 'O' ou 0 selon l'etat du jeu
 
int isFull(char board[3][3])
Retourne 1 si grille pleine, 0 sinon
 
double playTurn(char board[3][3], char player, FILE *f, int turn)
Saisie securisee, validation, placement, chrono, log
 
void logMove(FILE *f, int turn, char player, int row, int col)
Ecrit "Tour N : Joueur X joue (row,col)" dans le fichier
 
void displayLog(const char *filename)
Relit et affiche le fichier historique en fin de partie
 
void gameLoop(void)
Boucle principale : alternance X/O, detection fin, affichage resultats

Difficultés 
Quelques confusions sur la séparation des fichiers, il était necessaire de comprendre le role des prototypes les .h vs 
vs les implementations .c ainsi qu'eviter les inclusions circulaires on avait de lire un prototype puis le suivant 
puis rentre dans une boucle infinie d'ou l'utisation des #ifndef BOARD_H
#define BOARD_H

/

#endif
qui a réglé ce probléme
u départ ecoule était utilisé avant d'être rempli par playTurn, ce qui donnait une valeur aléatoire pour le chrono.
Il fallait bien appeler playTurn en premier avant d'accumuler le temps.

TESTS realises
des saisies hors limites, dessaisies non numériques 