
/* =================================================================================
	DÉFINITION DES MÉTHODES ET DES FONCTIONS DE SQUARE
   ===============================================================================*/

#include "square.h"

// CONSTRUCTEURS (2)

// Constructeur SANS paramètres
square::square() {
	_value = _color = _borderColor = 0;
	_active = false;
}

// Constructeur 7 paramètres, dont 4 par défaut
// Seules les coordonnées de x et y ne sont pas par défaut
// Les 4 autres variables sont à 0 ou false
square::square(int x, int y, int side, int color, int bdColor, int value, bool active) {
	setSquare(x, y, side, color, bdColor, value, active);
}

// DESTRUCTEUR (1)
square::~square() {
	//_coord.setPosition(0, 0);				// Remise de tous les par. à 0 ou à false
	_value = _color = _borderColor = 0;
	_active = false;
}

// SETTEURS (5)

// Modifie le numéro du carré/case
void square::setValue(int value) {
	_value = value;
}

// Modifie la couleur intérieure du carré
void square::setColor(int color) {
	assert(color >= 0 && color <= 15);		
	_color = color;
}

// Modifie la couleur de la bordure/contour du carré
void square::setBorderColor(int bdColor) {
	assert(bdColor >= 0 && bdColor <= 15);	
	_borderColor = bdColor;
}

// Modifie la valeur booléenne de la variable _active  
// qui permet de déterminer si un emplacement est déjà occupé ou non par un carré
void square::setActive(bool active) {
	_active = active;
}

// Modifie les var. du carré entier, dont la position (x,y) et taille d'un côté
// Autres var. à 0 (value = _color = _borderColor) ou à false (_active)
void square::setSquare(int x, int y, int side, 
	int color, int bdColor, int value, bool active) {
	
	setPosition(x, y);						// Pt d'origine du carré en haut à gauche
	setDimension(side, side);				// Taille côtés carré
	setColor(color);						// Couleur intérieure carré init. à 0
	setBorderColor(bdColor);				// Couleur bordure carré init. à 0
	setValue(value);						// Numéro carré/case init. à 0
	setActive(active);						// Dispo emplacement intit. à false
}

// GETTEURS (4)

// Retourne le numéro du carré/case
int square::getValue()const {
	return _value;
}

// Retourne la couleur intérieure du carré
int square::getColor()const {
	return _color;
}

// Retourne la couleur de la bordure du carré
int square::getBorderColor()const {
	return _borderColor;
}

// Retourne vrai si case déjà occupée et faux sinon
bool square::isActive()const {
	return _active;
}

// Dessine un carré de bordures bleues (9) avec le chiffre 1 dedans. 
// Représente un carré vide
void square::draw(ostream& sortie)const {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

	gotoxy(_coord.getX(), _coord.getY());	// Bordure du carré ligne du haut

	for (int i = 0; i < _w; i++) {
		sortie << "\xFE ";
	}

	for (int i = 0; i < _h - 2; i++) {		

		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		sortie << "\xFE";					// Bordure carré ligne de gauche

	
		for (int j = 0; j < _w - 2; j++) {	// Carré au centre (constitué de pts)
			sortie << "  ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
		sortie << " \xFE";					// Bordure carré ligne de droite
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++) {			// Bordure du carré ligne du bas
		sortie << "\xFE ";
	}

	gotoxy(_coord.getX() + _w - 1, _coord.getY() + _h / 2);
	cout << getValue();						// Chiffre au centre du carré

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Dessine un carré de bordures bleues (9) formées de petits carré consécutifs 
// avec un carré interne constitué de petits carrés de couleur jaune (6)
// Représente un carré plein
void square::drawFull(ostream& sortie)const {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

	gotoxy(_coord.getX(), _coord.getY());	// Bordure du carré ligne du haut

	for (int i = 0; i < _w; i++) {
		sortie << "\xFE ";
	}

	for (int i = 0; i < _h - 2; i++) {

		gotoxy(_coord.getX(), _coord.getY() + i + 1);
		sortie << "\xFE";					// Bordure carré ligne de gauche

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
		for (int j = 0; j < _w - 2; j++) {	// Carré au centre (constitué de pts)
			sortie << " \xFE";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
		sortie << " \xFE";					// Bordure carré ligne de droite
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++) {			// Bordure du carré ligne du bas

		sortie << "\xFE ";
	}

	if (_value != 0) {						// Affichage du chiffre au centre

		gotoxy(_coord.getX() + _h - 1, _coord.getY() + _h / 2);
		cout << _value;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}



