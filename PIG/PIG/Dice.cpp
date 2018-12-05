#include "pch.h"
#include "Dice.h"
#include <random>
#include <ctime>

Dice::Dice()
{
	m_rollTotal = 0;
}


Dice::~Dice()
{
}

int Dice::roll()
{
	m_roll = rand() % 6 + 1; //roll 1-6?
	srand(time(NULL));
	return m_roll;
}

void Dice::addTotalRoll(int roll)
{
	m_rollTotal += roll; //adds each roll to roll total for turn
}

int Dice::getRollTotal() { return m_rollTotal; }
void Dice::setRollTotal(int total) { m_rollTotal = total; }
