#pragma once
#include <string>
#include "Wizard.h"
#include <vector>
#include <ctime>
class Player
{

private:
	std::string m_name;
	Wizard m_wizard;
	std::vector<int> m_deck;
	bool m_hasWizard;
	bool m_usedWizard;

public:
	Player();
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void setWizard();
	Wizard getWizard();
	void setDeck(std::vector<int> deck);
	std::vector<int> getDeck();
	void addCardToDeck(int card);
	void setDeckForGameMode(int gameMode);
	bool checkIfDeckIsEmpty();
	void removePlacedCardFromDeck(int card);

};

