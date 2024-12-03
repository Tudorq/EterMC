#pragma once
#include <vector>
#include "Player.h"
#include "ActiveMatch.h"
#include <iostream>
class Game
{

private:
	int gameMode;
	ActiveMatch match;
	Player player1;
	Player player2;
	int playerScore1;
	int playerScore2;

public:
	Game();
	void createGame();
	void startGame();

};

