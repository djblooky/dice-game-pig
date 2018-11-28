#pragma once
#include "Dice.h"
#include "Player.h"

class Game
{
private:
	Dice dice;
	Player player1;
	Player player2;
public:
	Game();
	~Game();
	void gameLoop();
};

