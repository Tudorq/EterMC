#include "PlacedDeck.h"

PlacedDeck::PlacedDeck()
{
	this->placedCards = {};
	this->pos.first = -1;
	this->pos.second = -1;
}

PlacedDeck::PlacedDeck(int initialCard, int posX, int posY)
{
	this->placedCards.push_back(initialCard);
	this->pos.first = posX;
	this->pos.second = posY;
}

void PlacedDeck::addCardToDeck(int card)
{
	this->placedCards.push_back(card);
}

int PlacedDeck::getLastCard()
{
	return this->placedCards.back();
}

PlacedDeck& PlacedDeck::operator=(const PlacedDeck& node)
{
	this->placedCards = node.placedCards;
	this->pos.first = node.pos.first;
	this->pos.second = node.pos.second;

	return *this;
}
