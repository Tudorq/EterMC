#include "Wizard.h"

Wizard::Wizard()
{
	m_pickedPower = FIRE1;
}

Wizard::Wizard(int type)
{
	m_pickedPower = Power(type);
}

void Wizard::usePower(int posX = -1, int posY = -1, int row = -1, int card, std::string playerName = "")
{
	switch (m_pickedPower)
	{
	case Wizard::FIRE1:
		removeCard(posX, posY);
		break;
	case Wizard::FIRE2:
		removeRow(row);
		break;
	case Wizard::EARTH1:
		coverCardWithSmallerNumber(posX, posY, card, playerName);
		break;
	case Wizard::EARTH2:
		break;
	case Wizard::AIR1:
		break;
	case Wizard::AIR2:
		break;
	case Wizard::WATER1:
		break;
	case Wizard::WATER2:
		break;
	default:
		break;
	}
}

void Wizard::removeCard(int posX, int posY)
{
	m_board->m_boardMatrix[posX][posY].removeLastCardFromDeck();
}

void Wizard::removeRow(int row)
{
	for (int i = 0; i < m_board->m_boardMatrix.size(); i++)
	{
		m_board->m_boardMatrix[row][i] = PlacedDeck(Card(-1, ""), 0, 0);
	}
}

void Wizard::coverCardWithSmallerNumber(int posX, int posY, int card, std::string playerName)
{
	Card NewCard{ card, playerName };

	m_board->m_boardMatrix[posX][posY].addCardToDeck(NewCard);
}

void Wizard::createHole()
{
}

void Wizard::moveOwnBoardDeck()
{
}

void Wizard::getExtraEter()
{
}

void Wizard::moveOtherBoardDeck()
{
}

void Wizard::moveEdgeRow()
{
}
