
/* =================================================================================
	D�FINITION DES M�THODES ET DES FONCTIONS DE SQUARE
   ===============================================================================*/

#include "square.h"

// CONSTRUCTEURS (2)

// Constructeur SANS param�tres
square::square() {
	_value = _color = _borderColor = 0;
	_active = false;
}

// Constructeur 7 param�tres, dont 4 par d�faut
// Seules les coordonn�es de x et y ne sont pas par d�faut
// Les 4 autres variables sont � 0 ou false
square::square(int x, int y, int side, int color, int bdColor, int value, bool active) {
	setSquare(x, y, side, color, bdColor, value, active);
}

// DESTRUCTEUR (1)
square::~square() {
	//_coord.setPosition(0, 0);				// Remise de tous les par. � 0 ou � false
	_value = _color = _borderColor = 0;
	_active = false;
}

// SETTEURS (5)

// Modifie le num�ro du carr�/case
void square::setValue(int value) {
	_value = value;
}

// Modifie la couleur int�rieure du carr�
void square::setColor(int color) {
	assert(color >= 0 && color <= 15);		
	_color = color;
}

// Modifie la couleur de la bordure/contour du carr�
void square::setBorderColor(int bdColor) {
	assert(bdColor >= 0 && bdColor <= 15);	
	_borderColor = bdColor;
}

// Modifie la valeur bool�enne de la variable _active  
// qui permet de d�terminer si un emplacement est d�j� occup� ou non par un carr�
void square::setActive(bool active) {
	_active = active;
}

// Modifie les var. du carr� entier, dont la position (x,y) et taille d'un c�t�
// Autres var. � 0 (value = _color = _borderColor) ou � false (_active)
void square::setSquare(int x, int y, int side, 
	int color, int bdColor, int value, bool active) {
	
	setPosition(x, y);						// Pt d'origine du carr� en haut � gauche
	setDimension(side, side);				// Taille c�t�s carr�
	setColor(color);						// Couleur int�rieure carr� init. � 0
	setBorderColor(bdColor);				// Couleur bordure carr� init. � 0
	setValue(value);						// Num�ro carr�/case init. � 0
	setActive(active);						// Dispo emplacement intit. � false
}

// GETTEURS (4)

// Retourne le num�ro du carr�/case
int square::getValue()const {
	return _value;
}

// Retourne la couleur int�rieure du carr�
int square::getColor()const {
	return _color;
}

// Retourne la couleur de la bordure du carr�
int square::getBorderColor()const {
	return _borderColor;
}

// Retourne vrai si case d�j� occup�e et faux sinon
bool square::isActive()const {
	return _active;
}

// Dessine un carr� de bordures bleues (9) avec le chiffre 1 dedans. 
// Repr�sente un carr� vide
void square::draw(ostream& sortie)const {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

	gotoxy(_coord.getX(), _coord.getY());	// Bordure du carr� ligne du haut

	for (int i = 0; i < _w; i++) {
		sortie << "\xFE ";
	}

	for (int i = 0; i < _h - 2; i++) {		

		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		sortie << "\xFE";					// Bordure carr� ligne de gauche

	
		for (int j = 0; j < _w - 2; j++) {	// Carr� au centre (constitu� de pts)
			sortie << "  ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
		sortie << " \xFE";					// Bordure carr� ligne de droite
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++) {			// Bordure du carr� ligne du bas
		sortie << "\xFE ";
	}

	gotoxy(_coord.getX() + _w - 1, _coord.getY() + _h / 2);
	cout << getValue();						// Chiffre au centre du carr�

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Dessine un carr� de bordures bleues (9) form�es de petits carr� cons�cutifs 
// avec un carr� interne constitu� de petits carr�s de couleur jaune (6)
// Repr�sente un carr� plein
void square::drawFull(ostream& sortie)const {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

	gotoxy(_coord.getX(), _coord.getY());	// Bordure du carr� ligne du haut

	for (int i = 0; i < _w; i++) {
		sortie << "\xFE ";
	}

	for (int i = 0; i < _h - 2; i++) {

		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		sortie << "\xFE";					// Bordure carr� ligne de gauche

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
		for (int j = 0; j < _w - 2; j++) {	// Carr� au centre (constitu� de pts)
			sortie << " \xFE";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
		sortie << " \xFE";					// Bordure carr� ligne de droite
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++) {			// Bordure du carr� ligne du bas

		sortie << "\xFE ";
	}

	if (_value != 0) {						// Affichage du chiffre au centre

		gotoxy(_coord.getX() + _h - 1, _coord.getY() + _h / 2);
		cout << _value;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}



