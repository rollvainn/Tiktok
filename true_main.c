#include <stdio.h>
#include <time.h>

void initBoard(char grille[3][3]) {

}
void printBoard(char grille[3][3]) {

}
char checkWin(char grille[3][ 3]) {

}
int isFull(char grille[3][3]) {
    
}
void logMove(){ 

}
void measuretime(){
    
}
double playTurn(char grille[3][3], char joueur, FILE *fichier, int tour) { //la fonction renvoie un double en fin et permet d'effectuer la saisie et le blindage qui va avec
    int ligne, col;
    clock_t debut, fin; //type qui permet de contenir les valeurs renvoyes par clock()

    debut = clock();//demarre le chrono


















}






int main() {
    char grille[3][3];
    char joueur = 'X';
    char gagnant;
    int tour = 1;
    double tempsX = 0.0, tempsO = 0.0;
    FILE *fichierLog;
    char nomFichier[] = "historique_morpion_g_xx.txt";

    initBoard(grille);

    fichierLog = fopen(nomFichier, "w");
    if (fichierLog == NULL)
        printf("Impossible de creer le fichier historique.\n");
    else
        fprintf(fichierLog, " Partie de Morpion \n");

    printf("\n Bienvenue dans le Morpion ! \n");

    while (1) {
        printBoard(grille);

        if (joueur == 'X')
            tempsX += playTurn(grille, joueur, fichierLog, tour);
        else
            tempsO += playTurn(grille, joueur, fichierLog, tour);

        gagnant = checkWin(grille);
        if (gagnant != 0) {
            printBoard(grille);
            printf(" Joueur %c a gagne ! \n\n", gagnant);
            if (fichierLog != NULL)
                fprintf(fichierLog, "Resultat : Joueur %c gagne.\n", gagnant);
            break;
        }

        if (isFull(grille)) {
            printBoard(grille);
            printf(" Match nul !\n\n");
            if (fichierLog != NULL)
                fprintf(fichierLog, "Resultat : Match nul.\n");
            break;
        }

        if (joueur == 'X')
            joueur = 'O';
        else
           joueur = 'X';
        tour++;
    }

    printf("Temps total joueur X = %.2f secondes\n", tempsX);
    printf("Temps total joueur O = %.2f secondes\n\n", tempsO);


    return 0;
}
