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
	int m_gameMode;
	std::shared_ptr<Player> m_player1;
	std::shared_ptr<Player> m_player2;
	int m_playerScore1;
	int m_playerScore2;

public:
	Game();
	void createGame();
	void startGame();
	void startGameModeTraining();
	void startGameModeWizard();

};

