#include "Card.h"

Card::Card()
{
}

Card::Card(int card, std::string playerName, bool isIllusion)
{
	this->m_cardValue = card;
	this->m_playerName = playerName;
	m_isIllusion = isIllusion;
}

int Card::getCardValue()
{
	return m_cardValue;
}

void Card::setIsIllusionStatus(bool status)
{
	m_isIllusion = status;
}

bool Card::checkIllusionStatus()
{
	return m_isIllusion;
}

std::string Card::getPlayerName()
{
	return m_playerName;
}
