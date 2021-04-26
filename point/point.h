/*=============================================================================================
Auteur : Raphael Fraser
Projet : Lab06
Nom du fichier :point.h
Date : 2021-03-11
But : Objet point => objet avec coordonn�es (x,y) et une couleur pour affichage en console
===============================================================================================*/

// LES LIBRAIRIES
#pragma once		// Permet d'�viter de r�inclure le iostream et autres librairies...
#include <iostream>	// Permet le input et output
#include <cassert>	// Permet d'inclure le assert (robustesse -> setteurs)
#include <windows.h>// Permer utiliser setConsoleAttribute
using namespace std;

// LA CLASSE POINT
class point {

private:		// Donn�es priv�es par d�faut

	int _x,		// Coordonn�es du point
		_y,		
	 _color;	// Couleur du point en console (1 � 15)

// PROTOTYPES DES M�THODES (fonctions membres, interfaces de l'objet = syn)
public:
	point();								// Const. sans param�tres
	point(int x, int y);					// Const. avec 2 para.
//point(int x=0, int y=0, int color=15);	// Const. avec 3 para. par d�faut
	point(const point& p);					// Const. de copie
	~point();								// Destructeur

	int getColor()const;					// Guetteurs de couleur
	int getX()const;						// Guetteurs de x
	int getY()const;						// Guetteurs de y
	
	void setColor(int color);				// Setteurs de couleur
	void setX(int x);						// Setteur de x
	void setY(int y);						// Setteur de y
	void setPosition(int x, int y);				// Setteur de x ET y

	void print(ostream& sortie) const;		// Afficher point par un flux (cout)
	void read(istream& entree);				// Lire point par un flux (cin)
	
	bool operator==(const point& p)const;	// V�rifier si �gal-�gal (vrai ou faux)
	bool operator!=(const point& p)const;	// V�rifier si diff�rent (vrai ou faux)
	const point& operator=(const point& p);	// Affecter valeur (gr�ce au =)
	
	point operator+(const point& p)const;	// Faire somme (+)
	point operator-(const point& p)const;	// Faire diff�rence (-)
											// Afficher un carr�
	void draw(ostream& sortie)const;			
											// Calculer distance entre 2 points (milieu)
	friend float distance(const point& p1, const point& p2); 

};

// PROTOTYPE DES FONCTIONS PROPRES � L'OBJET POINT

// Fonction d'affichage du point (cout << p)
ostream& operator<<(ostream& sortie, const point& p);

// Fonction de saisie du point (cin >> p)
istream& operator>>(istream& entree, point& p);

// Afficher le carr� � la bonne position
void gotoxy(int xpos, int ypos);		

