//#include "Wizard.h"
//
//Wizard::Wizard()
//{
//	m_pickedPower = FIRE1;
//}
//
//Wizard::Wizard(int type)
//{
//	m_pickedPower = Power(type);
//}
//
//void Wizard::usePower(int posX1 = -1, int posY1 = -1, int posX2 = -1, int posY2 = -1, int row = -1, int card = 0, std::string playerName = "", bool isRow = false, bool position = false)
//{
//	switch (m_pickedPower)
//	{
//	case Wizard::FIRE1:
//		removeCard(posX1, posY1);
//		break;
//	case Wizard::FIRE2:
//		removeRow(row);
//		break;
//	case Wizard::EARTH1:
//		coverCardWithSmallerNumber(posX1, posY1, card, playerName);
//		break;
//	case Wizard::EARTH2:
//		createHole(posX1, posY1);
//		break;
//	case Wizard::AIR1:
//		moveOwnBoardDeck(posX1, posY1, posX2, posY2);
//		break;
//	case Wizard::AIR2:
//		getExtraEter();
//		break;
//	case Wizard::WATER1:
//		moveOtherBoardDeck(posX1, posY1, posX2, posY2);
//		break;
//	case Wizard::WATER2:
//		moveEdgeRow(isRow, position);
//		break;
//	default:
//		break;
//	}
//}
//
//void Wizard::removeCard(int posX, int posY)
//{
//	m_board->m_boardMatrix[posX][posY].removeLastCardFromDeck();
//}
//
//void Wizard::removeRow(int row)
//{
//	for (int i = 0; i < m_board->m_boardMatrix.size(); i++)
//	{
//		m_board->m_boardMatrix[row][i] = PlacedDeck(Card(-1, ""), 0, 0);
//	}
//}
//
//void Wizard::coverCardWithSmallerNumber(int posX, int posY, int card, std::string playerName)
//{
//	Card NewCard{ card, playerName };
//
//	m_board->m_boardMatrix[posX][posY].addCardToDeck(NewCard);
//}
//
//void Wizard::createHole(int posX, int posY)
//{
//	m_board->m_secondaryMatrix[posX][posY] = -2;
//}
//
//void Wizard::moveOwnBoardDeck(int posX1, int posY1, int posX2, int posY2)
//{
//	m_board->m_boardMatrix[posX2][posY2] = m_board->m_boardMatrix[posX1][posY1];
//	m_board->m_boardMatrix[posX1][posY1] = PlacedDeck(Card(-1, ""), 0, 0);
//}
//
//void Wizard::getExtraEter()
//{
//	m_player->addCardToDeck(0);
//}
//
//void Wizard::moveOtherBoardDeck(int posX1, int posY1, int posX2, int posY2)
//{
//	m_board->m_boardMatrix[posX2][posY2] = m_board->m_boardMatrix[posX1][posY1];
//	m_board->m_boardMatrix[posX1][posY1] = PlacedDeck(Card(-1, ""), 0, 0);
//}
//
//void Wizard::moveEdgeRow(bool isRow, bool isPosition)
//{
//	std::vector<std::vector<PlacedDeck>> aux(m_board->m_boardMatrix.size(), std::vector<PlacedDeck>(m_board->m_boardMatrix.size(), PlacedDeck(Card(-1, ""), 0, 0)));
//
//	for (int i = 0; i < m_board->m_boardMatrix.size(); i++)
//	{
//		for (int j = 0; j < m_board->m_boardMatrix.size(); j++)
//		{
//			if (isRow)
//			{
//				if (isPosition)
//				{
//					if (i == 0)
//					{
//						aux[m_board->m_boardMatrix.size() - 1][j] = m_board->m_boardMatrix[i][j];
//					} 
//					else {
//						aux[i - 1][j] = m_board->m_boardMatrix[i][j];
//					}
//				}
//				else
//				{
//					if (i == m_board->m_boardMatrix.size() - 1)
//					{
//						aux[0][j] = m_board->m_boardMatrix[i][j];
//					}
//					else {
//						aux[i + 1][j] = m_board->m_boardMatrix[i][j];
//					}
//
//				}
//			}
//			else
//			{
//				if (isPosition)
//				{
//					if (j == 0)
//					{
//						aux[j][m_board->m_boardMatrix.size() - 1] = m_board->m_boardMatrix[j][i];
//					}
//					else {
//						aux[j - 1][i] = m_board->m_boardMatrix[j][i];
//					}
//				}
//				else
//				{
//					if (j == m_board->m_boardMatrix.size() - 1)
//					{
//						aux[j][0] = m_board->m_boardMatrix[j][i];
//					}
//					else {
//						aux[j + 1][i] = m_board->m_boardMatrix[j][i];
//					}
//
//				}
//			}
//		}
//	}
//
//	
//}
