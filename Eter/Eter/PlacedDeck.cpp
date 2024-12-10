#include "PlacedDeck.h"

PlacedDeck::PlacedDeck()
{
	this->placedCards = {};
	this->posX = -1;
	this->posY = -1;
}

PlacedDeck::PlacedDeck(int initialCard, int posX, int posY)
{
	this->placedCards.push_back(initialCard);
	this->posX = posX;
	this->posY = posY;
}

PlacedDeck& PlacedDeck::operator=(const PlacedDeck& node)
{
	this->placedCards = node.placedCards;
	this->posX = node.posX;
	this->posY = node.posY;

	return *this;
}
