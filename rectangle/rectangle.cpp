
#include "rectangle.h"

// LA DÉFINITION DES CONSTRUCTEURS

// Constructeur SANS paramètres
rectangle::rectangle() {
	_w = _h = 0;	
}

// Constructeur avec 2 paramètres
// Coordonnées du point + hauteur et largeur intinitalisés à 0
rectangle::rectangle(int w, int h) {
	setWidth(w);
	setHeight(h);
}

//// Const. avec 4 para. dont 2 par défaut
//rectangle::rectangle(int x, int y, int w, int h) {
//	_w = w;
//	_h = h;
//}

// Constructeur avec 4 paramètres
// Coordonnées du point + hauteur et largeur
rectangle::rectangle(int x, int y, int w, int h) {
	_coord.setPosition(x, y);
	setWidth(w);
	setHeight(h);
}

// DESTRUCTEUR
rectangle::~rectangle() {
	_w = _h = 0;	//= passser balayeuse avant de brûler chalet, mais on se pratique.
};

// LA DÉFINITION DES GETTEURS (4)

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

// Retourne le rectangle lui-même (pos, w, h)
const rectangle& rectangle::getRectangle()const {
	return *this;
}

// LA DÉFINITION DES SETTEURS (5)

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

// Modifie le rectangle lui-même
void rectangle::setRectangle(int x, int y, int w, int h) {
	setDimension(w, h);
	_coord.setPosition(x,y);
}

// Afficher infos sur rectangle (coordonnées + w + h)
// au format (2,3) de 10X20
void rectangle::print(ostream& sortie)const{
	sortie << _coord << " de " << _w << "X" << _h;
}

// Lire infos sur rectangle (coordonnées + w + h)
// au format (2,3) 10X20
void rectangle::read(istream& entree){
	char skip; // Pour ramasser les parenthèses et le virgule ( , )
	entree >> _coord >> _w >>  skip >> _h;
}

// Gestion de l'OPÉRATEUR ÉGAL-ÉGAL (comparaison)
// Retourne vrai si coordonnées x et y + w + h sont égales et faux sinon
bool rectangle::operator==(const rectangle& r) const {
	return _coord == r._coord && _w == r._w && _h == r._h;
}

// Gestion de l'OPÉRATEUR DIFFÉRENT DE (comparaison)
// Retourne vrai si coordonnées x et y + w + h sont égales et faux sinon
bool rectangle::operator!=(const rectangle& r) const {
	return !(operator==(r));
}

// Gestion de l'OPÉRATEUR PLUS GRAND OU ÉGAL (comparaison)
// Retourne vrai si aire de r1 et plus grand ou égal à aire de r2, et faux sinon
bool rectangle::operator>=(const rectangle& r)const {
	return aire() >= r.aire();
}

// Gestion de l'OPÉRATEUR PLUS PETIT OU ÉGAL (comparaison)
// Retourne vrai si aire de r1 et plus petit ou égal à aire de r2, et faux sinon
bool rectangle::operator<=(const rectangle& r)const {
	return aire() <= r.aire();
}

// Gestion de l'OPÉRATEUR PLUS GRAND QUE (comparaison)
// Retourne vrai si aire de r1 et plus grand que aire de r2, et faux sinon
bool rectangle::operator>(const rectangle& r)const {
	return aire() > r.aire();
}

// Gestion de l'OPÉRATEUR PLUS PETIT QUE (comparaison)
// Retourne vrai si aire de r1 et plus petit que aire de r2, et faux sinon
bool rectangle::operator<(const rectangle& r)const {
	return aire() < r.aire();
}

// Afficher le rectangle sous forme de points consécutifs
void rectangle::draw(ostream& sortie)const {
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _coord.getColor());
	gotoxy(_coord.getX(), _coord.getY());	// Première ligne

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
	for (int i = 0; i < _w; i++) {			// Dernière ligne
		
		sortie << '*';
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Calcule et retourne le périmètre d'un rectangle
int rectangle::perimetre()const {
	return 2 * _w + 2 * _h;
}

// Calcule et retourne l'aire d'un rectangle
int rectangle::aire()const {
	return _w *_h;
}


// DÉFINITION DES FONCTIONS PROPRES À L'OBJET RECTANGLE

// Gestion de l'OPÉRATEUR <<
// Quand on veut afficher  les infos d'un rectangle par un flux  
// Ex.: cout << r1 affiche : (2,3) de 10X20
// Attention! Fait appel à la méthode print()
ostream& operator<<(ostream& sortie, const rectangle& r) {
	r.print(sortie);
	return sortie;
}

// Gestion de l'OPÉRATEUR >>
// Quand on veut lire les infos d'un rectangle par un flux  
// Ex.: cin >> r1
// IMPORTANT : Infos à saisir en console au format : (2,3) 10X20
// Attention! Fait appel à la méthode read()
istream& operator>>(istream& entree, rectangle& r) {
	r.read(entree);
	return entree;
}


