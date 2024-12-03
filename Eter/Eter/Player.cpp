#include "Player.h"

Player::Player()
{
}

Player::Player(std::string name)
{
	this->setName(name);
}

void Player::setName(std::string name)
{
	this->name = name;
}

std::string Player::getName()
{
	return this->name;
}
