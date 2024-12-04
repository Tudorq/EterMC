#include "Player.h"

Player::Player()
{
	this->hasWizard = 0;
}

Player::Player(std::string name)
{
	this->setName(name);
	this->hasWizard = 0;
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::getName()
{
	return this->name;
}

void Player::setDeck(std::vector<int> deck)
{
	this->deck = deck;
}

std::vector<int> Player::getDeck()
{
	return this->deck;
}

void Player::setDeckForGameMode(int gameMode)
{
	if (gameMode == 1) {
		this->deck = { 1, 1, 2, 2, 3, 3, 4 };
	}
	else if (gameMode == 2) {
		this->deck = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 0 };
	}
}
