#pragma once

#include <vector>
#include <utility>

class PlacedDeck
{
private:
	std::vector<int> placedCards;
	std::pair<int, int> pos;

public:
	PlacedDeck();
	PlacedDeck(int initialCard, int posX, int posY);
	void addCardToDeck(int card);
	int getLastCard();
	PlacedDeck& operator=(const PlacedDeck& node);
};

