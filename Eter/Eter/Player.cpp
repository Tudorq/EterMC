#include "Player.h"
#include "Board.h"

Player::Player()
{
	m_hasWizard = 0;
	m_usedWizard = 0;
	m_usedIllusion = false;
}

Player::Player(std::string name)
{
	setName(name);
	m_hasWizard = 0;
	m_usedWizard = 0;
	m_usedIllusion = false;
}

void Player::setName(std::string name)
{
	m_name = name;
}

std::string Player::getName()
{
	return m_name;
}

void Player::setWizard()
{
	int numberPicked;

	srand(time(0));

	numberPicked = rand()%8;

	m_pickedPowerId = numberPicked;
	m_pickedPower = Powers[numberPicked];


}

std::string Player::getWizardName()
{
	return m_pickedPower;
}

int Player::getWizardId()
{
	return m_pickedPowerId;
}


void Player::setDeck(std::vector<int> deck)
{
	m_deck = deck;
}

std::vector<int> Player::getDeck()
{
	return m_deck;
}

void Player::addCardToDeck(int card)
{
	m_deck.push_back(card);
}

void Player::setDeckForGameMode(int gameMode)
{
	if (gameMode == 1) {
		m_deck = { 1, 1, 2, 2, 3, 3, 4 };
	}
	else if (gameMode == 2) {
		m_deck = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 0 };
	}
}

bool Player::checkIfDeckIsEmpty()
{
	if (m_deck.size() == 0)
	{
		return true;
	}
	return false;
}

bool Player::checkIfUsedIllusion()
{
	return m_usedIllusion;
}

void Player::useIllusion()
{
	m_usedIllusion = true;
}

void Player::removePlacedCardFromDeck(int card)
{
	m_deck.erase(find(m_deck.begin(), m_deck.end(), card));
}


void Player::removeCard(Board& board, int posX, int posY)
{
	board.m_boardMatrix[posX][posY].removeLastCardFromDeck();
}

void Player::removeRow(Board& board, int row)
{
	for (int i = 0; i < board.m_boardMatrix.size(); i++)
	{
		board.m_boardMatrix[row][i] = PlacedDeck(Card(-1, "", 0), 0, 0);
	}
}

void Player::coverCardWithSmallerNumber(Board& board, int posX, int posY, int card, std::string playerName)
{
	Card NewCard{ card, playerName, 0};

	board.m_boardMatrix[posX][posY].addCardToDeck(NewCard);
}

void Player::createHole(Board& board, int posX, int posY)
{
	board.m_secondaryMatrix[posX][posY] = -2;
}

void Player::moveOwnBoardDeck(Board& board, int posX1, int posY1, int posX2, int posY2)
{
	board.m_boardMatrix[posX2][posY2] = board.m_boardMatrix[posX1][posY1];
	board.m_boardMatrix[posX1][posY1] = PlacedDeck(Card(-1, ".", 0), 0, 0);
}

void Player::getExtraEter()
{
	addCardToDeck(0);
}

void Player::moveOtherBoardDeck(Board& board, int posX1, int posY1, int posX2, int posY2)
{
	board.m_boardMatrix[posX2][posY2] = board.m_boardMatrix[posX1][posY1];
	board.m_boardMatrix[posX1][posY1] = PlacedDeck(Card(-1, ".", 0), 0, 0);
}

void Player::moveEdgeRow(Board& board, bool isRow, bool isPosition)
{
	std::vector<std::vector<PlacedDeck>> aux(board.m_boardMatrix.size(), std::vector<PlacedDeck>(board.m_boardMatrix.size(), PlacedDeck(Card(-1, ".", 0), 0, 0)));

	for (int i = 0; i < board.m_boardMatrix.size(); i++)
	{
		for (int j = 0; j < board.m_boardMatrix.size(); j++)
		{
			if (isRow)
			{
				if (isPosition)
				{
					if (i == 0)
					{
						aux[board.m_boardMatrix.size() - 1][j] = board.m_boardMatrix[i][j];
					}
					else {
						aux[i - 1][j] = board.m_boardMatrix[i][j];
					}
				}
				else
				{
					if (i == board.m_boardMatrix.size() - 1)
					{
						aux[0][j] = board.m_boardMatrix[i][j];
					}
					else {
						aux[i + 1][j] = board.m_boardMatrix[i][j];
					}
				}
			}
			else
			{
				if (isPosition)
				{
					if (j == 0)
					{
						aux[j][board.m_boardMatrix.size() - 1] = board.m_boardMatrix[j][i];
					}
					else {
						aux[j - 1][i] = board.m_boardMatrix[j][i];
					}
				}
				else
				{
					if (j == board.m_boardMatrix.size() - 1)
					{
						aux[j][0] = board.m_boardMatrix[j][i];
					}
					else {
						aux[j + 1][i] = board.m_boardMatrix[j][i];
					}
				}
			}
		}
	}
}
