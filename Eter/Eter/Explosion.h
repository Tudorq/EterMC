#pragma once
#include <vector>
#include <ctime>
#include <iostream>
#include "ExplosionEffects.h"
class Explosion
{

private:
	std::vector<std::vector<ExplosionEffects>> m_explosionMatrix;
	int m_size;

public:
	Explosion();
	Explosion(int size);
	void generateExplosionCards();
	void rotate(bool left);
	std::vector<std::vector<int>> getExplosionCards();
	friend std::ostream& operator << (std::ostream& out, const std::vector<std::vector<ExplosionEffects>> explosionMatrix);

};

