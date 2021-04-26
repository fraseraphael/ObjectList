/*=============================================================================================
Auteur : Raphaël Fraser
Projet : Lab06
Nom du fichier : rectangle.h
Date : 2021-03-11
But : Un rectangle est composé d'un point d'orgine (supérieur gauche) ainsi qu'une largeur et hauteur
	permettant de le manipuler et de le dessiner en console.
===============================================================================================*/

// LES LIBRAIRIES
#pragma once		// Permet d'éviter de réinclure le iostream et autres librairies...
#include <iostream>	// Permet le input et output
#include "point.h"
#include <cassert>	// Permet d'inclure le assert (robustesse -> setteurs)
using namespace std;

// LA CLASSE RECTANGLE
class rectangle {

protected:				// Données privées par défaut

	point _coord;		// Coordonnées du point
	int _w,				// Largeur du rectangle
		_h;				// Hauteur du rectangle

// PROTOTYPES DES MÉTHODES (fonctions membres, interfaces de l'objet = syn)
public:

	rectangle();						// Const. sans para.
	rectangle(int w, int h);			// Const. avec 2 para.
	//									// Const. avec 4 para. dont 2 par défaut
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
										
	void setPosition(int x, int y);		// Setteur coordonées
										// Setteur coordonnées + hauteur + largeur
	void setRectangle(int x, int y, int w, int h);

	void print(ostream& sortie)const;	// Afficher infos rectangle par flux
	void read(istream& entree);

										// Vérifier si égal-égal (V ou F)
	bool operator==(const rectangle& r)const;	
										// Vérifier si différent (V ou F)
	bool operator!=(const rectangle& r)const;	
										// Vérifier si aire plus grand ou égal (V ou F)
	bool operator>=(const rectangle& r)const;
										// Vérifier si aire plus petit ou égal (V ou F)
	bool operator<=(const rectangle& r)const;
										// Vérifier si aire plus grand (V ou F)
	bool operator>(const rectangle& r)const;
										// Vérifier si aire plus petit (V ou F)
	bool operator<(const rectangle& r)const;

	void draw(ostream& sortie)const;

	int perimetre()const;				// Calculer perimetre rectangle
	int aire()const;					// Calculer aire rectangle
};

// PROTOTYPE DES FONCTIONS PROPRES À L'OBJET RECTANGLE

// Fonction d'affichage des infos du rectangle
// soit coordonnées + w + h par cout << p
ostream& operator<<(ostream& sortie, const rectangle& r);

// Fonction de lecture des infos du rectangle
// soit coordonnées + w + h par cin >> p
// Saisir au format : 
istream& operator>>(istream& entree, rectangle& r);