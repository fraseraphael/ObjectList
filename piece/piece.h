#pragma once
/*==================================================================================
Auteure : Raphaël Fraser
Projet : Lab07-Jeu de Blokudoku
Nom du fichier : point.h
Date : 2021-04-19
But : Piece du jeu Blokudoku (qui utilise le square qui hérite du rectangle)
==================================================================================*/

// LES LIBRAIRIES
#pragma once		 // Évite de réinclure le iostream et autres librairies...
#include <iostream>	 // Permet le input et output
#include <cassert>	 // Permet d'inclure le assert (robustesse -> setteurs)
#include "square.h"  // Objet square (qui hérite de l'objet rectangle)
using namespace std;

// LA CLASSE PIECE
class piece {

private:

	square _piece[2][2];					// Pièce faite de 1,2,3 ou 4 square

// PROTOTYPES DES MÉTHODES (4)
public:

	void setPiece(int line, int col, const square& q);
	const square& getPiece(int line, int col) const;
	void setPieceActive(bool val1, bool val2, bool val3, bool val4);
	void draw(ostream& sortie)const;

};

// PROTOTYPE DES FONCTIONS PROPRES À L'OBJET PIECE (1)

ostream& operator<<(ostream& sortie, const piece& p);
