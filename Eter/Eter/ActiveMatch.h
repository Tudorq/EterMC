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
	std::string m_playerWhoWon;
	bool m_isFirstTurn;
	bool m_isDraw;
	bool m_isLastTurn;
	bool m_playedLastTurn;
	Board m_board;
public:
	ActiveMatch(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2, int gameMode);
	int startMatch();
	bool startTurn(std::shared_ptr<Player> currentPlayer);
	bool checkIfMatchIsDraw();
	std::string playerWhoWon();

};

