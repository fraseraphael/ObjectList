
/* =================================================================================
	DÉFINITION DES MÉTHODES ET DES FONCTIONS DE PIÈCE
   ===============================================================================*/

#include "piece.h"

 // SETTEURS(2)

 // Modifie un des squares de la piece 
void piece::setPiece(int line, int col, const square& q) {
	assert(line >= 0 && line < 2);
	assert(col >= 0 && line < 2);
	_piece[line][col] = q;		// Tableau formé de squares
}

// Set les 4 valeurs bool des 4 squares de la pièce pour faire des formes diff.
void piece::setPieceActive(bool val1, bool val2, bool val3, bool val4) {
	_piece[0][0].setActive(val1);
	_piece[0][1].setActive(val2);
	_piece[1][0].setActive(val3);
	_piece[0][1].setActive(val4);
}

// GUETTEUR (1)
const square& piece::getPiece(int line, int col) const {
	assert(line >= 0 && line < 2);
	assert(col >= 0 && col < 2);
	return _piece[line][col];
}

// PROTOTYPE DES MÉTHODES PROPRES À L'OBJET PIECE (1)
void piece::draw(ostream& sortie)const {

	for (int i = 0; i < 2 ; i++)
		for (int j = 0; j < 2; j++) {
			if (_piece[i][j].isActive())		// Affichage des squares actifs seul.
				_piece[i][j].drawFull(sortie);
		}
}

// PROTOTYPE DES FONCTIONS PROPRES À L'OBJET SQUARE (1)
// Quand on veut AFFICHER UN PIÈCE en utilisant << 
// Ex.: cout << p1
// Attention! Fait appel à la méthode read()
ostream& operator<<(ostream& sortie, const piece& p){
		p.draw(sortie);
		return sortie;
}
