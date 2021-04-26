/*==================================================================================
Auteurs : Rapha�l Fraser et Marie-Claire Lewandowski
Projet : TP1 - Jeu du serpent
Nom du fichier : snake.h
Date : 2021-04-05
But : Objet snake constitu� d'un tableau de points (coord. x et y + couleur verte) 
	  pouvant �tre manipul� de diff�rentes fa�ons et affichable en console.
==================================================================================*/

// LES LIBRAIRIES
#pragma once		// �vite de r�inclure le iostream et autres librairies...
#include <iostream>	// Inclure le input et output
#include <cassert>	// Inclure le assert (robustesse -> setteurs)
#include "point.h"

using namespace std;

// LA CLASSE SNAKE
class snake {

private:					
												// Longueur max = aire-p�r.-apple
	point _snake[1079];							// Coord. de toutes les pos du snake
	int _size;									// Longueur du serpent

// PROTOTYPE DES M�THODES

public:
	snake();									// Const. sans param�tres
	snake(int x, int y);						// Const. avec 2 para. (coord. x, y)

	~snake();									// Destructeur

	void initialize(int x, int y);				// Init. serpent au centre plateau

	const point& getHeadPosition()const;		// Retourne pos. t�te du snake
	const point& getPosition(int ind)const;		// Retourne pos. snake � indice re�u
	const point& operator[](int ind)const;		// Appel le getteur de position
	int getSize()const;							// Retourne la taille du snake

	point newPosition(int dir);					// Retourne la pos. selon direction

	bool ifCollision(const point& pos) const;	// V�rif. s'il y a colliosion (V / F)
					
	void move(int dir);							// Avance snake selon dir.
	void eat(int dir);							// Mange apple selon dir.

	void draw(ostream& sortie);					// Affiche le snake console (vert)
};

// PROTOTYPE DES FONCTIONS PROPRES � L'OBJET SNAKE

// Gestion de l'OP�RATEUR <<
// Quand on veut afficher le snake en console en utilisant cout << s1
ostream& operator<<(ostream& sortie, snake& s);