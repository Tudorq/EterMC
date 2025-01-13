#include "PlacedDeck.h"

PlacedDeck::PlacedDeck()
{
	m_placedCards = {};
	m_pos.first = -1;
	m_pos.second = -1;
}

PlacedDeck::PlacedDeck(Card initialCard, int posX, int posY)
{
	m_placedCards.push_back(initialCard);
	m_pos.first = posX;
	m_pos.second = posY;
}

void PlacedDeck::addCardToDeck(Card card)
{
	m_placedCards.push_back(card);
}

void PlacedDeck::removeLastCardFromDeck()
{
	m_placedCards.pop_back();
}

Card PlacedDeck::getLastCard()
{
	return m_placedCards.back();
}

PlacedDeck& PlacedDeck::operator=(const PlacedDeck& node)
{
	m_placedCards = node.m_placedCards;
	m_pos.first = node.m_pos.first;
	m_pos.second = node.m_pos.second;

	return *this;
}
