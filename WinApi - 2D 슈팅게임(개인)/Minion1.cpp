#include "stdafx.h"
#include "Minion1.h"


Minion1::Minion1()
{
}


Minion1::~Minion1()
{
}


void Minion1::fire()
{


		
				//_bullet->fire2(_rcBoss.left + (_rcBoss.right - _rcBoss.left) / 2,
				//	_rcBoss.top + (_rcBoss.bottom - _rcBoss.top) / 2, 52, 3.0f);    // PI 해바라기
	

}

void Minion1::move()
{
	switch (_movePhase)
	{
	case 0:
		_angle = PI / 2;
		_speed = 3.0f;
		_x += _speed;
		_y += RND->getFromFloatTo(-5.0f,5.0f);
		if (_x >= WINSIZEX) _movePhase = 1;
			
		break;

	case 1:
		_angle = PI / 2;
		_speed = 3.0f;
		_y += RND->getFromFloatTo(-5.0f, 5.0f);
		_x -= _speed;
		if (_x <= 0) _movePhase = 0;
		break;

	
	}
	_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

}
