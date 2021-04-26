#include "point.h"

// LA D�FINITION DES CONSTRUCTEURS

// Constructeur SANS param�tres
// x et y � 0, sauf couleur � 15 (blanc)
point::point() {
	_x = _y = 0;
	_color = 15;
}

// Constructeur avec 2 param�tres
// La couleur a �t� �tablie � 15 par d�faut // blanc
point::point(int x, int y) {
	_x = x;
	_y = y;
	_color = 15;
}

//// Constructeur AVEC 3 param�tres dont 1 par d�faut
//// Initialis�s � la d�claration � x=0, y=0, color=15 (blanc)
//point::point(int x, int y, int color) {
//	_x = x;
//	_y = y;
//}

// Constructeur de COPIE 
// Quand on cr�e un point � partir d'un autre. Ex.: p2(p3)
point::point(const point& p) {
	_x = p._x;
	_y = p._y;
	_color = p._color;
}

// LA D�FINITION DU DESTRUCTEUR
point::~point() {
	_color = _x = _y = 0;	//= passser balayeuse avant de br�ler chalet, mais on se pratique.
};

// LA D�FINITION DES GETTEURS

// Retourne coord. de x
int point::getX()const {
	return _x;				
}

// Retourne coord. de y
int point::getY()const {
	return _y;				
}

// Retourne couleur (de 1 � 15, 0 �tant noir)
int point::getColor()const {
	return _color;			
}

// D�finition du setteur couleur 

// Modifie couleur (de 1 � 15, 0 �tant noir)
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

// Lire coordonn�es de x et de y
void point::read(istream& entree){
	char skip; // Pour ramasser les parenth�ses et le virgule ( , )
	entree >> skip >> _x >> skip >> _y >> skip;
}

// Gestion de l'OP�RATEUR �GAL-�GAL (comparaison)
// Retourne vrai si coordonn�es x et y sont �gales et faux sinon
bool point::operator==(const point& p) const{
	return _x == p._x && _y == p._y;
}

// Gestion de l'OP�RATEUR DIFF�RENT DE (comparaison)
// Retourne vrai si coordonn�es x et y sont �gales et faux sinon
bool point::operator!=(const point& p) const{
	return !(operator==(p));
}

// Gestion de l'OP�RATEUR �GAL (affectateur)
// Quand on cr�e un point �gal � un autre. Ex.: p2 = p3
const point& point::operator=(const point& p) {
	_x = p._x;
	_y = p._y;
	_color = p._color;

	return *this;	//  this = pointeur sur l'objet
					// *this = l'objet lui-m�me
}

// Gestion de l'OP�RATEUR SOMME (+)
// Quand on additionne 2 points. Ex.: p3 = p1 = p2
// Retour par valeur, car cr�ation d'une nouvelle valeur
point point::operator+(const point& p)const {
	return point(_x + p._x, _y + p._y);
}

// Gestion de l'OP�RATEUR DIFF�RENCE (-)
// Quand on soustrait 2 points. Ex.: p3 = p1 = p2
point point::operator-(const point& p)const {
	return point(_x - p._x, _y - p._y);
}

// Afficher un carr� pour repr�senter le point
void point::draw(ostream& sortie)const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
	gotoxy(_x, _y);
	sortie << "\xFE";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

// Fonction pour se positionner dans l'�cran � (x,y)
void gotoxy(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

// D�FINITION DES FONCTIONS AMIES

// Calcule de la distance entre 2 points (milieu)
float distance(const point& p1, const point& p2) {

	return sqrt(pow((p1._x + p2._x),2)* pow((p1._y + p2._y),2));
}

// D�FINITION DES FONCTIONS PROPRES � L'OBJET POINT

// Gestion de l'OP�RATEUR <<
// Quand on veut afficher un point par un flux  Ex.: cout << p1
// Attention! Fait appel � la m�thode print()
ostream& operator<<(ostream& sortie, const point& p) {
	p.print(sortie);
	return sortie;
}

// Gestion de l'OP�RATEUR >>
// Quand on veut lire un point par un flux Ex.: cin >> p1
// Attention! Fait appel � la m�thode read()
istream& operator>>(istream& entree, point& p) {
	p.read(entree);
	return entree;
}

