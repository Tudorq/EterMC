#pragma once
#include <memory>
#include "Board.h"
#include "Player.h"
class Wizard
{
public:

	enum Power
	{
		FIRE1,
		FIRE2,
		EARTH1,
		EARTH2,
		AIR1,
		AIR2,
		WATER1,
		WATER2,
	};

	Wizard();
	Wizard(int type);
	void usePower(int posX1 = -1, int posY1 = -1, int posX2 = -1, int posY2 = -1, int row = -1, int card, std::string playerName, bool isRow, bool position);
	void removeCard(int posX, int posY);
	void removeRow(int row);
	void coverCardWithSmallerNumber(int posX, int posY, int card, std::string playerName);
	void createHole(int posX, int posY);
	void moveOwnBoardDeck(int posX1, int posY1, int posX2, int posY2);
	void getExtraEter();
	void moveOtherBoardDeck(int posX1, int posY1, int posX2, int posY2);
	void moveEdgeRow(bool isRow, bool position);

private:
	Power m_pickedPower;
	bool wasUsed;
	std::shared_ptr<Player> m_player;
	std::shared_ptr<Board> m_board;
};

