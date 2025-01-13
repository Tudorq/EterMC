#pragma once
#include <memory>
#include "Board.h"
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
	void usePower();
	void removeCard();
	void removeRow();
	void coverCardWithSmallerNumber();
	void createHole();
	void moveOwnBoardDeck();
	void getExtraEter();
	void moveOtherBoardDeck();
	void moveEdgeRow();

private:
	Power m_pickedPower;
	bool wasUsed;
	std::shared_ptr<Board> m_board;
};

