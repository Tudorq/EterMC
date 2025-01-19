#pragma once
#include <string>
#include "Player.h"

class Card
{
private:
	int m_cardValue;
	bool m_isIllusion;
	std::string m_playerName;

public:
	Card();
	Card(int card, std::string playerName);
	int getCardValue();
	void setIsIllusionStatus(bool status);
	std::string getPlayerName();
};

