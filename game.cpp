/* =================================================================================
	DÉFINITION DES MÉTHODES DE GAME
	===============================================================================*/

#include "game.h"

// CONSTRUCTEURS (1)
// Init. les variables a 0
game::game()
{
	_score = _dir = _gameOver = _cptLife = 0;	// Init. les variables a 0
}

// DESTRUCTEUR (1)

game::~game()
{
	_cptLife = _score = _gameOver = _dir = 0;	// Init. les variables a 0
}

// GETTEURS (1)

// Retourne le score de la partie
int game::getScore()const
{
	return _score;
}

// AUTRES MÉTHODES SPÉCIFIQUES À L'OBJET GAME (7)

// Init. les variables pour une partie jouable
void game::initialize()
{
	_cptLife = 3;							// Partie ayant 3 vie 
	_score = 0;								// Score commence a 0
	_dir = LEFT;							// Direction de commencement du snake

	_plateau.setSize(_width, _height);		// Plateau de jeu
	_plateau.getPosition().setColor(15);	// Couleur du bord de jeu blanc
	_plateau.draw(cout);

	srand(time(NULL));						// Pour les randoms du reste du code

	drawScreen();							
	createApple();
}

// Génère un point à une position aléatoire dans le plateau de jeu
point game::randPosition()const
{
	int randX = rand() % (_width - 2) + 1;
	int randY = rand() % (_height - 2) + 1;

	point p(randX, randY);
	return p;
}

// Crée une pomme situé dans le plateau de jeu de manière aléatoire
void game::createApple()
{
	do				// S'assure que la pomme ne sera pas générer sur le snake
	{	
		point p = randPosition();
		_apple.setPosition(p.getX(), p.getY());
	} while (_snake.ifCollision(_apple.getPosition()));		

	_apple.draw(cout);	
}

// Methode d'une partie du jeu de snake
void game::play()
{
	initialize();
	while (!_gameOver)			// Loop principale du jeu
	{
		printScore(cout);
		inputKey();				// Input du joueur - direction ou exit

		if (_dir != STOP)			// Si la direction n'est pas a STOP
		{
			point newHead = _snake.newPosition(_dir);

			if (!canMove(newHead))	// Si le snake ne peut pas bouger
			{
				_cptLife--;			// Faire perdre une vie 
				printLife(cout);

				if (_cptLife == 0)	// Si le snake n'a plus de vie alors GameOver
				{
					_gameOver = true;
				}
				else
				{
					drawScreen();
					createApple();
					_dir = LEFT;
				}

			}
			// Si la nouvelle position est celle de la pomme	
			else if (newHead == _apple.getPosition())	
			{
				_snake.eat(_dir);	// Mange la pomme	
				_score++;			// Gagne un point

				printScore(cout);
				createApple();		// Crée une nouvelle pomme
			}
			else
			{
				_snake.move(_dir);
			}
			cout << _snake;
			Sleep(100);				// Temps d'attente avant le prochain mouvement
		}
	}

	printEndGame(cout);
}

// Affiche l'interface de jeu - plateau, nb vies, score et place le snake au centre  
void game::drawScreen() 
{
	system("cls"); 

	_plateau.draw(cout);
	printScore(cout);
	printLife(cout);

	_snake.initialize(_width / 2, _height / 2);
	cout << _snake;
}

// Saisie des touches du joueur
void game::inputKey() {				
	int touche;
	if (_kbhit()) {					// Si une touche est appuyée
		touche = _getch();			// Saisie la touche
		if (touche == 'q') {		// Si la touche est q, on veut arrêter le jeu
			_gameOver = true;
			_dir = STOP;
		}
		else if (touche == 224) {	// Si la touche est 224, c’est une flèche
			touche = _getch();		
			switch (touche) {
			case 75:				// Code ascii des flèches
				_dir = LEFT;
				break;
			case 72:
				_dir = UP;
				break;
			case 80:
				_dir = DOWN;
				break;
			case 77:
				_dir = RIGHT;
			}
		}
	}
}

// Retourne true si le snake peut bouger (pas bloquer par lui même ou le border)
bool game::canMove(const point& newHead)const
{
	if (newHead.getX() <= 0 || newHead.getX() >= _width - 1  
		|| newHead.getY() <= 0 || newHead.getY() >= _height - 1)
	{
		return false;

	}
	if (_snake.ifCollision(newHead))
	{
		return false;
	}
	return true;
}

// Affiche le score en dessous du plateau de jeu dans la console 
void game::printScore(ostream& sortie)const
{
	gotoxy(0, _height + 4);
	sortie << "Score : " << _score << endl;
}

// Affiche le nombre de vie restante en dessous du plateau de jeu dans la console 
void game::printLife(ostream& sortie)const
{
	gotoxy(0, _height + 3);
	sortie << "Nombre de vie restantes : " << _cptLife << endl;
}

// Affiche GAMEOVER en dessous du plateau de jeu dans la console 
void game::printEndGame(ostream& sortie)const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(20, _height + 4);
	sortie << "- GAME OVER -" << endl;
	Sleep(1000);
}
