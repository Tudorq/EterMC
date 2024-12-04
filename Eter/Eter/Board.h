#pragma once
#include <vector>

class Board
{
private:
	std::vector<std::vector<int>> boardMatrix;
	bool isTrainingBoard;

public:
	Board(bool isTrainingBoard);
	void addCard(int card, int posX, int posY);
};

