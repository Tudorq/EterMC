#pragma once

#include <vector>
#include <utility>
#include "Card.h"

class PlacedDeck
{
private:
	std::vector<Card> m_placedCards;
	std::pair<int, int> m_pos;

public:
	PlacedDeck();
	PlacedDeck(Card initialCard, int posX, int posY);
	void addCardToDeck(Card card);
	Card getLastCard();
	PlacedDeck& operator=(const PlacedDeck& node);
};

