#pragma once
#include <memory>
#include "Player.h"
#include "Board.h"
#include <iostream>
class ActiveMatch
{
private:
	std::shared_ptr<Player> player1;
	std::shared_ptr<Player> player2;
	int currentPlayer;
	bool isFinished;
	Board board;
public:
	ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode);
	int startMatch();

};

