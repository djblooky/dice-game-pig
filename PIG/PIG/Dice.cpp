#include "pch.h"
#include "Dice.h"
#include <random>
#include <ctime>

Dice::Dice()
{
}


Dice::~Dice()
{
}

int Dice::roll()
{
	m_roll = rand() % 5 + 1; //roll 1-6?
	srand(time(NULL));
	return m_roll;
}
