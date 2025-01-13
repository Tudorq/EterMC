#include "Wizard.h"

Wizard::Wizard()
{
	m_pickedPower = FIRE1;
}

Wizard::Wizard(int type)
{
	m_pickedPower = Power(type);
}

void Wizard::removeCard()
{
}

void Wizard::removeRow()
{
}

void Wizard::coverCardWithSmallerNumber()
{
}

void Wizard::createHole()
{
}

void Wizard::moveOwnBoardDeck()
{
}

void Wizard::getExtraEter()
{
}

void Wizard::moveOtherBoardDeck()
{
}

void Wizard::moveEdgeRow()
{
}
