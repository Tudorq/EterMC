#include "Card.h"

Card::Card()
{
}

Card::Card(int card, std::string playerName)
{
	this->m_cardValue = card;
	this->m_playerName = playerName;
}

int Card::getCardValue()
{
	return m_cardValue;
}

void Card::setIsIllusionStatus(bool status)
{
	m_isIllusion = status;
}

std::string Card::getPlayerName()
{
	return m_playerName;
}
