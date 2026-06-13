#include <stdio.h>
#include "game.h"
#include "board.h"
#include "io.h"
#include "log.h"

void gameLoop(void) {
    char board[3][3];
    char joueuractuel;
    char gagnant;
    int tour;
    double timeX, timeO, ecoule;
    FILE *logFile;
    char logFilename[28] = "historique_morpion_g_.txt";

   
    initBoard(board);
    joueuractuel = 'X';
    tour = 1;
    timeX = 0.0;
    timeO = 0.0;

    
    logFile = fopen(logFilename, "w");
    if (logFile == NULL) {
        printf("Erreur d'ouverture\n");
    } else {
        fprintf(logFile, "=== Partie de Morpion ===\n");
    }

    printf("\n--- Bienvenue dans le Morpion ! ---\n");
    printf("Joueur X commence.\n");

    
    while (1) {
    ecoule = playTurn(board, joueuractuel, logFile, tour);

    if (joueuractuel == 'X') {
        timeX += ecoule;
    } else {
        timeO += ecoule;
    }

    gagnant = checkWin(board);
    if (gagnant != 0) {
        printBoard(board);
        printf("*** Joueur %c a gagne ! ***\n\n", gagnant);
        if (logFile != NULL) {
            fprintf(logFile, "Resultat : Joueur %c gagne.\n", gagnant);
        }
        break;
    }

    if (isFull(board)) {
        printBoard(board);
        printf("*** Match nul ! ***\n\n");
        if (logFile != NULL) {
            fprintf(logFile, "Resultat : Match nul.\n");
        }
        break;
    }

    joueuractuel = (joueuractuel == 'X') ? 'O' : 'X';
    tour++;
}

    
    printf("Temps total joueur X = %.2f secondes\n", timeX);
    printf("Temps total joueur O = %.2f secondes\n\n", timeO);

    
    if (logFile != NULL) {
        fprintf(logFile, "Temps total joueur X = %.2f secondes\n", timeX);
        fprintf(logFile, "Temps total joueur O = %.2f secondes\n", timeO);
        fclose(logFile);
    }


    displayLog(logFilename);
}
