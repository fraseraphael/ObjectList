/* =================================================================================
	DÉFINITION DES MÉTHODES DE SNAKE
   ===============================================================================*/

#include "snake.h"

// CONSTRUCTEURS (2)

// Constructeur SANS paramètres
// Init. position du serpent selon à (0,0)
snake::snake() {
	initialize(0, 0);						// Init. snake à position (0,0)
}

// Constructeur avec 2 paramètres
// Init. position du serpent selon une coordonnée reçue (x et y)
snake::snake(int x, int y) {
	initialize(x, y);						// Init. snake à position reçue (x,y)
}

// DESTRUCTEUR (1)
snake::~snake() {
	_size = 0;                              // Remise de la taille du serpent à 0
}

// SETTEUR (1)
void snake::initialize(int x, int y) {

	_size = 6;                              // Longueur snake par défaut à 6
    assert(_size < 1079);                   // Taille max définie dans la classe

	gotoxy(x, y);                           // Position du snake sur le plateau

	for (int i = 0; i < _size; i++) {
		_snake[i].setColor(2);              // Couleur point à vert (2)
		_snake[i].Position(x + i + 1, y);   // Init. pos. snake à (0,0)
	}
}

// GETTEURS (4)

// Retourne la position de la tête du snake[0]
const point& snake::getHeadPosition()const {
	return _snake[0];
}

// Retourne la position du snake à l'indice reçu
const point& snake::getPosition(int ind)const {
	return _snake[ind];
}

// Gestion de l'OPÉRATEUR CROCHET []
// Permet d'utiliser snake[ind] et de retourner la pos à l'indice reçu
const point& snake::operator[](int ind)const {
	return getPosition(ind);
}

// Retourne la taille du snake
int snake::getSize()const {
	return _size;
}

// AUTRES MÉTHODES SPÉCIFIQUES À L'OBJET SNAKE (5)

// Retourne la position de la tête du snake (point = neeHead)
// Selon la direction choisie par le joueur (flèches)
point snake::newPosition(int dir) {

        point newHead = _snake[0];

        switch (dir)
        {
        case 1:  // LEFT                   
            newHead.setX(newHead.getX() - 1);
            break;
        case 2: // RIGHT
            newHead.setX(newHead.getX() + 1);
            break;
        case 3: // UP
            newHead.setY(newHead.getY() - 1);
            break;
        case 4: // DOWN
            newHead.setY(newHead.getY() + 1);
            break;
        }
        return newHead;
}

// RETOURNE VRAI SI la position de la tête du snake entre en COLLISION 
// avec son corps ou les limites du plateau de jeu, sinon, retourne faux
bool snake::ifCollision(const point& pos) const {

    for (int i = 0; i < _size; i++)
    {
        if (pos == _snake[i])
            return true;
    }
    return false;
}

// AVANCE le snake dans la bonne direction
// Depuis l'emplacement de la tête on détermine la position du reste du corps
void snake::move(int dir) {

    point newHead = newPosition(dir);       // On part de la pos. de la tête

    for (int i = _size - 1; i >= 0; i--)    // On définit les pos. du corps
    {
        _snake[i + 1] = _snake[i];
    }
    _snake[0] = newHead;                    // On redéfinit pos. tête
}

// Permet d'augmenter la taille du snake quand sa tête rencontre une APPLE
void snake::eat(int dir) {
    move(dir);
    _size++;
}

// Permet d'afficher le snake en console (en vert)
void snake::draw(ostream& sortie) {

    for (int i = 0; i < _size; i++)
        _snake[i].draw(sortie);

    if (_snake[_size].getX() != 0) {
        _snake[_size].setColor(0);
        _snake[_size].draw(sortie);
    }    
}

// DÉFINITION DES FONCTIONS PROPRES À L'OBJET SNAKE

// Gestion de l'OPÉRATEUR <<
// Quand on veut afficher le snake en console en utilisant cout << s1
ostream& operator<<(ostream& sortie, snake& s) {

    s.draw(sortie);
    return sortie;
}


