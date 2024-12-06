#pragma once
#include <vector>
#include <iostream>
#include <queue>
class Board
{
private:
	std::vector<std::vector<int>> boardMatrix;
	bool isTrainingBoard;

public:
	Board();
	Board(bool isTrainingBoard);
	void addCard(int card, int posX, int posY);
	void removeCard(int card, int posX, int posY);
	std::vector<std::vector<int>> getBoard();
	friend std::ostream& operator << (std::ostream& out, const Board board);
};

