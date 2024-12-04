#pragma once
#include <vector>
#include "Player.h"
#include "ActiveMatch.h"
#include <iostream>
#include "Board.h"
#include <memory>
class Game
{

private:
	int gameMode;
	ActiveMatch match;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	int playerScore1;
	int playerScore2;

public:
	Game();
	void createGame();
	void startGame();
	void startGameModeTraining();
	void startGameModeWizard();

};

