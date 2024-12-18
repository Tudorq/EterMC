#pragma once
#include <string>
#include "Player.h"

class Card
{
private:
	int card;
	std::string player_name;

public:
	Card(int card, std::string player_name);

};

