#include "stdafx.h"
#include "User.h"
#include "enemyManager.h"



User::User()
{
}


User::~User()
{
}

HRESULT User::init()
{

	_userFrontImage = IMAGEMANAGER->findImage("플레이어");

	x = WINSIZEX / 2;
	y = WINSIZEY - 150;

	_rc = RectMakeCenter(x, y, 40,80);

	_bulletCard = new bulletCard;
	_bulletCard->init(100, 900);
	_bulletBomb = new bulletBomb;
	_bulletBomb->init(1);
	_bulletBird = new bulletBird;
	_bulletBird->init();
	_bulletEffect = new bulletEffect;
	_bulletEffect->init(100);
	_bulletDead = new bulletDead;
	_bulletDead->init(100);
	_bulletCoin = new bulletCoin;
	_bulletCoin->init(10000);
	
	 _bombCount = 3;
	 _birdFire = false;
	 _lifeCount = 3;
	 _score = 0;
	 _level = 1;
	 _speed = 8.0f;
	 _currentHP = 100;
	 _maxHP = 100;
	 _fireCount = 0;
	 // _alphaValue = 255;
	 _charCondition = CHARGREEN;
	 
	

	return S_OK;
}

void User::release()
{
}

void User::update()
{
	
	


	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left >= 0)
	{
		x -= _speed;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right <= WINSIZEX)
	{
		x += _speed;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top >= 0)
	{
		y -= _speed;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom <= WINSIZEY)
	{
		y += _speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_SHIFT)) //미세조정활성
	{
		_speed = 2.0f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_SHIFT)) // 미세조정 종료
	{
		_speed = 6.0f;
	}

	if (KEYMANAGER->isStayKeyDown('A')) //기본탄환
	{
		_fireCount++;
		if (_fireCount % 9 == 0)
		
			
			switch (_level)
			{
			case 1:
				_bulletCard->fire(x, y, 0, _charCondition);
				break;

			case 2:
				_bulletCard->fire(x, y, -PI / 45, _charCondition);
				_bulletCard->fire(x, y, PI / 45, _charCondition);
				break;

			case 3:
				_bulletCard->fire(x, y, 0, _charCondition);
				_bulletCard->fire(x, y, -PI / 45, _charCondition);
				_bulletCard->fire(x, y, PI / 45, _charCondition);
				break;

			
		}

	}
	if (KEYMANAGER->isStayKeyDown('S'))//호밍기
	{
		if (_birdFire == false)
		{
			switch (_level)
			{
			case 1:
				_bulletBird->fire(x, y, 0,_level, _charCondition);
				_birdFire = true;
				break;

			case 2:
				_bulletBird->fire(x, y, 0, _level, _charCondition);
				_bulletBird->fire(x, y,	PI, _level, _charCondition);
				_birdFire = true;
				break;

			case 3:
				_bulletBird->fire(x, y, 0, _level, _charCondition);
				_bulletBird->fire(x, y, PI/3*2, _level, _charCondition);
				_bulletBird->fire(x, y, PI/3*4, _level, _charCondition);
				_birdFire = true;
				break;
			}

		}
	}

		if (KEYMANAGER->isOnceKeyUp('S'))//호밍기
		{
				_birdFire = false;
		}
		if (KEYMANAGER->isOnceKeyDown('D'))//폭탄
		{
			if (_bombCount >= 1)
			{
				_bombCount--;
				_bulletBomb->fire(x, y, _level);
			}

		}
		_bulletCard->update();
		_bulletBomb->update();
		_bulletBird->update(x, y, _birdFire);
		_bulletEffect->update();
		_bulletDead->update();
		_bulletCoin->update(x,y);

		_rc = RectMakeCenter(x, y, 40, 80);
	
		

	if (_score / 1000 == 0) _level = 1;
	if (_score / 1000 > 1 && 5 > _score / 1000) _level = 2;
	if (_score / 1000 > 5) _level = 3;
}

void User::render()
{
	switch (_charCondition)
	{
	case CHARGREEN :
		_userBackImage = IMAGEMANAGER->findImage("초록배경");
		break;

	case CHARYELLOW:
		_userBackImage = IMAGEMANAGER->findImage("노랑배경");
		break;

	case CHARRED:
		_userBackImage = IMAGEMANAGER->findImage("빨강배경");
		break;
	}

	_userBackImage->render(getMemDC(), _rc.left, _rc.top);
	_userFrontImage->render(getMemDC(), _rc.left, _rc.top);

	_bulletCard->render();
	_bulletBomb->render();
	_bulletBird->render();
	_bulletEffect->render();
	_bulletDead->render();
	_bulletCoin->render();
}

void User::removeMissile(int arrNum)
{
	_bulletCard->removeBulletCard(arrNum);
}

void User::collison()
{
}

void User::hitDamage(float damage)
{
	_currentHP -= damage;
}
