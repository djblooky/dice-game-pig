#include "Player.h"

Player::Player()
{
	m_score = 0;
	m_name = "Player";
}

Player::Player(int score, std::string name) //constructor
{
	m_score = score;
	m_name = name;
}

Player::~Player() //destructor
{
}

int Player::getScore() { return m_score; }
void Player::setScore(int score) { m_score = score; }
std::string Player::getName() { return m_name; }
void Player::setName(std::string name) { m_name = name; }

void Player::tallyScore(int rollTotal) { //adds to players score 
	m_score += rollTotal;
}
