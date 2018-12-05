#pragma once
#include "Dice.h"
#include "Player.h"

class Game
{
private:
	Dice m_dice;
	Player m_p1;
	Player m_p2;
	Player currentPlayer;
	bool playerTurn;
	int turn;
public:
	Game(Dice dice, Player p1, Player p2);
	~Game();
	void gameLoop();
	void pickTurn();
	void beginGame();
	void play();
	void botPlay();
	void displayScores();
};

