/*==================================================================================
Auteurs : Marie-Claire Lewandowski
Projet : Lab07-Jeu de Blokudoku
Nom du fichier : mainBlokudoku.cpp
Date : 2021-04-08
But : ********* À FAIRE ****************
==================================================================================*/

#include <iostream>			// Permet le input et output
#include "square.h"			// Objet square
#include "piece.h"			// Objet piece
using namespace std;

// LES CONSTANTES

const int GRILLENBLINE = 5;		// Largeur de la grille
const int GRILLENBCOL = 5;		// Hauteur de la grille
const int PIECENBLINE = 2;		// Hauteur de la piece
const int PIECENBCOL = 2;		// Largeur de la piece

// LES PROTOTYPES DE FONCTIONS

void tailleEcran(int x, int y);
void initGrille(square tab[][GRILLENBCOL], int nbLigne, int nbColonne);
void printGrille(square tab[][GRILLENBCOL], int NBLINE, int NBCOL);
void initPiece(piece p[], int size);
//void printPiece(square tab[][PIECENBLINE], int pieceHauteur, int pieceLargeur);
int nextPiece(piece piece[], int size);
int choseCase();
void putPiece(const piece& p, square grilleJeu[][GRILLENBCOL], int indLine, int indCol);
bool collisionPiece(const piece& p, square grilleJeu[][GRILLENBCOL], int nbLine, int nbCol);
void viderBuffer();
// void printScore(int score); ****PAS FAITE ENCORE****
void eraseLineCol(square grilleJeu[][GRILLENBCOL], int indLine, int indCol); //****INACHEVÉE****

void main() {

	square grilleJeu[GRILLENBLINE][GRILLENBCOL];
	piece piece[10];
	int noCase(0);
	int indAleatoire;
	bool lose(false);
	int score(0);

	cout << "Bienvenue dans ce petit jeu ou vous pouvez placer des pieces sur la"
		<< endl << "grille, pour completer des lignes ou des colonnes completes."
		<< endl << "Attention de ne pas choisir un emplacement deja occupe!";

	srand(time(nullptr));	// Important pour un vrai random

	initGrille(grilleJeu, GRILLENBLINE, GRILLENBCOL);
	initPiece(piece, 10);
	printGrille(grilleJeu, GRILLENBLINE, GRILLENBCOL);
	tailleEcran(80, 40);
	
	indAleatoire = nextPiece(piece, 10);

	while (!lose) {			
		
		noCase = choseCase();

		int indLine = (noCase - 1) / GRILLENBLINE;
		int indCol = (noCase - 1) % GRILLENBCOL;

		if (!collisionPiece(piece[indAleatoire], grilleJeu, indLine, indCol)) {

			putPiece(piece[indAleatoire], grilleJeu, indLine, indCol);

			eraseLineCol(grilleJeu, GRILLENBLINE, GRILLENBCOL); //****INACHEVÉE****

			printGrille(grilleJeu, GRILLENBLINE, GRILLENBCOL);

			indAleatoire = nextPiece(piece, 10);

			Sleep(100);
		}

		else {
			gotoxy(0, 37);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // Msg en rouge
			cout << "Cet emplacement n'est pas valide.";
		}
		Sleep(200);
		
	}
	system("pause>0");
}

// Fonction générique
// qui permet de redimensionner la taille de l'écran console
void tailleEcran(int x, int y) {

	COORD tailleEcran = { x,y };
	SMALL_RECT tailleRectangle = { 0,0,x - 1,y - 1 };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), tailleEcran);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &tailleRectangle);
}

// Fonction propre au programme
// qui permet d'initialiser la grille de jeu 
void initGrille(square tab[][GRILLENBCOL], int nbligne, int nbcolonne) {

	for (int i = 0; i < nbligne; i++) {				// i = lignes
		for (int j = 0; j < nbcolonne; j++) {		// j = colonnes
			tab[i][j].setSquare((j * 8), (i * 4 + 3), 5, 6, 9, (i * 5 + j + 1), false);
		}
	}
}

// Fonction propre au programme
// qui permet d'afficher la grille du jeu en console
void printGrille(square tab[][GRILLENBCOL], int nbLigne, int nbColonne) {

	for (int i = 0; i < nbLigne; i++) {					// i = lignes
		for (int j = 0; j < nbColonne; j++) {			// j = colonnes
			if (tab[i][j].isActive())
				tab[i][j].drawFull(cout);
			else
				tab[i][j].draw(cout);
		}
	}
}

void initPiece(piece p[], int size) {

	int color[] = { 3,5,6,7,8,10,11,12,13,14 };
	for (int noPiece = 0; noPiece < 10; noPiece++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				square temp(j * 8, i * 4 + 26, 5, color[noPiece], 9);
				p[noPiece].setPiece(i, j, temp);
			}

	p[0].setPieceActive(true, true, true, true);	// gros carré
	p[1].setPieceActive(true, true, true, false);	// L sens inverse symétrie
	p[2].setPieceActive(true, true, false, true);	// 
	p[3].setPieceActive(false, true, true, true);	// L (symétrie gauche)
	p[4].setPieceActive(true, false, true, true);	// L (bon sens)
	p[5].setPieceActive(true, false, true, false);	// ligne gauche
	p[6].setPieceActive(true, true, false, false);	// barre haut
	p[7].setPieceActive(true, false, false, false); // petit carré
	p[8].setPieceActive(false, true, true, false);	// diago droite (/)
	p[9].setPieceActive(true, false, false, true);	// diago gauche (\)
}

// Fonction propre au programme
// qui génère un indice aléatoire et affiche la prochaine pièce
int nextPiece(piece piece[], int size)
{	
	gotoxy(0, 26);							// Effacement de la pièce précédente
	for (int i = 0; i < 40; i++)
		cout << "                           ";

	int indAleatoire = rand() % size;

	gotoxy(0, 25);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "Prochaine piece :" << endl;
	piece[indAleatoire].draw(cout);			// Affichage de la pièce

	return indAleatoire;
}

// Fonction propre au programme
// qui permet d'afficher la prochaine pièce en console
void printPiece(square tab[][PIECENBLINE], int pieceHauteur, int pieceLargeur) {

	for (int i = 0; i < pieceHauteur; i++) {			// i = lignes
		for (int j = 0; j < pieceLargeur; j++) {		// j = colonnes
			if (tab[i][j].isActive())
				tab[i][j].drawFull(cout);
		}
	}
}

int choseCase() {

	int noCase(0);

	do {
		gotoxy(0, 36);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Choisissez l'endroit ou placer la piece sur la grille :    ";
		gotoxy(57, 36);				// Emplacement de saisie de la rép. du joueur

		cin >> noCase;

		// On supprime le message d'erreur de la ligne sous celle de la saisie, s'il y a lieu
		gotoxy(0, 37);
		cout <<  "                                                                ";
	} while (noCase <1 && noCase > GRILLENBLINE*GRILLENBCOL);

	return noCase;
}

// Fonction propre au programme
// qui permet de placer une pièce sur la grille de jeu à la position désirée
void putPiece(const piece& p, square grilleJeu[][GRILLENBCOL], int indLine, int indCol) {

	for (int i = 0; i < PIECENBCOL; i++) {
		for (int j = 0; j < PIECENBLINE; j++) {	// IF ci-dessous = vérif si morceau sur ou hors grille
			if (p.getPiece(i,j).isActive() && (indLine + i < GRILLENBLINE && indCol + j < GRILLENBCOL)) {
				grilleJeu[indLine + i][indCol + j].setColor(p.getPiece(i, j).getColor());
				grilleJeu[indLine + i][indCol + j].setActive(p.getPiece(i, j).isActive());
				grilleJeu[indLine + i][indCol + j].drawFull(cout);
			}
		}
	}
}

// Fonction propre au programme
// qui permet de vérifier s'il y a chevauchement de pièces actives
// Retourne vrai s'il y a collision, faux sinon
bool collisionPiece(const piece& p, square grilleJeu[][GRILLENBCOL], int indLine, int indCol) {

	for (int i = 0; i < PIECENBCOL; i++) {
		for (int j = 0; j < PIECENBLINE; j++) {
			if (p.getPiece(i, j).isActive()) {	// Si pièce active

				if (indLine + i >= GRILLENBLINE || indCol + j >= GRILLENBCOL)
					return true;		// Si morceau sur ou hors grille

				if (grilleJeu[indLine + i][indCol + j].isActive())
					return true;		// Si sur une pièce
			}
		}
	}
	return false;
}

// Fonction générique
// qui permet de vider le buffer avant saisie (cin)
void viderBuffer() {

	cin.clear();			// On clear la val du cin (flux)

	if (!cin.fail())		// Flux valide, buffer non vide   
		fflush(stdin);

	else					// Flux invalide, buffer non vide
		cin.clear();		// Flux invalide remis à valide
}


// Fonction propre au programme ****INACHEVÉE****
// qui supprime les lignes ou colonnes complètes
void eraseLineCol(square grilleJeu[][GRILLENBCOL], int indLine, int indCol) {

	int compteurLignes(0);
	int compteurCol(0);
	int valeurLigne;
	int WinX[24] = { 0 };

	for (int i = 0; i < GRILLENBCOL; i++) {
	
		for (int j = 0; j < GRILLENBCOL; j++) {
			if (grilleJeu[i][j].isActive()){
				compteurLignes++;	
				compteurCol--;
			}

			if (compteurLignes == GRILLENBLINE) {
				for (int k = 0; k < GRILLENBLINE; k++) {
					(grilleJeu[i][k].setActive(false));
				}
			}

			if (compteurLignes == GRILLENBCOL) {
				for (int k = 0; k < GRILLENBCOL; k++) {
					(grilleJeu[k][i].setActive(false));
				}
			}

		}
		compteurLignes = 0;
	}

	compteurCol=0;
}


