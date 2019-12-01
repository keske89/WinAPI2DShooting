#include "stdafx.h"
#include "Minion2.h"


Minion2::Minion2()
{
}


Minion2::~Minion2()
{
}

void Minion2::fire()
{
}

void Minion2::move()
{
	switch (_movePhase)
	{
	case 0:
		_angle = PI / 2;
		_speed = 3.5f;
		_x += _speed* sinf(_angle);
		_y += _speed* sinf(_angle);

		if (_x >= WINSIZEX - 100)
		{
			_x = WINSIZEX - 100;
			_movePhase = 1;
		}
		break;

	case 1:
		_angle = PI / 2;
		_speed = 3.5f;
		_x -= _speed* sinf(_angle);
		_y -= _speed* sinf(_angle);

		if (_x <= 100)
		{
			_x = 100;
			_movePhase = 0;
		}
		break;

	case 2:
		_angle = PI / 2;
		_speed = 3.5f;
		_x -= _speed* sinf(_angle);
		_y += _speed* sinf(_angle);

		if (_x <=  100)
		{
			_x = 100;
			_movePhase = 3;
		}
		break;

	case 3:
		_angle = PI / 2;
		_speed = 3.5f;
		_x += _speed* sinf(_angle);
		_y -= _speed* sinf(_angle);

		if (_x >= WINSIZEX - 100)
		{
			_x = WINSIZEX - 100;
			_movePhase = 2;
		}
		break;


		
	}
	_rc = RectMakeCenter(_x, _y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
}
