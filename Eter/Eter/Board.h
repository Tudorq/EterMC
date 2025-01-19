#pragma once
#include "Player.h"
#include <vector>
#include <memory>
#include <iostream>
#include <queue>
#include "PlacedDeck.h"
#include <string>
#include "Card.h"
class Board
{
private:
	bool m_isTrainingBoard;
	Card m_lastAddedCard;
	std::shared_ptr<Player> m_wonBy;


public:
	std::vector<std::vector<PlacedDeck>> m_boardMatrix;
	std::vector<std::vector<int>> m_secondaryMatrix;
	Board();
	Board(bool isTrainingBoard);
	std::shared_ptr<Player> getWonBy();
	int addCard(int card, int posX, int posY, std::string playerName, bool useIllusion);
	bool checkForIllusion(int card);
	bool checkIfCardIsInsideBoard(int & posX, int & posY);
	bool checkIfCardCanBePlacedOnBoard(int card, int posX, int posY);
	void removeCard(int card, int posX, int posY);
	std::vector<std::vector<PlacedDeck>> getBoard();
	void calculatePoints(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
	bool checkWinningConditions(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
	bool checkLinesForWinningConditions(std::string & firstUserName);
	friend std::ostream& operator << (std::ostream& out, const Board board);
};

