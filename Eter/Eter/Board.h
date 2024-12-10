#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include "PlacedDeck.h"
class Board
{
private:
	std::vector<std::vector<PlacedDeck>> boardMatrix;
	bool isTrainingBoard;

public:
	Board();
	Board(bool isTrainingBoard);
	void addCard(int card, int posX, int posY);
	bool checkIfCardIsInsideBoard(int posX, int posY);
	bool checkIfCardCanBePlacedOnBoard(int card, int posX, int posY);
	void removeCard(int card, int posX, int posY);
	std::vector<std::vector<PlacedDeck>> getBoard();
	friend std::ostream& operator << (std::ostream& out, const Board board);
};

