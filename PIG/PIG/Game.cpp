#include "pch.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <Windows.h>


Game::Game(Dice dice, Player p1, Player p2)
{
	m_dice = dice;
	m_p1 = p1;
	m_p2 = p2;
	turn = 2;
}


Game::~Game()
{
}

void Game::gameLoop() //organizes game order
{
	beginGame(); 

	while (m_p1.getScore() < 100 && m_p2.getScore() < 100) { //while nobody has won yet
		displayScores();
		Sleep(1000);
		pickTurn();
		if (playerTurn) { //if it's not the bot's turn
			play();
		}
		else {
			botPlay();
		}
		
	}

	if (m_p1.getScore() >= 100) {
		std::cout << "\t" << m_p1.getName() << " wins!" << std::endl;
	}
	else {
		std::cout << "\t" << m_p2.getName() << " wins!" << std::endl;
	}	
	
}

void Game::beginGame()
{
	std::string name;
	std::cout << "\n\tEnter your name: ";
	std::cin >> name;
	m_p1.setName(name);
}

void Game::pickTurn() //assigns currentPlayer
{
	if (turn % 2 == 0) {;
		playerTurn = true;
	}
	else {
		playerTurn = false;
	}
	
	turn++;
	
}

void Game::displayScores()
{
	std::cout << std::endl << std::endl;
	std::cout << "\t" << m_p1.getName() << "'s score: " << m_p1.getScore() << std::endl;
	std::cout << "\t" << m_p2.getName() << "'s score: " << m_p2.getScore() << std::endl << std::endl;
}

void Game::play() //play current player's turn
{
	unsigned int roll;
	bool hold = false;
	int h;

	while (!hold) {
		roll = m_dice.roll(); //rolls dice
		if (roll == 1) {
			roll = 0;
			m_dice.setRollTotal(0); //reset roll total to zero
			std::cout << "\t" << m_p1.getName() << " has rolled a pig!" << std::endl; //add
			hold = true;
			break;
		}
		std::cout << "\t" << m_p1.getName() << " has rolled a " << roll << std::endl;
		m_dice.addTotalRoll(roll); //adds roll to total
		std::cout << "\t" << m_p1.getName()  << "'s current roll total is " << m_dice.getRollTotal() << std::endl;

		std::cout << "\t" << "Enter 1 to hold, 2 to play" << std::endl;
		std::cin >> h;
		if (h == 1) {
			hold = true;
		}	
	}

	m_p1.tallyScore(m_dice.getRollTotal()); //set player score to turn total
	m_dice.setRollTotal(0); //reset roll total to zero	
}

void Game::botPlay()
{
	unsigned int roll;
	bool hold = false;

	while (!hold) {
		roll = m_dice.roll(); //rolls dice
		if (roll == 1) {
			roll = 0;
			m_dice.setRollTotal(0); //reset roll total to zero
			std::cout << "\t" << m_p2.getName() << " has rolled a pig!" << std::endl; //add
			hold = true;
			break;
		}
		std::cout << "\t" << m_p2.getName()  << " has rolled a " << roll << std::endl;
		m_dice.addTotalRoll(roll); //adds roll to total
		std::cout << "\t" << m_p2.getName()  << "'s current roll total is " << m_dice.getRollTotal() << std::endl;
		Sleep(1000);

		if(m_dice.getRollTotal() >= 20) {
			std::cout << std::endl << "\t" << "Player 2 holds!";
			hold = true;
		}
	}

	m_p2.tallyScore(m_dice.getRollTotal()); //set player score to turn total
	m_dice.setRollTotal(0); //reset roll total to zero		
}
