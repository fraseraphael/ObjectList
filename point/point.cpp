#include "point.h"

// LA DÉFINITION DES CONSTRUCTEURS

// Constructeur SANS paramètres
// x et y à 0, sauf couleur à 15 (blanc)
point::point() {
	_x = _y = 0;
	_color = 15;
}

// Constructeur avec 2 paramètres
// La couleur a été établie à 15 par défaut // blanc
point::point(int x, int y) {
	_x = x;
	_y = y;
	_color = 15;
}

//// Constructeur AVEC 3 paramètres dont 1 par défaut
//// Initialisés à la déclaration à x=0, y=0, color=15 (blanc)
//point::point(int x, int y, int color) {
//	_x = x;
//	_y = y;
//}

// Constructeur de COPIE 
// Quand on crée un point à partir d'un autre. Ex.: p2(p3)
point::point(const point& p) {
	_x = p._x;
	_y = p._y;
	_color = p._color;
}

// LA DÉFINITION DU DESTRUCTEUR
point::~point() {
	_color = _x = _y = 0;	//= passser balayeuse avant de brûler chalet, mais on se pratique.
};

// LA DÉFINITION DES GETTEURS

// Retourne coord. de x
int point::getX()const {
	return _x;				
}

// Retourne coord. de y
int point::getY()const {
	return _y;				
}

// Retourne couleur (de 1 à 15, 0 étant noir)
int point::getColor()const {
	return _color;			
}

// Définition du setteur couleur 

// Modifie couleur (de 1 à 15, 0 étant noir)
void point::setColor(int color) {
	assert(color >= 0 && color <= 15);
	_color = color;
}

// Modifie coord. de x
void point::setX(int x) {
	_x = x;
}

// Modifie coord. de y
void point::setY(int y) {
	_y = y;
}

// Modifie coord. de x et de y
void point::setPosition(int x, int y) {
	setX(x);
	setY(y);
}

// Afficher coord. de x et de y
void point::print(ostream& sortie) const{
	sortie << "(" << _x << ", " << _y << ")";
}

// Lire coordonnées de x et de y
void point::read(istream& entree){
	char skip; // Pour ramasser les parenthèses et le virgule ( , )
	entree >> skip >> _x >> skip >> _y >> skip;
}

// Gestion de l'OPÉRATEUR ÉGAL-ÉGAL (comparaison)
// Retourne vrai si coordonnées x et y sont égales et faux sinon
bool point::operator==(const point& p) const{
	return _x == p._x && _y == p._y;
}

// Gestion de l'OPÉRATEUR DIFFÉRENT DE (comparaison)
// Retourne vrai si coordonnées x et y sont égales et faux sinon
bool point::operator!=(const point& p) const{
	return !(operator==(p));
}

// Gestion de l'OPÉRATEUR ÉGAL (affectateur)
// Quand on crée un point égal à un autre. Ex.: p2 = p3
const point& point::operator=(const point& p) {
	_x = p._x;
	_y = p._y;
	_color = p._color;

	return *this;	//  this = pointeur sur l'objet
					// *this = l'objet lui-même
}

// Gestion de l'OPÉRATEUR SOMME (+)
// Quand on additionne 2 points. Ex.: p3 = p1 = p2
// Retour par valeur, car création d'une nouvelle valeur
point point::operator+(const point& p)const {
	return point(_x + p._x, _y + p._y);
}

// Gestion de l'OPÉRATEUR DIFFÉRENCE (-)
// Quand on soustrait 2 points. Ex.: p3 = p1 = p2
point point::operator-(const point& p)const {
	return point(_x - p._x, _y - p._y);
}

// Afficher un carré pour représenter le point
void point::draw(ostream& sortie)const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	gotoxy(_x, _y);
	sortie << "\xFE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Fonction pour se positionner dans l'écran à (x,y)
void gotoxy(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

// DÉFINITION DES FONCTIONS AMIES

// Calcule de la distance entre 2 points (milieu)
float distance(const point& p1, const point& p2) {

	return sqrt(pow((p1._x + p2._x),2)* pow((p1._y + p2._y),2));
}

// DÉFINITION DES FONCTIONS PROPRES À L'OBJET POINT

// Gestion de l'OPÉRATEUR <<
// Quand on veut afficher un point par un flux  Ex.: cout << p1
// Attention! Fait appel à la méthode print()
ostream& operator<<(ostream& sortie, const point& p) {
	p.print(sortie);
	return sortie;
}

// Gestion de l'OPÉRATEUR >>
// Quand on veut lire un point par un flux Ex.: cin >> p1
// Attention! Fait appel à la méthode read()
istream& operator>>(istream& entree, point& p) {
	p.read(entree);
	return entree;
}

