#include "Game.h"

Game::Game()
{
	m_playerScore1 = 0;
	m_playerScore2 = 0;
	m_gameMode = 0;
}

void Game::createGame()
{

	std::string name1;
	std::string name2;
	int selectedGameMode;
	
	std::cout << "Introduceti numele jucatorului 1: ";
	std::cin >> name1;
	std::cout << "Introduceti numele jucatorului 2: ";
	std::cin >> name2;

	m_player1 = std::make_shared<Player>(name1);
	m_player2 = std::make_shared<Player>(name2);

	std::cout << "Jucatorii au fost creati \n\n";

	std::cout << "Bine ati venit " << m_player1->getName() << " si " << m_player2->getName() << "\n\n";

	while (true)
	{
		std::cout << "Alegeti modul de joc: \n 1. Modul antrenament \n 2. Duelul vrajitorilor \n 3. Exit \n";
		std::cin >> selectedGameMode;

		while (selectedGameMode != 1 && selectedGameMode != 2 && selectedGameMode != 3) {
			std::cout << "Ati selectat " << selectedGameMode << " care nu este un mod de joc valid\n Incercati din nou: ";
			std::cin >> selectedGameMode;
		}

		if (selectedGameMode == 3)
		{
			break;
		}

		m_gameMode = selectedGameMode;
		startGame();
	}

}

void Game::startGame()
{
	if (m_gameMode == 1) {
		startGameModeTraining();
	}
	else if (m_gameMode == 2) {
		startGameModeWizard();
	}
}

void Game::startGameModeTraining()
{
	int roundsWonByPlayer1 = 0, roundsWonByPlayer2 = 0;
	while (roundsWonByPlayer1 != 2 && roundsWonByPlayer2 != 2) {
		m_player1->setDeckForGameMode(1);
		m_player2->setDeckForGameMode(1);

		ActiveMatch match{m_player1, m_player2, 1};

		match.startMatch();

		if (!match.checkIfMatchIsDraw())
		{
			if (m_player1->getName() == match.playerWhoWon())
			{
				roundsWonByPlayer1++;
			}
			else
			{
				roundsWonByPlayer2++;
			}
		}

		std::cout << '\n';
		std::cout << "Runda a fost castigata de " << match.playerWhoWon() << '\n';
	}


	if (roundsWonByPlayer1 > roundsWonByPlayer2)
	{
		std::cout << "Meciul a fost castigat de " << m_player1->getName()<<'\n';
		m_playerScore1++;
	}
	else
	{
		std::cout << "Meciul a fost castigat de " << m_player2->getName()<<'\n';
		m_playerScore2++;
	}

	std::cout << "Scor:" << '\n';
	std::cout << m_player1->getName() << ": " << m_playerScore1<<'\n';
	std::cout << m_player2->getName() << ": " << m_playerScore2 <<'\n';
}

void Game::startGameModeWizard()
{
	int roundsWonByPlayer1 = 0, roundsWonByPlayer2 = 0;
	
	m_player1->setWizard();
	m_player2->setWizard();

	while (roundsWonByPlayer1 != 3 && roundsWonByPlayer2 != 3) {
		m_player1->setDeckForGameMode(2);
		m_player2->setDeckForGameMode(2);

		ActiveMatch match{ m_player1, m_player2, 0};

		match.startMatch();

		if (!match.checkIfMatchIsDraw())
		{
			if (m_player1->getName() == match.playerWhoWon())
			{
				roundsWonByPlayer1++;
			}
			else
			{
				roundsWonByPlayer2++;
			}
		}

		std::cout << '\n';
		std::cout << "Runda a fost castigata de " << match.playerWhoWon() << '\n';
	}


	if (roundsWonByPlayer1 > roundsWonByPlayer2)
	{
		std::cout << "Meciul a fost castigat de " << m_player1->getName() << '\n';
		m_playerScore1++;
	}
	else
	{
		std::cout << "Meciul a fost castigat de " << m_player2->getName() << '\n';
		m_playerScore2++;
	}

	std::cout << "Scor:" << '\n';
	std::cout << m_player1->getName() << ": " << m_playerScore1 << '\n';
	std::cout << m_player2->getName() << ": " << m_playerScore2 << '\n';
}
