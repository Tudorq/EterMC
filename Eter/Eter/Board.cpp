#include "Board.h"


Board::Board()
{
}

Board::Board(bool isTrainingBoard)
{
	m_isTrainingBoard = isTrainingBoard;
	m_boardMatrix = {};
};



void Board::addCard(int card, int posX, int posY, std::string playerName)
{
	Card NewCard{ card, playerName };
	
	if (!checkIfCardIsInsideBoard(posX, posY)) {
		std::vector<std::vector<PlacedDeck>> aux(m_boardMatrix.size() + 1, std::vector<PlacedDeck>(m_boardMatrix.size() + 1, PlacedDeck(Card(-1, ""), 0, 0)));
		
		if (posX == 0 || posY == 0) {
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i + 1][j + 1] = m_boardMatrix[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i][j] = m_boardMatrix[i][j];
				}
			}
		}
		m_boardMatrix = aux;
		m_boardMatrix[posX][posY].addCardToDeck(NewCard);

	}
	else {
		m_boardMatrix[posX][posY].addCardToDeck(NewCard);

	}
}

bool Board::checkIfCardIsInsideBoard(int posX, int posY)
{
	if ((!m_isTrainingBoard && m_boardMatrix.size() < 4) || (m_isTrainingBoard && m_boardMatrix.size() < 3)) {
		if (posX == 0 || posX > m_boardMatrix.size() || posY == 0 || posY > m_boardMatrix.size()) {
			return false;
		}
	}

	return true;
}

bool Board::checkIfCardCanBePlacedOnBoard(int card, int posX, int posY)
{
	if (!checkIfCardIsInsideBoard(posX, posY)) {
		return true;
	}

	return false;
}

void Board::removeCard(int card, int posX, int posY)
{
}

std::vector<std::vector<PlacedDeck>> Board::getBoard()
{
	return m_boardMatrix;
}

std::ostream& operator<<(std::ostream& out, Board board)
{
	
	if (board.m_boardMatrix.size() == 1) {

		out << "00" << " " << "01" << " " << "02" << "\n";
		out<<10<< "|" << board.m_boardMatrix[0][0].getLastCard().getCardValue() << "|" << 12 << "\n";
		out << 20 << " " << 21 << " " << 22 << "\n";
 
		return out;
	}

	if (board.m_boardMatrix.size() == 2) {
		out << "00" << " " << "01" << " " << "02 " << "03" << "\n";
		for (int i = 0; i < board.m_boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.m_boardMatrix.size(); j++) {
				out << "|" << board.m_boardMatrix[i][j].getLastCard().getCardValue();
			}
			out << "| " << i + 1 << 3 << "\n";
		}
		out << "30" << " " << "31" << " " << "32 " << "33" << "\n";

		return out;
	}

	if (board.m_boardMatrix.size() == 3 && board.m_isTrainingBoard) {
		out << "00" << " " << "01" << " " << "02 " << "03" << " 04" << "\n";
		for (int i = 0; i < board.m_boardMatrix.size(); i++) {
			out << i + 1 << 0 << " ";
			for (int j = 0; j < board.m_boardMatrix.size(); j++) {
				out << "|" << board.m_boardMatrix[i][j].getLastCard().getCardValue();
			}
			out << "| " << i + 1 << 4 << "\n";
		}
		out << "40" << " " << "41" << " " << "42 " << "43" << " 44" << "\n";

		return out;
	}

	for (int i = 0; i < board.m_boardMatrix.size(); i++) {
		for (int j = 0; j < board.m_boardMatrix.size(); j++) {
			out << "|" << board.m_boardMatrix[i][j].getLastCard().getCardValue();
		}
		out << "|" << "\n";
	}



	return out;
}
