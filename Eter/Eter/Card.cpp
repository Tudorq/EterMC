#include "Card.h"

Card::Card(int card, std::string playerName)
{
	this->m_cardValue = card;
	this->m_playerName = playerName;
}

int Card::getCardValue()
{
	return m_cardValue;
}

std::string Card::getPlayerName()
{
	return m_playerName;
}
