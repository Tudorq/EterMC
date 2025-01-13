#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "PlacedDeck.h"
#include <string>
#include "Card.h"
class Board
{
private:
	std::vector<std::vector<PlacedDeck>> m_boardMatrix;
	bool m_isTrainingBoard;
	Card m_lastAddedCard;

public:
	Board();
	Board(bool isTrainingBoard);
	bool addCard(int card, int posX, int posY, std::string playerName);
	bool checkIfCardIsInsideBoard(int & posX, int & posY);
	bool checkIfCardCanBePlacedOnBoard(int card, int posX, int posY);
	void removeCard(int card, int posX, int posY);
	std::vector<std::vector<PlacedDeck>> getBoard();
	bool checkWinningConditions();
	bool checkLinesForWinningConditions();
	friend std::ostream& operator << (std::ostream& out, const Board board);
};

