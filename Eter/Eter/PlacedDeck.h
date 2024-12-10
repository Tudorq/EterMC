#pragma once

#include <vector>

class PlacedDeck
{
private:
	std::vector<int> placedCards;
	int posX, posY;

public:
	PlacedDeck();
	PlacedDeck(int initialCard, int posX, int posY);
	PlacedDeck& operator=(const PlacedDeck& node);
	

};

