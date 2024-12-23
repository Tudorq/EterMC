#pragma once
#include <memory>
#include "Player.h"
#include "Board.h"
#include <iostream>
class ActiveMatch
{
private:
	std::shared_ptr<Player> m_player1;
	std::shared_ptr<Player> m_player2;
	int m_currentPlayer;
	bool m_isFinished;
	Board m_board;
public:
	ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode);
	int startMatch();
	void startTurn(std::shared_ptr<Player> currentPlayer);

};

