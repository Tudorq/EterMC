#pragma once
#include <string>
#include "Wizard.h"
#include <vector>
class Player
{

private:
	std::string name;
	Wizard wizard;
	std::vector<int> deck;
	bool hasWizard;
	bool usedWizard;

public:
	Player();
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void setWizard(Wizard wizard);
	Wizard getWizard();
	void setDeck(std::vector<int> deck);
	std::vector<int> getDeck();
	void setDeckForGameMode(int gameMode);

};

