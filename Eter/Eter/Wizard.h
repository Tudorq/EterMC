#pragma once
class Wizard
{
private:
	int type;
public:
	Wizard();
	Wizard(int type);
	void removeCard();
	void removeRow();
	void coverCardWithSmallerNumber();
	void createHole();
	void moveOwnBoardDeck();
	void getExtraEter();
	void moveOtherBoardDeck();
	void moveEdgeRow();

};

