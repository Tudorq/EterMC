#include "ActiveMatch.h"


ActiveMatch::ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode)
{
	m_player1 = player1;
	m_isFirstTurn = true;
	m_player2 = player2;
	m_currentPlayer = 1;
	m_isFinished = false;
	m_board = Board(gameMode);
}

int ActiveMatch::startMatch()
{
	int cardPicked;
	int x, y;
	std::cout << "Meciul a inceput \n";

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
	int x, y;
	bool cardWasPlaced;

	std::cout << "Tura actuala: " << currentPlayer->getName() << "\n";
	std::cout << "Carti disponibile: ";
	for (int i = 0; i < currentPlayer->getDeck().size(); i++) {
		std::cout << currentPlayer->getDeck()[i] << " ";
	}

	std::cout << "\n";

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

	cardWasPlaced = m_board.addCard(cardPicked, x, y, currentPlayer->getName());

	if (cardWasPlaced)
	{
		switch (m_currentPlayer)
		{
		case 1:
			m_player1->removePlacedCardFromDeck(cardPicked);
			break;
		case 2:
			m_player2->removePlacedCardFromDeck(cardPicked);
			break;
		default:
			break;
		}
	}
	else
	{
		std::cout << "Cartea nu poate fi pusa, incearca din nou.";
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
}
