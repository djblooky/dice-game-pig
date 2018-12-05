// PIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Game.h"
#include <iostream>


int main()
{
	Player p1(0, "Player 1");
	Player p2(0, "Bot");
	Dice dice;

	Game game(dice, p1, p2);
	game.gameLoop();

	return 0;
}

