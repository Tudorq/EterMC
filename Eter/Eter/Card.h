#pragma once
#include <string>
#include "Player.h"

class Card
{
private:
	int m_cardValue;
	std::string m_playerName;

public:
	Card(int card, std::string playerName);
	int getCardValue();
	std::string getPlayerName();

};

