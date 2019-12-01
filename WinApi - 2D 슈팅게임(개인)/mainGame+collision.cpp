#include "stdafx.h"
#include "mainGame.h"

//객체지향이 C++에서 지원이되면서 나온 설계 방식인데
//한 개 헤더파일은 여러개 cpp파일을 거느릴 수 있게 되면서
//지금 mainGame처럼 여러개 클래스들이 모일 가능성이 있는 객체는
//함수당 여러개 CPP파일로 분리해서 가독성 + 관리가 용이하게 할수있다



void mainGame::collision(void)
{
	for ( int i = 0; i < _user->getBulletCard()->getVBullet().size(); i++ )
	{
		for ( int j = 0; j < _em->getVMinion().size(); j++ )
		{
			RECT temp;
			if ( IntersectRect(&temp, &_user->getBulletCard()->getVBullet()[i]._rc, &_em->getVMinion()[j]->getRect()) )
			
			{
				

			
				_user->getBulletEffect()->fire(_user->getBulletCard()->getVBullet()[i]._x, _user->getBulletCard()->getVBullet()[i]._y-25);
				_em->hitDamage(j, _user->getBulletCard()->getVBullet()[i]._damage);
				if (_em->getVMinion()[j]->getHP() <= 0)
				{
					_user->getBulletDead()->fire(_user->getBulletCard()->getVBullet()[i]._x, _user->getBulletCard()->getVBullet()[i]._y - 25);
				_user->getBulletCoin()->fire(_user->getBulletCard()->getVBullet()[i]._x, _user->getBulletCard()->getVBullet()[i]._y, PI/2, 10.0f);
					_em->removeMinion(j);
				}
				_user->getBulletCard()->removeBulletCard(i);
							
				
				break;
			}
		}
	}
}

void mainGame::collisionBird()
{
	for (int i = 0; i < _user->getBulletBird()->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_user->getBulletBird()->getVBullet()[i]._rc, &_em->getVMinion()[j]->getRect()))
			{
			


				_user->getBulletEffect()->fire(_user->getBulletBird()->getVBullet()[i]._x, _user->getBulletBird()->getVBullet()[i]._y);
				_em->hitDamage(j, _user->getBulletBird()->getVBullet()[i]._damage);
				if (_em->getVMinion()[j]->getHP() <= 0)
				{
					_user->getBulletDead()->fire(_user->getBulletBird()->getVBullet()[i]._x, _user->getBulletBird()->getVBullet()[i]._y);
					_user->getBulletCoin()->fire(_user->getBulletBird()->getVBullet()[i]._x, _user->getBulletBird()->getVBullet()[i]._y, 0, 10.0f);
					_em->removeMinion(j);
				}

				break;
			}
		}
	}
}

void mainGame::collisionBomb()
{
	for (int i = 0; i < _user->getBulletBomb()->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_user->getBulletBomb()->getVBullet()[i]._rc, &_em->getVMinion()[j]->getRect()))
			{
				


				_user->getBulletEffect()->fire(_user->getBulletBomb()->getVBullet()[i]._x, _user->getBulletBomb()->getVBullet()[i]._y);
				_em->hitDamage(j, _user->getBulletBomb()->getVBullet()[i]._damage);
				if (_em->getVMinion()[j]->getHP() <= 0)
				{
					_user->getBulletDead()->fire(_user->getBulletBomb()->getVBullet()[i]._x, _user->getBulletBomb()->getVBullet()[i]._y);
					_user->getBulletCoin()->fire(_user->getBulletBomb()->getVBullet()[i]._x, _user->getBulletBomb()->getVBullet()[i]._y, 0, 10.0f);
					_em->removeMinion(j);

				}
				break;
			}
			
		}
	}

	for (int i = 0; i < _user->getBulletBomb()->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getBullet()->getVBullet().size(); j++)
		{
			RECT temp1;
			if (IntersectRect(&temp1, &_user->getBulletBomb()->getVBullet()[i]._rc, &_em->getBullet()->getVBullet()[j]._rc))
			{
				_em->getBullet()->removeBullet(j);
			}
		}
	}
	
			
}

void mainGame::collisonCoin()  // 유저랑 부딪히는것들
{

	for (int i = 0; i < _user->getBulletCoin()->getVBullet().size(); i++)
	{
			RECT temp;
			if (IntersectRect(&temp, &_user->getBulletCoin()->getVBullet()[i]._rc, &_user->getUserRect()))

			{
				
				_user->setUserScore(100);
				_user->getBulletCoin()->removeBulletCoin(i);


				break;
			}
		}
	
	
		for (int j = 0; j < _em->getBullet()->getVBullet().size(); j++)
		{
			RECT temp1;
			if (10>getDistance(_user->getUserX(), _user->getUserY(), _em->getBullet()->getVBullet()[j]._x, _em->getBullet()->getVBullet()[j]._y))
			{
				_em->getBullet()->removeBullet(j);
				_user->setUserLife(_user->getUserLife()-1);
				_user->setUserScore (-_user->getUserScore());
			}
		}
	
}


