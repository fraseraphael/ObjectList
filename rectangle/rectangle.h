/*=============================================================================================
Auteur : Rapha�l Fraser
Projet : Lab06
Nom du fichier : rectangle.h
Date : 2021-03-11
But : Un rectangle est compos� d'un point d'orgine (sup�rieur gauche) ainsi qu'une largeur et hauteur
	permettant de le manipuler et de le dessiner en console.
===============================================================================================*/

// LES LIBRAIRIES
#pragma once		// Permet d'�viter de r�inclure le iostream et autres librairies...
#include <iostream>	// Permet le input et output
#include "point.h"
#include <cassert>	// Permet d'inclure le assert (robustesse -> setteurs)
using namespace std;

// LA CLASSE RECTANGLE
class rectangle {

protected:				// Donn�es priv�es par d�faut

	point _coord;		// Coordonn�es du point
	int _w,				// Largeur du rectangle
		_h;				// Hauteur du rectangle

// PROTOTYPES DES M�THODES (fonctions membres, interfaces de l'objet = syn)
public:

	rectangle();						// Const. sans para.
	rectangle(int w, int h);			// Const. avec 2 para.
	//									// Const. avec 4 para. dont 2 par d�faut
	//rectangle(int x, int y, int w = 0, int h = 0);
										// Const. avec 4 para.
	rectangle(int x, int y, int w, int h);		

	~rectangle();						// Destructeur

	int getWidth()const;				// Guetteur largeur
	int getHeight()const;				// Guetteur hauteur
	point& getPosition();				// Guetteur emplacement du point
										// Guetteur emplacement point et hauteur et largeur
	const rectangle& getRectangle()const;		

	
	void setWidth(int w);				// Setteur de largeur
	void setHeight(int h);				// Setteur de hauteur
	void setDimension(int w, int h);			// Setteur de hauteur et largeur
										
	void setPosition(int x, int y);		// Setteur coordon�es
										// Setteur coordonn�es + hauteur + largeur
	void setRectangle(int x, int y, int w, int h);

	void print(ostream& sortie)const;	// Afficher infos rectangle par flux
	void read(istream& entree);

										// V�rifier si �gal-�gal (V ou F)
	bool operator==(const rectangle& r)const;	
										// V�rifier si diff�rent (V ou F)
	bool operator!=(const rectangle& r)const;	
										// V�rifier si aire plus grand ou �gal (V ou F)
	bool operator>=(const rectangle& r)const;
										// V�rifier si aire plus petit ou �gal (V ou F)
	bool operator<=(const rectangle& r)const;
										// V�rifier si aire plus grand (V ou F)
	bool operator>(const rectangle& r)const;
										// V�rifier si aire plus petit (V ou F)
	bool operator<(const rectangle& r)const;

	void draw(ostream& sortie)const;

	int perimetre()const;				// Calculer perimetre rectangle
	int aire()const;					// Calculer aire rectangle
};

// PROTOTYPE DES FONCTIONS PROPRES � L'OBJET RECTANGLE

// Fonction d'affichage des infos du rectangle
// soit coordonn�es + w + h par cout << p
ostream& operator<<(ostream& sortie, const rectangle& r);

// Fonction de lecture des infos du rectangle
// soit coordonn�es + w + h par cin >> p
// Saisir au format : 
istream& operator>>(istream& entree, rectangle& r);