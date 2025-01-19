#include "ActiveMatch.h"


ActiveMatch::ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode)
{
	m_player1 = player1;
	m_isFirstTurn = true;
	m_player2 = player2;
	m_currentPlayer = 1;
	m_isFinished = false;
	m_isDraw = false;
	m_board = Board(gameMode);
	m_isLastTurn = false;
	m_playedLastTurn = false;
	m_playerWhoWon = "";
	m_gameMode = gameMode;
}

int ActiveMatch::startMatch()
{
	int cardPicked;
	int x, y;
	std::cout << "Runda a inceput \n";

	while (!m_isFinished) {
		std::cout << m_board;
		if (m_currentPlayer == 1) {
			startTurn(m_player1);

		}
		else {
			startTurn(m_player2);
		}

	}

	return 0;
}

bool ActiveMatch::startTurn(std::shared_ptr<Player> currentPlayer)
{

	int cardPicked;
	bool usingIllusion = false;
	int choice;
	int x, y;
	int cardStatus;

	std::cout << "Tura actuala: " << currentPlayer->getName() << "\n";
	std::cout << "Carti disponibile: ";
	for (int i = 0; i < currentPlayer->getDeck().size(); i++) {
		std::cout << currentPlayer->getDeck()[i] << " ";
	}

	std::cout << "\n";

	if (!m_gameMode && !currentPlayer->checkIfUsedIllusion())
	{
		std::cout << "Aveti o iluzie disponibila \n Folositi iluzia? \n 1. Da \n 2. nu \n";
		std::cin >> choice;

		if (choice == 1)
		{
			usingIllusion = true;
		}

		std::cout << "Aveti aceasta putere: " << currentPlayer->getWizardName() << '\n';
		std::cout << "Doriti sa o folositi? \n 1. Da \n 2. Nu \n";
		std::cin >> choice;

		if (choice == 1)
		{
			switch (currentPlayer->getWizardId())
			{
			case 0:
				std::cout << "Alege pozitia(x,y): ";
				std::cin >> x >> y;
				if (m_board.m_boardMatrix.size() - 4)
				{
					x--;
					y--;
				}
				currentPlayer->removeCard(m_board, x, y);
			case 1:
				std::cout << "Alege randul: ";
				std::cin >> choice;
				currentPlayer->removeRow(m_board, choice);
			case 2:
				std::cout << "Alege pozitia(x,y): ";
				std::cin >> x >> y;
				std::cout << "\n Alege cartea: \n";
				std::cin >> choice;
				currentPlayer->coverCardWithSmallerNumber(m_board, x, y, choice, currentPlayer->getName());
			case 3:
				std::cout << "Alege pozitia(x,y): ";
				std::cin >> x >> y;
				currentPlayer->createHole(m_board, x, y);
			case 4:
				int x2, y2;
				std::cout << "Alege pozitia initiala(x, y)";
				std::cin >> x >> y;
				std::cout << "Alege pozitia finala(x, y)";
				std::cin >> x2 >> y2;
				currentPlayer->moveOwnBoardDeck(m_board, x, y, x2, x2);
			case 5:
				std::cout << "Alege pozitia(x, y)";
				std::cin >> x >> y;
				currentPlayer->getExtraEter();
				m_board.addCard(0, x, y, currentPlayer->getName(), 0);
			case 6:
				std::cout << "Alege pozitia initiala(x, y)";
				std::cin >> x >> y;
				std::cout << "Alege pozitia finala(x, y)";
				std::cin >> x2 >> y2;
				currentPlayer->moveOtherBoardDeck(m_board, x, y, x2, x2);
			case 7:
				std::cout << "1. Coloana \n 2. Rand \n";
				std::cin >> x;
				std::cout << "Alege pozitia(1, 2) \n";
				std::cin >> y;
				currentPlayer->moveEdgeRow(m_board, x, y);
			default:
				break;
			}

		}
	}

		std::cout << "Alege cartea: ";

		std::cin >> cardPicked;

		if (!m_isFirstTurn)
		{
			std::cout << "Alege pozitia(x,y): ";
			std::cin >> x >> y;
		}
		else
		{
			x = 0;
			y = 0;
			m_isFirstTurn = false;
		}


		cardStatus = m_board.addCard(cardPicked, x, y, currentPlayer->getName(), usingIllusion);

		if (cardStatus == 1)
		{
			switch (m_currentPlayer)
			{
			case 1:
				m_player1->removePlacedCardFromDeck(cardPicked);
				if (usingIllusion)
				{
					m_player1->useIllusion();
				}
				break;
			case 2:
				m_player2->removePlacedCardFromDeck(cardPicked);
				if (usingIllusion)
				{
					m_player2->useIllusion();
				}
				break;
			default:
				break;
			}

			if (m_board.checkWinningConditions(m_player1, m_player2))
			{
				if (m_board.getWonBy() != nullptr)
				{
					m_playerWhoWon = m_board.getWonBy()->getName();
					m_isFinished = true;
				}
				else if (m_board.getWonBy() == nullptr && m_playedLastTurn)
				{
					m_board.calculatePoints(m_player1, m_player2);
					if (m_board.getWonBy() == nullptr)
					{
						m_isDraw = true;
					}
					else
					{
						m_playerWhoWon = m_board.getWonBy()->getName();
					}
					m_isFinished = true;
				}
				else
				{
					m_isLastTurn = true;
				}

			}
		}
		else if (cardStatus == 0)
		{
			std::cout << "Cartea nu poate fi pusa, incearca din nou.";
			return false;
		}
		else if (cardStatus == 2)
		{
			std::cout << "Valoarea iluziei este mai mare sau egala, v-ati pierdut cartea";
			switch (m_currentPlayer)
			{
			case 1:
				m_player1->removePlacedCardFromDeck(cardPicked);
				if (usingIllusion)
				{
					m_player1->useIllusion();
				}
				break;
			case 2:
				m_player2->removePlacedCardFromDeck(cardPicked);
				if (usingIllusion)
				{
					m_player2->useIllusion();
				}
				break;
			default:
				break;
			}
		}
		else
		{
			std::cout << "Nu poti plasa o carte pe propria iluzie";
			return false;
		}

		if (m_currentPlayer == 1)
		{
			m_currentPlayer = 2;
		}
		else
		{
			m_currentPlayer = 1;
		}

		if (m_isLastTurn)
		{
			m_playedLastTurn = true;
		}
	}


bool ActiveMatch::checkIfMatchIsDraw()
{
	return m_isDraw;
}

std::string ActiveMatch::playerWhoWon()
{
	return m_playerWhoWon;
}

void ActiveMatch::handleWizard(std::shared_ptr<Player> currentPlayer)
{
}
