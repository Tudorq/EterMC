#include "Player.h"

Player::Player()
{
	m_hasWizard = 0;
	m_usedWizard = 0;

}

Player::Player(std::string name)
{
	setName(name);
	m_hasWizard = 0;
	m_usedWizard = 0;
}

void Player::setName(std::string name)
{
	m_name = name;
}

std::string Player::getName()
{
	return m_name;
}

void Player::setDeck(std::vector<int> deck)
{
	m_deck = deck;
}

std::vector<int> Player::getDeck()
{
	return m_deck;
}

void Player::setDeckForGameMode(int gameMode)
{
	if (gameMode == 1) {
		m_deck = { 1, 1, 2, 2, 3, 3, 4 };
	}
	else if (gameMode == 2) {
		m_deck = { 1, 1, 2, 2, 2, 3, 3, 3, 4, 0 };
	}
}

void Player::removePlacedCardFromDeck(int card)
{
	m_deck.erase(find(m_deck.begin(), m_deck.end(), card));
}
