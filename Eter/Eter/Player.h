#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <vector>
#include <string>
#include <memory>

class Board;

class Player
{
public:
	std::vector<std::string> Powers = { "fire 1", "fire 2", "earth 1", "earth 2", "air 1", "air 2", "water 1", "water 2" };

	Player();
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void setWizard();
	std::string getWizardName();
	int getWizardId();
	void setDeck(std::vector<int> deck);
	std::vector<int> getDeck();
	void addCardToDeck(int card);
	void setDeckForGameMode(int gameMode);
	bool checkIfDeckIsEmpty();
	bool checkIfUsedIllusion();
	void useIllusion();
	void removePlacedCardFromDeck(int card);
	void removeCard(Board& board, int posX, int posY);
	void removeRow(Board& board,  int row);
	void coverCardWithSmallerNumber(Board& board, int posX, int posY, int card, std::string playerName);
	void createHole(Board& board, int posX, int posY);
	void moveOwnBoardDeck(Board& board, int posX1, int posY1, int posX2, int posY2);
	void getExtraEter();
	void moveOtherBoardDeck(Board& board, int posX1, int posY1, int posX2, int posY2);
	void moveEdgeRow(Board& board, bool isRow, bool position);

private:
	std::string m_name;
	std::vector<int> m_deck;
	bool m_hasWizard;
	bool m_usedWizard;
	bool m_usedIllusion;
	int m_pickedPowerId;
	std::string m_pickedPower;

};

