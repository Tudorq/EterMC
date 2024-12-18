#include "ActiveMatch.h"


ActiveMatch::ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode)
{
	m_player1 = player1;
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

void ActiveMatch::startTurn(std::shared_ptr<Player> currentPlayer)
{

	int cardPicked;
	int x, y;

	std::cout << "Tura actuala: " << currentPlayer->getName() << "\n";
	std::cout << "Carti disponibile: ";
	for (int i = 0; i < currentPlayer->getDeck().size(); i++) {
		std::cout << currentPlayer->getDeck()[i] << " ";
	}

	std::cout << "\n";

	std::cout << "Alege cartea: ";

	std::cin >> cardPicked;
	std::cout << "Alege pozitia(x,y): ";

	std::cin >> x >> y;

	m_board.addCard(cardPicked, x, y, currentPlayer->getName());
}
