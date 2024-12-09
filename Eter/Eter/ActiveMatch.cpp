#include "ActiveMatch.h"


ActiveMatch::ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode)
{
	this->player1 = player1;
	this->player2 = player2;
	this->currentPlayer = 1;
	this->isFinished = false;
	this->board = Board(gameMode);
}

int ActiveMatch::startMatch()
{
	int cardPicked;
	int x, y;
	std::cout << "Meciul a inceput \n";





	while (!isFinished) {

		/*for (int i = 0; i < this->board.getBoard().size(); i++) {
			for (int j = 0; j < this->board.getBoard()[0].size(); j++) {
				std::cout << " " << this->board.getBoard()[i][j] << "(" << i + 1 << "," << j + 1 << ")" << " ";
			}
			std::cout << "\n";
		}*/

		std::cout << board;
		if (currentPlayer == 1) {
			this->startTurn(this->player1);

		}
		else {
			this->startTurn(this->player2);
		}


		break;
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
}
