#pragma once
#include <iostream>

class Player
{
private:
	unsigned int m_score;
	std::string m_name;

public:
	Player();
	Player(int score, std::string name);
	~Player();

	int getScore(); //getters and setters!
	void setScore(int score);
	std::string getName();
	void setName(std::string name);

	void tallyScore(int rollTotal);

};

