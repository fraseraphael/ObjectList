/*==================================================================================
Auteurs : Marie-Claire Lewandowski
Projet : Lab07-Jeu de Blokudoku
Nom du fichier : square.h
Date : 2021-04-08
But : Objet quare h�rit� de rectangle (objet) qui permet de manipuler et d'afficher 
des carr�s compos�s de points (objet) de taille et de de couleurs diff�rentes
(couleur int�rieure et couleurs des bordures diff�rentes). En en assemblant 
plusieurs, on peut cr�er des formes.
==================================================================================*/

#pragma once
#include <iostream>							// Permet le input et output
#include <cassert>							// Permet d'inclure les assert
#include "rectangle.h";						// Objet rectangle

class square: public rectangle{

	int _value;								// Num�ro du carr�/case
	bool _active;							// Pour d�ter. si case occup�e ou non
	int _color;								// Couleur int�rieure du carr� (1 � 15)
	int _borderColor;						// Couleur bordure du carr� (1 � 15)

public:

	square();								// Const. sans para. (tout � 0 ou false)
	square(int x, int y,  int side,			// Const. avec 6 para.(dont 4 par d�faut) 
		int color = 0, int bdColor = 0, int value = 0, bool active=false);
	~square();								// Destructeur

	void setValue(int value);				// Setteur du num�ro du carr�/case
	void setColor(int color);				// Setteur couleur int�rieure du carr�
	void setBorderColor(int bdColor);		// Setteur couleur bordure du carr�
	void setActive(bool active);			// Setteur d�t. si case occup�e ou non
	void setSquare(int x, int y,			// Setteur carr� entier 7 var.
		 int side, int color=0, int bdColor=0, int value=0, bool active= false);	

	int getValue()const;					// Retourne num�ro du carr�/case
	int getColor()const;					// Retourne couleur int�rieure du carr�
	int getBorderColor()const;				// Retourne la couleur bordure du carr�
	bool isActive()const;					// Retourne vrai si case occup�e

	void draw(ostream& sortie) const;		// Aff. carr� bleu + chiffre au centre
	void drawFull(ostream& sortie)const;	// Aff. carr� bleu + carr� jaune centre


};