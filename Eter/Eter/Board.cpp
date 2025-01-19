#include "Board.h"


Board::Board()
{
}

Board::Board(bool isTrainingBoard)
{
	m_isTrainingBoard = isTrainingBoard;
	m_boardMatrix = {};

	m_wonBy = nullptr;
}
std::shared_ptr<Player> Board::getWonBy()
{
	return m_wonBy;
}
;



bool Board::addCard(int card, int posX, int posY, std::string playerName)
{
	Card NewCard{ card, playerName };
	
	if (!checkIfCardIsInsideBoard(posX, posY)) {
		std::vector<std::vector<PlacedDeck>> aux(m_boardMatrix.size() + 1, std::vector<PlacedDeck>(m_boardMatrix.size() + 1, PlacedDeck(Card(-1, "."), 0, 0)));
		
		if (posX == 0 && posY == 0) {
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i + 1][j + 1] = m_boardMatrix[i][j];
				}
			}
		}
		else if (posX == 0)
		{
			posY--;
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i + 1][j] = m_boardMatrix[i][j];
				}
			}
		}
		else if (posY == 0)
		{
			posX--;
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i][j + 1] = m_boardMatrix[i][j];
				}
			}
		}
		else {
			posX--;
			posY--;
			for (int i = 0; i < m_boardMatrix.size(); i++) {
				for (int j = 0; j < m_boardMatrix.size(); j++) {
					aux[i][j] = m_boardMatrix[i][j];
				}
			}
		}
		m_boardMatrix = aux;
		m_boardMatrix[posX][posY].addCardToDeck(NewCard);
		m_lastAddedCard = NewCard;
		
	}
	else {

		if (checkIfCardCanBePlacedOnBoard(NewCard.getCardValue(), posX, posY))
		{
			m_boardMatrix[posX][posY].addCardToDeck(NewCard);
			m_lastAddedCard = NewCard;
		}
		else
		{
			return false;
		}

	}

	return true;
}

bool Board::checkIfCardIsInsideBoard(int & posX, int & posY)
{
	if ((!m_isTrainingBoard && m_boardMatrix.size() < 4) || (m_isTrainingBoard && m_boardMatrix.size() < 3)) {
		if (posX == 0 || posY == 0) {
			return false;
		}
		else if (posX > m_boardMatrix.size() || posY > m_boardMatrix.size())
		{
			return false;
		}

		posX--;
		posY--;
		
	}

	return true;
}

bool Board::checkIfCardCanBePlacedOnBoard(int card, int posX, int posY)
{

	if (card == 0 && m_boardMatrix[posX][posY].getLastCard().getCardValue() == -1)
	{
		return true;
	}

	if (m_boardMatrix[posX][posY].getLastCard().getCardValue() < card) {
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

void Board::calculatePoints(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{
	int playerPoints1 = 0, playerPoints2 = 0;

	for (int i = 0; i < m_boardMatrix.size(); i++)
	{
		for (int j = 0; j < m_boardMatrix.size(); j++)
		{
			if (m_boardMatrix[i][j].getLastCard().getPlayerName() == player1->getName())
			{
				playerPoints1 += m_boardMatrix[i][j].getLastCard().getCardValue();
				if (m_boardMatrix[i][j].getLastCard().getCardValue() == 0)
				{
					playerPoints1++;
				}
			}
			else
			{
				playerPoints2 += m_boardMatrix[i][j].getLastCard().getCardValue();
				if (m_boardMatrix[i][j].getLastCard().getCardValue() == 0)
				{
					playerPoints1++;
				}
			}
		}
	}

	if (playerPoints1 > playerPoints2)
	{
		m_wonBy = player1;
	}
	else if (playerPoints2 > playerPoints1)
	{
		m_wonBy = player2;
	}


}

bool Board::checkWinningConditions(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{

	bool isWinningCondition = true;
	std::string firstUserName;

	if (m_boardMatrix.size() < 2)
	{
		return false;
	}

	if (checkLinesForWinningConditions(firstUserName))
	{
		std::cout << firstUserName;
		if (firstUserName == player1->getName())
		{
			m_wonBy = player1;
		}
		else {
			m_wonBy = player2;
		}

		return true;
	}
	
	for (int i = 0; i < m_boardMatrix.size(); i++)
	{
		for (int j = 0; j < m_boardMatrix.size(); j++)
		{
			if (m_boardMatrix[i][j].getLastCard().getCardValue() == -1)
			{
				isWinningCondition = false;
			}
		}

	}
	
	if (isWinningCondition)
	{
		return true;
	}

	if (player1->checkIfDeckIsEmpty() || player2->checkIfDeckIsEmpty())
	{
		return true;
	}

	return false;
	
}

bool Board::checkLinesForWinningConditions(std::string & firstUserName)
{
	int boardLength = m_boardMatrix.size();
	int diagonalCounter = 1;
	bool isWinningCondition = true;
	for (int i = 0; i < boardLength; i++)
	{
		firstUserName = m_boardMatrix[i][0].getLastCard().getPlayerName();
		
		for (int j = 1; j < boardLength; j++)
		{
			if (m_boardMatrix[i][j].getLastCard().getPlayerName() != firstUserName)
			{
				isWinningCondition = false;
			}
		}

		if (isWinningCondition && firstUserName != ".")
		{
			return true;
		}
		isWinningCondition = true;
	}
	for (int i = 0; i < boardLength; i++)
	{
		firstUserName = m_boardMatrix[0][i].getLastCard().getPlayerName();
		isWinningCondition = true;
		for (int j = 1; j < boardLength; j++)
		{
			if (m_boardMatrix[j][i].getLastCard().getPlayerName() != firstUserName)
			{
				isWinningCondition = false;
			}
		}

		if (isWinningCondition && firstUserName != ".")
		{
			return true;
		}
	}
	for (int i = 0; i < boardLength; i++)
	{
		firstUserName = m_boardMatrix[0][0].getLastCard().getPlayerName();
		isWinningCondition = true;
		for (int j = 1; j < boardLength; j++)
		{
			if (i == j && m_boardMatrix[i][j].getLastCard().getPlayerName() == firstUserName)
			{
				diagonalCounter++;
			}
		}
		if (diagonalCounter == boardLength && firstUserName != ".")
		{
			return true;
		}
	}
	diagonalCounter = 1;
	for (int i = 0; i < boardLength; i++)
	{
		firstUserName = m_boardMatrix[0][0].getLastCard().getPlayerName();
		isWinningCondition = true;
		for (int j = 1; j < boardLength; j++)
		{
			if (i + j == boardLength - 1 && m_boardMatrix[i][j].getLastCard().getPlayerName() == firstUserName)
			{
				diagonalCounter++;
			}
		}
		if (diagonalCounter == boardLength && firstUserName != ".")
		{
			return true;
		}
	}
	return false;
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

	if (board.m_boardMatrix.size() == 3 && !board.m_isTrainingBoard) {
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
