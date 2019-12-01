#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(const char * imagename, float Ex, float Ey, float anlge, float speed, int pattern, int movePhase, float currentHP, float maxHP)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;

	_rndFireCount = 10;
	_imageName = IMAGEMANAGER->findImage(imagename);
	_x = Ex;
	_y = Ey;
	_angle = anlge;
	_speed = speed;
	_pattern = pattern;
	_movePhase = movePhase;
	_currentHP = currentHP;
	_maxHP = maxHP;
	_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	if (_count % 2 == 0)
	{
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		if (_currentFrameX >= _imageName->getMaxFrameX())
		{
			_currentFrameY++;

			if (_currentFrameY > _imageName->getMaxFrameY()) _currentFrameY = 0;

			_currentFrameX = 0;
			
		}
	

		_count = 0;
	}




	move();
}

void enemy::render()
{
	draw();
}

void enemy::move()
{
}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

bool enemy::bulletCountFire()
{
	_fireCount++;

	if (_fireCount % _rndFireCount == 0)
	{
		_fireCount = 0;
		_rndFireCount = RND->getFromIntTo(10,100);
		return true;
	}

	return false;
}
