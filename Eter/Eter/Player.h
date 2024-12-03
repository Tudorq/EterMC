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

public:
	Player();
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void setWizard(Wizard wizard);
	Wizard getWizard();
	void setDeck(std::vector<int> deck);
	std::vector<int> getDeck();

};

