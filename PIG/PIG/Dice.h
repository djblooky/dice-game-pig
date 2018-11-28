#pragma once
class Dice
{
private: 
	unsigned int m_roll;
public:
	Dice();
	~Dice();

	int roll(); //generates and returns roll
};

