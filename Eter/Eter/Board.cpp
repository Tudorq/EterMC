#include "Board.h"


Board::Board()
{
}

Board::Board(bool isTrainingBoard)
{
	this->isTrainingBoard = isTrainingBoard;
	this->boardMatrix = { { - 1 } };
};



void Board::addCard(int card, int posX, int posY)
{

}

void Board::removeCard(int card, int posX, int posY)
{
}

std::vector<std::vector<int>> Board::getBoard()
{
	return this->boardMatrix;
}

std::ostream& operator<<(std::ostream& out, const Board board)
{
	return out;
}
