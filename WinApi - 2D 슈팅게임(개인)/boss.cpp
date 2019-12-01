#include "stdafx.h"
#include "boss.h"



boss::boss()
{
	_fireCountBoss = 0;
}


boss::~boss()
{
}

HRESULT boss::init(const char * imagename, float Ex, float Ey, float anlge, float speed, int pattern, int movePhase, float currentHP, float maxHP)
{
	enemy::init(imagename, Ex, Ey, anlge, speed, pattern, movePhase, currentHP, maxHP);

	_progressBar = new progressBar;
	_progressBar->init( "피통앞","피통뒤",0, 50, WINSIZEX, 30);

	return S_OK;
}

void boss::update()
{
	enemy::update();

	_progressBar->setGauge(_currentHP, _maxHP);
	_progressBar->update();
	
}

void boss::render()
{
	enemy::render();

	_progressBar->render();
}
void boss::fire()
{
	
}

void boss::move()
{


	switch (_movePhase)
	{
	case 1:
		_angle = PI / 2;
		_y += _speed * sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_y >= 215)
		{
			_y = 215;
		_movePhase++;
		}

		break;

	case 2:
		_x -= _speed* sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_x <= 150) 
		{
			_x = 150;
			_movePhase++;
		}
		break;

	case 3:
		_x += _speed* sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_x >= WINSIZEX-150)
		{
			_x = WINSIZEX - 150;
			_movePhase++;
		}
		break;

	case 4:
		_angle = getAngle(_x, _y, WINSIZEX / 2, WINSIZEY / 2);
		_x += _speed * cosf(_angle);
		_y += _speed *-sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

		if (getDistance(_x, _y, WINSIZEX / 2, WINSIZEY / 2) <= 20)	_movePhase ++;
		
		break;
	case 5:
		_angle = getAngle(_x, _y, WINSIZEX / 2, 215);
		_x += _speed * cosf(_angle);
		_y += _speed *-sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_y <= 220) _movePhase++;
		break;
	case 6:

		_angle = PI / 2;
		_x -= _speed* sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_x <= 150)
		{
			_x =  150;
			_movePhase++;
		}
		break;
	case 7:
		_angle = getAngle(_x, _y, WINSIZEX / 2, WINSIZEY / 2);
		_x += _speed * cosf(_angle);
		_y += _speed *-sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

		if (getDistance(_x, _y, WINSIZEX / 2, WINSIZEY / 2) <= 20)	_movePhase++;
		break;
	case 8:
		_angle = getAngle(_x, _y, WINSIZEX / 2, 215);
		_x += _speed * cosf(_angle);
		_y += _speed *-sinf(_angle);
		_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
		if (_y <= 220) _movePhase = 1;
		
		break;
	}
	
}
