#include "Board.h"


Board::Board()
{
}

Board::Board(bool isTrainingBoard)
{
	this->isTrainingBoard = isTrainingBoard;
	this->boardMatrix = {};
};



void Board::addCard(int card, int posX, int posY)
{
	
	if (!this->checkIfCardIsInsideBoard(posX, posY)) {
		std::vector<std::vector<PlacedDeck>> aux(this->boardMatrix.size() + 1, std::vector<PlacedDeck>(this->boardMatrix.size() + 1, PlacedDeck(-1, 0, 0)));
		
		if (posX == 0 || posY == 0) {
			for (int i = 0; i < this->boardMatrix.size(); i++) {
				for (int j = 0; j < this->boardMatrix.size(); j++) {
					aux[i + 1][j + 1] = this->boardMatrix[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < this->boardMatrix.size(); i++) {
				for (int j = 0; j < this->boardMatrix.size(); j++) {
					aux[i][j] = this->boardMatrix[i][j];
				}
			}
		}
		this->boardMatrix = aux;
		this->boardMatrix[posX][posY].addCardToDeck(card);

	}
	else {
		this->boardMatrix[posX][posY].addCardToDeck(card);

	}
}

bool Board::checkIfCardIsInsideBoard(int posX, int posY)
{
	if ((!this->isTrainingBoard && this->boardMatrix.size() < 4) || (this->isTrainingBoard && this->boardMatrix.size() < 3)) {
		if (posX == 0 || posX > this->boardMatrix.size() || posY == 0 || posY > this->boardMatrix.size()) {
			return false;
		}
	}

	return true;
}

bool Board::checkIfCardCanBePlacedOnBoard(int card, int posX, int posY)
{
	if (!this->checkIfCardIsInsideBoard(posX, posY)) {
		return true;
	}

	return false;
}

void Board::removeCard(int card, int posX, int posY)
{
}

std::vector<std::vector<PlacedDeck>> Board::getBoard()
{
	return this->boardMatrix;
}

std::ostream& operator<<(std::ostream& out, Board board)
{
	
	if (board.boardMatrix.size() == 1) {

		out << "00" << " " << "01" << " " << "02" << "\n";
		out<<10<< "|" << board.boardMatrix[0][0].getLastCard() << "|" << 12 << "\n";
		out << 20 << " " << 21 << " " << 22 << "\n";
 
		return out;
	}

	if (board.boardMatrix.size() == 2) {
		out << "00" << " " << "01" << " " << "02 " << "03" << "\n";
		for (int i = 0; i < board.boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.boardMatrix.size(); j++) {
				out << "|" << board.boardMatrix[i][j].getLastCard();
			}
			out << "| " << i + 1 << 3 << "\n";
		}
		out << "30" << " " << "31" << " " << "32 " << "33" << "\n";

		return out;
	}

	if (board.boardMatrix.size() == 3 && board.isTrainingBoard) {
		out << "00" << " " << "01" << " " << "02 " << "03" << " 04" << "\n";
		for (int i = 0; i < board.boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.boardMatrix.size(); j++) {
				out << "|" << board.boardMatrix[i][j].getLastCard();
			}
			out << "| " << i + 1 << 4 << "\n";
		}
		out << "40" << " " << "41" << " " << "42 " << "43" << " 44" << "\n";

		return out;
	}

	for (int i = 0; i < board.boardMatrix.size(); i++) {
		for (int j = 0; j < board.boardMatrix.size(); j++) {
			out << "|" << board.boardMatrix[i][j].getLastCard();
		}
		out << "|" << "\n";
	}



	return out;
}
