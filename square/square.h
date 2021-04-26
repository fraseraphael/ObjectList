/*==================================================================================
Auteurs : Marie-Claire Lewandowski
Projet : Lab07-Jeu de Blokudoku
Nom du fichier : square.h
Date : 2021-04-08
But : Objet quare hérité de rectangle (objet) qui permet de manipuler et d'afficher 
des carrés composés de points (objet) de taille et de de couleurs différentes
(couleur intérieure et couleurs des bordures différentes). En en assemblant 
plusieurs, on peut créer des formes.
==================================================================================*/

#pragma once
#include <iostream>							// Permet le input et output
#include <cassert>							// Permet d'inclure les assert
#include "rectangle.h";						// Objet rectangle

class square: public rectangle{

	int _value;								// Numéro du carré/case
	bool _active;							// Pour déter. si case occupée ou non
	int _color;								// Couleur intérieure du carré (1 à 15)
	int _borderColor;						// Couleur bordure du carré (1 à 15)

public:

	square();								// Const. sans para. (tout à 0 ou false)
	square(int x, int y,  int side,			// Const. avec 6 para.(dont 4 par défaut) 
		int color = 0, int bdColor = 0, int value = 0, bool active=false);
	~square();								// Destructeur

	void setValue(int value);				// Setteur du numéro du carré/case
	void setColor(int color);				// Setteur couleur intérieure du carré
	void setBorderColor(int bdColor);		// Setteur couleur bordure du carré
	void setActive(bool active);			// Setteur dét. si case occupée ou non
	void setSquare(int x, int y,			// Setteur carré entier 7 var.
		 int side, int color=0, int bdColor=0, int value=0, bool active= false);	

	int getValue()const;					// Retourne numéro du carré/case
	int getColor()const;					// Retourne couleur intérieure du carré
	int getBorderColor()const;				// Retourne la couleur bordure du carré
	bool isActive()const;					// Retourne vrai si case occupée

	void draw(ostream& sortie) const;		// Aff. carré bleu + chiffre au centre
	void drawFull(ostream& sortie)const;	// Aff. carré bleu + carré jaune centre


};