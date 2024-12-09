#include "Board.h"


Board::Board()
{
}

Board::Board(bool isTrainingBoard)
{
	this->isTrainingBoard = isTrainingBoard;
	this->boardMatrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
};



void Board::addCard(int card, int posX, int posY)
{
	
	if ((posX < 0 || posX >= this->boardMatrix.size()) && (posY < 0 || posY >= this->boardMatrix.size())) {
		std::vector<std::vector<int>> aux(this->boardMatrix.size() + 1, std::vector<int>(this->boardMatrix.size() + 1, -1));

	}

	this->boardMatrix[posX][posY] = card;
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
	
	if (board.boardMatrix.size() == 1) {

		out << "00" << " " << "01" << " " << "02" << "\n";
		out<<10<< "|" << board.boardMatrix[0][0] << "|" << 12 << "\n";
		out << 20 << " " << 21 << " " << 22 << "\n";
 
		return out;
	}

	if (board.boardMatrix.size() == 2) {
		out << "00" << " " << "01" << " " << "02 " << "03" << "\n";
		for (int i = 0; i < board.boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.boardMatrix.size(); j++) {
				out << "|" << board.boardMatrix[i][j];
			}
			out << "| " << i + 1 << 3 << "\n";
		}
		out << "30" << " " << "31" << " " << "32 " << "33" << "\n";

		return out;
	}

	if (board.boardMatrix.size() == 3 && !board.isTrainingBoard) {
		out << "00" << " " << "01" << " " << "02 " << "03" << " 04" << "\n";
		for (int i = 0; i < board.boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.boardMatrix.size(); j++) {
				out << "|" << board.boardMatrix[i][j];
			}
			out << "| " << i + 1 << 4 << "\n";
		}
		out << "40" << " " << "41" << " " << "42 " << "43" << " 44" << "\n";

		return out;
	}

	for (int i = 0; i < board.boardMatrix.size(); i++) {
		for (int j = 0; j < board.boardMatrix.size(); j++) {
			out << "|" << board.boardMatrix[i][j];
		}
		out << "|" << "\n";
	}



	return out;
}
