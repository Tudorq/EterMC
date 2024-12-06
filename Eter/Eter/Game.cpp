#include "Game.h"

Game::Game()
{
	this->playerScore1 = 0;
	this->playerScore2 = 0;
	this->gameMode = 0;
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

	this->player1 = std::make_shared<Player>(name1);
	this->player2 = std::make_shared<Player>(name2);

	std::cout << "Jucatorii au fost creati \n\n";

	std::cout << "Bine ati venit " << this->player1->getName() << " si " << this->player2->getName() << "\n\n";

	std::cout << "Alegeti modul de joc: \n 1. Modul antrenament \n 2. Duelul vrajitorilor \n ";
	std::cin >> selectedGameMode;

	while (selectedGameMode != 1 && selectedGameMode != 2) {
		std::cout << "Ati selectat " << selectedGameMode << " care nu este un mod de joc valid\n Incercati din nou: ";
		std::cin >> selectedGameMode;
	}

	this->gameMode = selectedGameMode;
}

void Game::startGame()
{
	if (this->gameMode == 1) {
		this->startGameModeTraining();
	}
	else if (this->gameMode == 2) {
		this->startGameModeWizard();
	}
}

void Game::startGameModeTraining()
{
	int roundsWonByPlayer1 = 0, roundsWonByPlayer2 = 0;
	while (roundsWonByPlayer1 != 2 || roundsWonByPlayer2 != 2) {
		this->player1->setDeckForGameMode(1);
		this->player2->setDeckForGameMode(2);

		ActiveMatch match = ActiveMatch(player1, player2, 1);

		match.startMatch();
		break;




	}



}

void Game::startGameModeWizard()
{
}
