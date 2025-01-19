//#include "Explosion.h"
//
//
//Explosion::Explosion()
//{
//	m_gameMode = 0;
//}
//
//Explosion::Explosion(int gameMode)
//{
//	m_gameMode = gameMode;
//}
//
//void Explosion::generateExplosionCards()
//{
//	srand(time(0));
//	ExplosionEffects effect;
//	int numOfEffectsLeft;
//
//	if (m_gameMode == 1)
//	{
//		numOfEffectsLeft = 2 + rand() % 3;
//
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				if (rand() % 2 && numOfEffectsLeft > 0)
//				{
//					effect = ExplosionEffects(rand() % 3);
//					m_explosionMatrix[i][j] = effect;
//				}
//				else
//				{
//					m_explosionMatrix[i][j] = ExplosionEffects::NOEFFECT;
//				}
//			}
//		}
//	}
//}
//
//void Explosion::rotate(bool left)
//{
//	if (left)
//	{
//
//	}
//}
//
//std::vector<std::vector<int>> Explosion::getExplosionCards()
//{
//	return std::vector<std::vector<int>>();
//}
//
////std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<ExplosionEffects>> explosionMatrix)
////{
////	for (int i = 0; i < explosionMatrix.size(); i++)
////	{
////		for (int j = 0; j < explosionMatrix.size(); j++)
////		{
////			switch (explosionMatrix[i][j])
////			{
////			case ExplosionEffects::RETURN:
////				out << "|" << 1;
////			case ExplosionEffects::REMOVE:
////				out << "|" << 2;
////			case ExplosionEffects::HOLE:
////				out << "|" << 3;
////			case ExplosionEffects::NOEFFECT:
////				out << "|" << 0;
////			default:
////				break;
////			}
////		}
////		out << "|" << "\n";
////	}
////
////	return out;
////}
