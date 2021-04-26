
#include "rectangle.h"

// LA D�FINITION DES CONSTRUCTEURS

// Constructeur SANS param�tres
rectangle::rectangle() {
	_w = _h = 0;	
}

// Constructeur avec 2 param�tres
// Coordonn�es du point + hauteur et largeur intinitalis�s � 0
rectangle::rectangle(int w, int h) {
	setWidth(w);
	setHeight(h);
}

//// Const. avec 4 para. dont 2 par d�faut
//rectangle::rectangle(int x, int y, int w, int h) {
//	_w = w;
//	_h = h;
//}

// Constructeur avec 4 param�tres
// Coordonn�es du point + hauteur et largeur
rectangle::rectangle(int x, int y, int w, int h) {
	_coord.setPosition(x, y);
	setWidth(w);
	setHeight(h);
}

// DESTRUCTEUR
rectangle::~rectangle() {
	_w = _h = 0;	//= passser balayeuse avant de br�ler chalet, mais on se pratique.
};

// LA D�FINITION DES GETTEURS (4)

// Retourne largeur du rectangle
int rectangle::getWidth()const {
	return _w;
}

// Retourne hauteur du rectangle
int rectangle::getHeight()const {
	return _h;
}

// Retourne la position du point
point& rectangle::getPosition() {
	return _coord;
}

// Retourne le rectangle lui-m�me (pos, w, h)
const rectangle& rectangle::getRectangle()const {
	return *this;
}

// LA D�FINITION DES SETTEURS (5)

// Modifie la largeur du rectangle
void rectangle::setWidth(int w) {
	assert(w >= 0);
	_w = w;
}

// Modifie la hauteur du rectangle
void rectangle::setHeight(int h) {
	assert(h >= 0);
	_h = h;
}

// Modifie la taille du rectangle (hauteur + largeur)
void rectangle::setDimension(int w, int h) {
	setWidth(w);
	setHeight(h);
}

// Modifie la position du point
void rectangle::setPosition(int x, int y) {
	assert(x >= 0);
	assert(y >= 0);
	_coord.setPosition(x,y);
}

// Modifie le rectangle lui-m�me
void rectangle::setRectangle(int x, int y, int w, int h) {
	setDimension(w, h);
	_coord.setPosition(x,y);
}

// Afficher infos sur rectangle (coordonn�es + w + h)
// au format (2,3) de 10X20
void rectangle::print(ostream& sortie)const{
	sortie << _coord << " de " << _w << "X" << _h;
}

// Lire infos sur rectangle (coordonn�es + w + h)
// au format (2,3) 10X20
void rectangle::read(istream& entree){
	char skip; // Pour ramasser les parenth�ses et le virgule ( , )
	entree >> _coord >> _w >>  skip >> _h;
}

// Gestion de l'OP�RATEUR �GAL-�GAL (comparaison)
// Retourne vrai si coordonn�es x et y + w + h sont �gales et faux sinon
bool rectangle::operator==(const rectangle& r) const {
	return _coord == r._coord && _w == r._w && _h == r._h;
}

// Gestion de l'OP�RATEUR DIFF�RENT DE (comparaison)
// Retourne vrai si coordonn�es x et y + w + h sont �gales et faux sinon
bool rectangle::operator!=(const rectangle& r) const {
	return !(operator==(r));
}

// Gestion de l'OP�RATEUR PLUS GRAND OU �GAL (comparaison)
// Retourne vrai si aire de r1 et plus grand ou �gal � aire de r2, et faux sinon
bool rectangle::operator>=(const rectangle& r)const {
	return aire() >= r.aire();
}

// Gestion de l'OP�RATEUR PLUS PETIT OU �GAL (comparaison)
// Retourne vrai si aire de r1 et plus petit ou �gal � aire de r2, et faux sinon
bool rectangle::operator<=(const rectangle& r)const {
	return aire() <= r.aire();
}

// Gestion de l'OP�RATEUR PLUS GRAND QUE (comparaison)
// Retourne vrai si aire de r1 et plus grand que aire de r2, et faux sinon
bool rectangle::operator>(const rectangle& r)const {
	return aire() > r.aire();
}

// Gestion de l'OP�RATEUR PLUS PETIT QUE (comparaison)
// Retourne vrai si aire de r1 et plus petit que aire de r2, et faux sinon
bool rectangle::operator<(const rectangle& r)const {
	return aire() < r.aire();
}

// Afficher le rectangle sous forme de points cons�cutifs
void rectangle::draw(ostream& sortie)const {
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _coord.getColor());
	gotoxy(_coord.getX(), _coord.getY());	// Premi�re ligne

	for (int i = 0; i < _w; i++) {
		sortie << '*';
	}

	for (int i = 0; i < _h - 2; i++) {		// Lignes du centre

		gotoxy(_coord.getX(), _coord.getY()+i+1);
		sortie << '*';

		for (int j = 0; j < _w - 2; j++) {
			sortie << " ";
		}
		sortie << '*';
	}

	gotoxy(_coord.getX(), _coord.getY() + _h - 1);
	for (int i = 0; i < _w; i++) {			// Derni�re ligne
		
		sortie << '*';
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Calcule et retourne le p�rim�tre d'un rectangle
int rectangle::perimetre()const {
	return 2 * _w + 2 * _h;
}

// Calcule et retourne l'aire d'un rectangle
int rectangle::aire()const {
	return _w *_h;
}


// D�FINITION DES FONCTIONS PROPRES � L'OBJET RECTANGLE

// Gestion de l'OP�RATEUR <<
// Quand on veut afficher  les infos d'un rectangle par un flux  
// Ex.: cout << r1 affiche : (2,3) de 10X20
// Attention! Fait appel � la m�thode print()
ostream& operator<<(ostream& sortie, const rectangle& r) {
	r.print(sortie);
	return sortie;
}

// Gestion de l'OP�RATEUR >>
// Quand on veut lire les infos d'un rectangle par un flux  
// Ex.: cin >> r1
// IMPORTANT : Infos � saisir en console au format : (2,3) 10X20
// Attention! Fait appel � la m�thode read()
istream& operator>>(istream& entree, rectangle& r) {
	r.read(entree);
	return entree;
}


