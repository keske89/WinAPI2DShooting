#include "stdafx.h"
#include "enemyManager.h"
#include "User.h"


enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	_bullet = new Bullets;
	_bullet->init("탄환1", 3000, 800, true);
	_bullet2 = new Bullets;
	_bullet2->init("탄환2", 50, 800, false);
	_bullet5 = new Bullets;
	_bullet5->init("탄환5", 200, 800, false);
	stageNum = MINION;
	wave = 0;
	return S_OK;
	
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	
	_bullet->update();
	minionBulletFire();
	collison();
	UserState();
}

void enemyManager::render()
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	
	_bullet->render();
}

void enemyManager::setMinion()
{
	switch (stageNum)
	{
	case MINION:
		
		for (int i = 0; i < 10; i++)
		{
			enemy* _Minion1;
			_Minion1 = new Minion1;
			_Minion1->init("박쥐", 0 - i * 80, RND->getFromFloatTo(100, WINSIZEY / 3), PI / 2, 2.5f, 1, 0, 5, 5);
			_vMinion.push_back(_Minion1);
			_Minion1 = new Minion1;
			_Minion1->init("박쥐", WINSIZEX + i * 80, RND->getFromFloatTo(100, WINSIZEY / 3), PI / 2, 2.5f, 1, 1, 5, 5);
			_vMinion.push_back(_Minion1);
		}
		wave++;
		if (wave == 3)
		{
			wave = 0; 
			stageNum++;
		}
		break;

	case MINION2:

		
		for (int i = 0; i < 4; i++)
		{
			enemy* _Minion2;
			_Minion2 = new Minion2;
			_Minion2->init("유령", 0 - (i+1) * 80 , -80, PI / 2, 2.5f, 1, 0, 100, 100);
			_vMinion.push_back(_Minion2);
			_Minion2 = new Minion2;
			_Minion2->init("유령", WINSIZEX + (i+1)* 80, -80, PI / 2, 2.5f, 1, 2, 100, 100);
			_vMinion.push_back(_Minion2);
		}
		wave++;
		if (wave == 3)
		{
			wave = 0;
			stageNum++;
		}
		break;

	case MINION3:
		for (int i = 0; i < 3; i++)
		{
			enemy* _Minion2;
			_Minion2 = new Minion2;
			_Minion2->init("유령", (1 + i) * 80, 100, PI / 2, 2.5f, 0, 0, 100, 100);
			_vMinion.push_back(_Minion2);
			_Minion2 = new Minion2;
			_Minion2->init("유령", WINSIZEX - (1 + i) * 80, 100, PI / 2, 2.5f, 1, 2, 100, 100);
			_vMinion.push_back(_Minion2);
		}
		wave++;
		if (wave == 3)
		{
			wave = 0;
			stageNum++;
		}
		break;

	case BOSS:
		enemy* _boss;
		_boss = new boss;
		_boss->init("보스", WINSIZEX / 2, -215, 0, 2.0f, 8,1,5000,5000);
		_vMinion.push_back(_boss);

		break;
	}
}

void enemyManager::minionBulletFire(void)
{

	////////////////////////////////////////보스 발사패턴///////////////////////////////////////////////////
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		//RECT _rcBoss;
		//_rcBoss = (*_viMinion)->getRect();

		
			switch ((*_viMinion)->getPattern())

			{
			case 0:
				if ((*_viMinion)->bulletCountFire())
				{
					_bullet->fire2((*_viMinion)->getRect().left + ((*_viMinion)->getRect().right - (*_viMinion)->getRect().left) / 2,
						(*_viMinion)->getRect().top + ((*_viMinion)->getRect().bottom - (*_viMinion)->getRect().top) / 2, 5, 7.0f);    // PI 해바라기
				}

				break;
			case 1:
				if ((*_viMinion)->bulletCountFire())
			{
					
				_bullet->fire((*_viMinion)->getCenterX(), (*_viMinion)->getCenterY(), getAngle(_user->getUserX(), _user->getUserY()
					,(*_viMinion)->getCenterX(), (*_viMinion)->getCenterY()),7.0f);    // PI 해바라기
			}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
			if ((*_viMinion)->bulletCountFire())   //기본탄 뿌리기
			{
			
				if ((*_viMinion)->getMovePhase() >= 0)
				{
					_bullet->fire2((*_viMinion)->getCenterX(), (*_viMinion)->getCenterY(), 52, 3.0f);
					_bullet2->fire2((*_viMinion)->getCenterX(), (*_viMinion)->getCenterY(), 13, 3.0f);// PI 해바라기
				}
			}
				break;
			}
		}
		
	}
	



void enemyManager::removeMinion(int arrNum)
{
	
	_vMinion.erase(_vMinion.begin() + arrNum);
	if (_vMinion.size() <= 0) setMinion();
}




void enemyManager::collison()
{
}

void enemyManager::UserState()
{
	float d = 300;

		for (_bullet->getVIBullet() = _bullet->getVBullet().begin(); _bullet->getVIBullet() != _bullet->getVBullet().end(); ++_bullet->getVIBullet())
		{

			if (d > getDistance(_bullet->getVIBullet()->_x, _bullet->getVIBullet()->_y, _user->getUserX(), _user->getUserY()))
				d = getDistance(_bullet->getVIBullet()->_x, _bullet->getVIBullet()->_y, _user->getUserX(), _user->getUserY());

		
		}

		if (d < 200 && d>100) _user->setUserCon(CHARYELLOW);
		else if (d < 100) _user->setUserCon(CHARRED);
		else _user->setUserCon(CHARGREEN);

	

}
void enemyManager::hitDamage(int arrNum, float damage)
{
	_vMinion[arrNum]->setHP(_vMinion[arrNum]->getHP() - damage);
}
