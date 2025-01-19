#include "Explosion.h"


Explosion::Explosion()
{
	m_size = 0;
}

Explosion::Explosion(int size)
{
	size = size;
}

void Explosion::generateExplosionCards()
{
	srand(time(0));
	ExplosionEffects effect;
	int numOfEffectsLeft;

	if (m_size == 3)
	{
		numOfEffectsLeft = 2 + rand() % 3;
	}
	else
	{
		numOfEffectsLeft = 3 + rand() % 4;
	}


	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (rand() % 2 && numOfEffectsLeft > 0)
			{
				effect = ExplosionEffects(rand() % 3);
				m_explosionMatrix[i][j] = effect;
			}
			else
			{
				m_explosionMatrix[i][j] = ExplosionEffects::NOEFFECT;
			}
		}
	}
}

void Explosion::rotate(bool left)
{
	std::vector<std::vector<ExplosionEffects>> aux(m_explosionMatrix.size(), std::vector<ExplosionEffects>(m_explosionMatrix.size(), ExplosionEffects::NOEFFECT));

	if (left)
	{
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				aux[m_size - j - 1][i] = m_explosionMatrix[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < m_size; i++) {
			for (int j = 0; j < m_size; j++) {
				aux[j][m_size - i - 1] = m_explosionMatrix[i][j];
			}
		}
	}

	m_explosionMatrix = aux;
}

std::vector<std::vector<int>> Explosion::getExplosionCards()
{
	return std::vector<std::vector<int>>();
}

std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<ExplosionEffects>> explosionMatrix)
{
	for (int i = 0; i < explosionMatrix.size(); i++)
	{
		for (int j = 0; j < explosionMatrix.size(); j++)
		{
			switch (explosionMatrix[i][j])
			{
			case ExplosionEffects::RETURN:
				out << "|" << 1;
			case ExplosionEffects::REMOVE:
				out << "|" << 2;
			case ExplosionEffects::HOLE:
				out << "|" << 3;
			case ExplosionEffects::NOEFFECT:
				out << "|" << 0;
			default:
				break;
			}
		}
		out << "|" << "\n";
	}

	return out;
}
