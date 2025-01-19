#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <memory>

class Board;

class Player
{
public:
	enum Power
	{
		FIRE1,
		FIRE2,
		EARTH1,
		EARTH2,
		AIR1,
		AIR2,
		WATER1,
		WATER2,
	};

	Player();
	Player(std::string name);
	void setName(std::string name);
	std::string getName();
	void setWizard();
	//Wizard getWizard();
	void setDeck(std::vector<int> deck);
	std::vector<int> getDeck();
	void addCardToDeck(int card);
	void setDeckForGameMode(int gameMode);
	bool checkIfDeckIsEmpty();
	bool checkIfUsedIllusion();
	void useIllusion();
	void removePlacedCardFromDeck(int card);
	void removeCard(std::shared_ptr<Board> board, int posX, int posY);
	void removeRow(std::shared_ptr<Board> board,  int row);
	void coverCardWithSmallerNumber(std::shared_ptr<Board> board, int posX, int posY, int card, std::string playerName);
	void createHole(std::shared_ptr<Board> board, int posX, int posY);
	void moveOwnBoardDeck(std::shared_ptr<Board> board, int posX1, int posY1, int posX2, int posY2);
	void getExtraEter();
	void moveOtherBoardDeck(std::shared_ptr<Board> board, int posX1, int posY1, int posX2, int posY2);
	void moveEdgeRow(std::shared_ptr<Board> board, bool isRow, bool position);

private:
	std::string m_name;
	std::vector<int> m_deck;
	bool m_hasWizard;
	bool m_usedWizard;
	bool m_usedIllusion;
	Power m_pickedPower;
	bool wasUsed;

};

