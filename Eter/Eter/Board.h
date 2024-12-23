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

public:
	Board();
	Board(bool isTrainingBoard);
	void addCard(int card, int posX, int posY, std::string playerName);
	bool checkIfCardIsInsideBoard(int posX, int posY);
	bool checkIfCardCanBePlacedOnBoard(int card, int posX, int posY);
	void removeCard(int card, int posX, int posY);
	std::vector<std::vector<PlacedDeck>> getBoard();
	friend std::ostream& operator << (std::ostream& out, const Board board);
};

