#pragma once
#include "Card.h"
#include <vector>
#include <utility>

class PlacedDeck
{
private:
	std::vector<Card> m_placedCards;
	std::pair<int, int> m_pos;

public:
	PlacedDeck();
	PlacedDeck(Card initialCard, int posX, int posY);
	void addCardToDeck(Card card);
	void removeLastCardFromDeck();
	Card getLastCard();
	PlacedDeck& operator=(const PlacedDeck& node);
};

