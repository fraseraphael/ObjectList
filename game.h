/*==================================================================================
Auteurs : Raphaël Fraser et Marie-Claire Lewandowski
Projet : TP1 - Jeu du serpent
Nom du fichier : game.h
Date : 2021-03-25
But : Objet game, c'est le jeu snake en console qui permet de déplacer dans toutes les directions
et de manger des pommes sans frapper les mures ou lui-même
==================================================================================*/


// LES LIBRAIRIES
#pragma once				// Évite de réinclure le iostream et autres librairies...
#include "rectangle.h"		
#include "point.h"
#include "apple.h"
#include "snake.h"
#include <iostream>			// Inclure le input et output
#include <windows.h>
#include <conio.h>			
#include <time.h>

using namespace std;


// LA CLASSE GAME
class game
{

private:
	bool _gameOver;					//Si la game fini

	int _cptLife,					//Compteur de vie
		_score,						//Score du jeu
		_dir;						//Direction choisie
							
	snake _snake;					//le Snake 
	apple _apple;					//la pomme
								
	rectangle _plateau;				//Rectangle du jeu
	const int _width = 60;			//Largeur du rectangle
	const int _height = 20;			//Hauteur du rectangle

	
	enum direction { STOP, LEFT, RIGHT, UP, DOWN, NONE };	//Liste des direction possible
	
	// PROTOTYPE DES MÉTHODES

public:
	game(); 
	~game();
	void initialize();

	int getScore()const;				//retourne le score (seule info	qui	pourrait être intéressante
										//de l’extérieur) et aucun setteur pour	cet	objet.

	point randPosition()const;			//génère une nouvelle position aléatoire ds	le terrain
	void createApple();					//génère une nouvelle pomme	tq position	est	ds le snake
	void play();						//la main loop du jeu

	void drawScreen();
	void inputKey();					//la saisie	des	touches	pour le	déplacement	du	snake
	bool canMove(const point &newHead)const;				//retourne vrai si la tête du snake peut bouger
	

	void printScore(ostream& sortie)const;		//affiche le score
	void printLife(ostream& sortie)const;		//affiche le compteur de vie
	void printEndGame(ostream& sortie)const;	//affiche game over et le score
};

