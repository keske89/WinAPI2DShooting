#include "stdafx.h"
#include "Bullets.h"
#include "User.h"

Bullets::Bullets()
{
}


Bullets::~Bullets()
{
}

HRESULT Bullets::init(const char * imageName, int bulletMax, float range, bool isHitAble)
{

	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;
	_isHitAble = isHitAble;

	return S_OK;
}

void Bullets::release(void)
{
}

void Bullets::update(void)
{
	move();
}

void Bullets::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->_rc.left, _viBullet->_rc.top);
	}
}

void Bullets::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet._speed = speed;
	bullet._radius = bullet.bulletImage->getWidth() / 2;
	bullet._x = bullet._fireX = x;
	bullet._y = bullet._fireY = y;
	bullet._angle = angle;

	bullet._rc = RectMakeCenter(bullet._x, bullet._y,
		bullet.bulletImage->getWidth(),
		bullet.bulletImage->getHeight());

	_vBullet.push_back(bullet);
}


void Bullets::fire2(float x, float y, int bulletNum, float speed)
{
	for (int i = 0; i < bulletNum; i++)
	{
		if (_bulletMax < _vBullet.size()) return;

		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
		bullet._speed = speed;
		bullet._radius = bullet.bulletImage->getWidth() / 2;
		bullet._x = bullet._fireX = x;
		bullet._y = bullet._fireY = y;
		bullet._angle = (i * 0.12);

		bullet._rc = RectMakeCenter(bullet._x, bullet._y,
			bullet.bulletImage->getWidth(),
			bullet.bulletImage->getHeight());

		_vBullet.push_back(bullet);
	}
	
}

void Bullets::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->_x += cosf(_viBullet->_angle) * _viBullet->_speed;
		_viBullet->_y += sinf(_viBullet->_angle) * _viBullet->_speed;

		_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_range < getDistance(_viBullet->_x, _viBullet->_y, _viBullet->_fireX, _viBullet->_fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Bullets::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}




bulletCard::bulletCard()
{
}

bulletCard::~bulletCard()
{
}

HRESULT bulletCard::init(int bulletMax, int range)
{	
	tagBullet bullet;
	bullet._cardCount = 0;
	_bulletMax = bulletMax;
	_range = range;
	return S_OK;
	
}

void bulletCard::release()
{
}

void bulletCard::update()
{
	
	move();
}

void bulletCard::render()
{
	

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{

		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->_rc.left,
			_viBullet->_rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->_cardCount++;

		if (_viBullet->_cardCount % 5 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->_cardCount = 0;
		}
	}

}

void bulletCard::fire(float x, float y, float angle, int CharCondition)
{
	if (_bulletMax < _vBullet.size()) return;
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	switch (CharCondition)
	{
	case CHARGREEN:
		bullet.bulletImage = IMAGEMANAGER->findImage("초록카드");
		bullet._damage = 5.0f;
		bullet._speed = 8.0f;
		break;

	case CHARYELLOW:
		bullet.bulletImage = IMAGEMANAGER->findImage("노랑카드");
		bullet._damage = 10.0f;
		bullet._speed = 10.0f;
		break;

		case CHARRED:
		bullet.bulletImage = IMAGEMANAGER->findImage("빨강카드");
		bullet._damage = 15.0f;
		bullet._speed = 20.0f;
		break;

	}
	
	bullet._angle = angle;
	bullet._x = bullet._fireX = x;
	bullet._y = bullet._fireY = y;
	bullet._rc = RectMakeCenter(bullet._x, bullet._y,20,40);
	_vBullet.push_back(bullet);
	
}

void bulletCard::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->_y -= _viBullet->_speed;
		_viBullet->_x -= _viBullet->_speed * -sinf(_viBullet->_angle);
		_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 20, 40);

		if (_range < getDistance(_viBullet->_x, _viBullet->_y, _viBullet->_fireX, _viBullet->_fireY))
		{
			
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void bulletCard::removeBulletCard(int arrNum)
{
	
	_vBullet.erase(_vBullet.begin() + arrNum);
}

bulletBird::bulletBird()
{
}

bulletBird::~bulletBird()
{
}

HRESULT bulletBird::init()
{
	tagBullet bullet;
	bullet._radius = 50;
	_birdCount = 0;

	


	return S_OK;
}

void bulletBird::release()
{
}

void bulletBird::update(float x, float y,bool birdf)
{
	
		move(x, y,birdf);
	
	
}

void bulletBird::render()
{

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
	
		_viBullet->bulletImage->render(getMemDC(),	_viBullet->_rc.left,_viBullet->_rc.top);
		
	}
	
}

void bulletBird::fire(float x, float y,int angle, int level, int CharCondition)
{
	tagBullet bullet;
	if (_bulletMax < _vBullet.size()) return;


	
	if (_birdCount >= level) return;
	
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet._angle = angle;
	bullet._radius = 80.0f;
	
	

	switch (CharCondition)
	{
	case CHARGREEN:
		bullet.bulletImage = IMAGEMANAGER->findImage("초록새");
		bullet._damage = 0.5f;
		bullet._speed = 5.0f;
		break;

	case CHARYELLOW:
		bullet.bulletImage = IMAGEMANAGER->findImage("노랑새");
		bullet._damage = 0.8f;
		bullet._speed = 7.5f;
		break;

	case CHARRED:
		bullet.bulletImage = IMAGEMANAGER->findImage("빨강새");
		bullet._damage = 1.0f;
		bullet._speed = 10.0f;
		break;

	}
	bullet._x = bullet._fireX = x;
	bullet._y = bullet._fireY = y;
	bullet._rc = RectMakeCenter(bullet._x, bullet._y, 90, 60);
	
	bullet._isfree = false;
	_birdCount++;
	_vBullet.push_back(bullet);

}

void bulletBird::move(float x, float y, bool birdf)
{
	
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (!birdf) _viBullet->_isfree = true;
		if (!_viBullet->_isfree)
		{
			_viBullet->_angle += 0.04;
		
			_viBullet->_y = y - _viBullet->_radius * -sinf(_viBullet->_angle);
			_viBullet->_x = x - _viBullet->_radius * cosf(_viBullet->_angle);
			_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 90, 60);

			if (_viBullet->_angle >= PI2) _viBullet->_angle = 0;
			++_viBullet;
		}
		else {
			_viBullet->_angle += 0.04;
			_viBullet->_speed += 0.12;
			_viBullet->_y -= _viBullet->_speed * -sinf(_viBullet->_angle+ PI/2);
			_viBullet->_x -= _viBullet->_speed * cosf(_viBullet->_angle + PI/2);
			_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 90, 60);

			if (_viBullet->_angle >= PI2) _viBullet->_angle = 0;

			if (_viBullet->_x>WINSIZEX || _viBullet->_x <0 || _viBullet->_y <0 || _viBullet->_y>WINSIZEY)
			{
			
				_viBullet = _vBullet.erase(_viBullet);
				_birdCount--;
			}
			else ++_viBullet;
		}
	   
	}
}


bulletBomb::bulletBomb()
{
}

bulletBomb::~bulletBomb()
{
}

HRESULT bulletBomb::init(int bulletMax)
{
	_bulletMax = bulletMax;
	_range = 250.0f;


	return S_OK;
	
}

void bulletBomb::release()
{
}

void bulletBomb::update()
{
	move();
}

void bulletBomb::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{

		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->_rc.left,
			_viBullet->_rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->_count++;

		if (_viBullet->_count % 5 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->_count = 0;
		}
	}
	
}

void bulletBomb::fire(float x, float y, int level)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet._fireCount = 0;
	bullet._radius = 498;
	bullet.bulletImage = IMAGEMANAGER->findImage("필살기");
	bullet._x = bullet._fireX = x;
	bullet._y = bullet._fireY = y ;
	bullet._isFire = true;
	bullet._damage = 5.0f;
	

	_vBullet.push_back(bullet);
}

void bulletBomb::move()
{
	
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (!_viBullet->_isFire) continue;

		 _viBullet->_fireCount++;
	
		_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, _viBullet->_radius, _viBullet->_radius);

		if (_viBullet->_fireCount > 250)
		{
			_viBullet->_fireCount = 0;
			_viBullet = _vBullet.erase(_viBullet);

			
		}
		else ++_viBullet;
	}
}

bulletEffect::bulletEffect()
{
}

bulletEffect::~bulletEffect()
{
}

HRESULT bulletEffect::init(int bulletMax)
{
	_bulletMax = bulletMax;
	return S_OK;
}

void bulletEffect::release()
{
}

void bulletEffect::update()
{
	move();
}

void bulletEffect::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->_rc.left,
			_viBullet->_rc.top,
			_viBullet->bulletImage->getFrameX(), 0);
		
		_viBullet->_effectCount++;

		if (_viBullet->_effectCount %  2 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->_effectCount = 0;
		}
	}
}

void bulletEffect::fire(float x, float y)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage("충돌");
	bullet._x = bullet._fireX = x;
	bullet._y = bullet._fireY = y;
	bullet._isFire = true;
	bullet._rc = RectMakeCenter(bullet._x, bullet._y, 30, 30);
	_vBullet.push_back(bullet);
	
}

void bulletEffect::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (!_viBullet->_isFire) continue;

		_viBullet->_fireCount++;

		_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 30, 30);

		if (_viBullet->_fireCount > 10)
		{
			_viBullet->_fireCount = 0;
			_viBullet = _vBullet.erase(_viBullet);
		

		}
		else ++_viBullet;
	}
}


bulletDead::bulletDead()
{
}

bulletDead::~bulletDead()
{
}

HRESULT bulletDead::init(int bulletMax)
{
	return S_OK;
}

void bulletDead::release()
{
}

void bulletDead::update()
{
	move();
}

void bulletDead::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->_rc.left,
			_viBullet->_rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->_deadCount++;

		if (_viBullet->_deadCount % 4 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->_deadCount = 0;
		}
	}
}

void bulletDead::fire(float x, float y)
{
	
		if (_bulletMax < _vBullet.size()) return;

		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = IMAGEMANAGER->findImage("죽음");
		bullet._x = bullet._fireX = x;
		bullet._y = bullet._fireY = y;
		bullet._isFire = true;
		bullet._rc = RectMakeCenter(bullet._x, bullet._y, 100, 100);
		_vBullet.push_back(bullet);

	
}

void bulletDead::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (!_viBullet->_isFire) continue;

		_viBullet->_fireCount++;

		_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 100, 100);

		if (_viBullet->_fireCount > 30)
		{
			_viBullet->_fireCount = 0;
			_viBullet = _vBullet.erase(_viBullet);


		}
		else ++_viBullet;
	}
}

bulletCoin::bulletCoin()
{
}

bulletCoin::~bulletCoin()
{
}

HRESULT bulletCoin::init(int bulletMax)
{
	return S_OK;
}

void bulletCoin::release()
{
}

void bulletCoin::update(int userX, int userY)
{
	move(userX,userY);
}

void bulletCoin::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
	
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->_rc.left,
			_viBullet->_rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->_coinCount++;

		if (_viBullet->_coinCount % 10 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->_coinCount = 0;
		}
	}
}

void bulletCoin::fire(float x, float y, float angle, float speed)
{
	
	
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.bulletImage = IMAGEMANAGER->findImage("동전");
		bullet._x = bullet._fireX = x;
		bullet._y = bullet._fireY = y;
		bullet._angle = angle;
		bullet._speed = speed;
		bullet._isFire = true;
		bullet._rc = RectMakeCenter(bullet._x , bullet._y, 40, 40);
		_vBullet.push_back(bullet);

	
	
	
}

void bulletCoin::move(int userX, int userY)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (!_viBullet->_isFire) continue;
	

			_viBullet->_angle = getAngle( _viBullet->_x, _viBullet->_y, userX, userY);

			_viBullet->_y += _viBullet->_speed* -sinf(_viBullet->_angle);
			_viBullet->_x += _viBullet->_speed * cosf(_viBullet->_angle);
			_viBullet->_rc = RectMakeCenter(_viBullet->_x, _viBullet->_y, 40, 40);
			
	
			

			if (_viBullet->_coinCount > 100)
			{
				_viBullet->_coinCount = 0;
				_viBullet = _vBullet.erase(_viBullet);
			}
			else ++_viBullet;
	}
}


void bulletCoin::removeBulletCoin(int arrNum)
{

	_vBullet.erase(_vBullet.begin() + arrNum);
}
