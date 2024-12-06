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

		for (int i = 0; i < this->board.getBoard().size(); i++) {
			for (int j = 0; j < this->board.getBoard()[0].size(); j++) {
				std::cout << " " << this->board.getBoard()[i][j] << "(" << i + 1 << "," << j + 1 << ")" << " ";
			}
			std::cout << "\n";
		}


		if (currentPlayer == 1) {
			std::cout << "Tura actuala: " << player1->getName() << "\n";
			std::cout << "Carti disponibile: ";
			for (int i = 0; i < player1->getDeck().size(); i++) {
				std::cout << player1->getDeck()[i] << " ";
			}
		}

		if (currentPlayer == 2) {
			std::cout << "Tura actuala: " << player2->getName() << "\n";
			for (int i = 0; i < player2->getDeck().size(); i++) {
				std::cout << player2->getDeck()[i] << " ";
			}
		}

		std::cout << "\n";

		std::cin >> cardPicked;
		std::cout << "Alege pozitia(x,y): ";

		std::cin >> x >> y;

		break;
	}

	return 0;
}
