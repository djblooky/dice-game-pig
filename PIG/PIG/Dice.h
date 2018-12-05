#pragma once
class Dice
{
private: 
	unsigned int m_roll;
	unsigned int m_rollTotal;
public:
	Dice();
	~Dice();

	int roll(); //generates and returns roll
	void addTotalRoll(int roll);
	int getRollTotal();
	void setRollTotal(int total);
};

