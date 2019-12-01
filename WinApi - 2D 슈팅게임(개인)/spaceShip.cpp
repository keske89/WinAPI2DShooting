#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{

}


HRESULT spaceShip::init()
{
	//플레이어 비행기 이미지 셋팅 후 가운대로 좌표 조절
	_ship = IMAGEMANAGER->addImage("플레이어", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2);
	_ship->setY(WINSIZEY / 2 + 250);

	_missile = new missile;
	_missile->init(30, 400);


	_thaad = new THAAD;
	_thaad->init(3000, 500);

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 15, _ship->getWidth(), 5);


	_currentHP = _maxHP = 100;
	
	_alphaValue = 255;

	return S_OK;
}


void spaceShip::release()
{

}


void spaceShip::update() 
{
	if ( KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0 )
	{
		_ship->setX(_ship->getX() - 5);
	}

	if ( KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX )
	{
		_ship->setX(_ship->getX() + 5);
	}

	if ( KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0 )
	{
		_ship->setY(_ship->getY() - 5);
	}

	if ( KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY )
	{
		_ship->setY(_ship->getY() + 5);
	}

	if ( KEYMANAGER->isOnceKeyDown(VK_SPACE) )
	{
		_missile->fire(_ship->getCenterX(), _ship->getCenterY() - 30);
	}

	if ( KEYMANAGER->isOnceKeyDown('X') )
	{
		_thaad->fire(_ship->getCenterX(), _ship->getCenterY() - 10);
	}

	//세이부!!!!
	if ( KEYMANAGER->isOnceKeyDown(VK_F1) )
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("HexaTeam.txt", vStr);
	}

	//로드!!!!
	if ( KEYMANAGER->isOnceKeyDown(VK_F2) )
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("HexaTeam.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_maxHP = (atoi(vStr[1].c_str()));
		_ship->setX(atoi(vStr[2].c_str()));
		_ship->setY(atoi(vStr[3].c_str()));
		
	}

	_missile->update();
	_thaad->update();

	collision();

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 15);
	_hpBar->setGauge(_currentHP, _maxHP);

	_hpBar->update();

	_alphaValue--;

	if ( _alphaValue <= 0 ) _alphaValue = 255;


}


void spaceShip::render() 
{
	//_ship->render(getMemDC(), _ship->getX(), _ship->getY());
	_ship->alphaRender(getMemDC(), _ship->getX(), _ship->getY(),10,10,42,54, _alphaValue);
	_missile->render();
	_thaad->render();
	_hpBar->render();
}


void spaceShip::removeMissile(int arrNum)
{
	_thaad->removeMissile(arrNum);
}

void spaceShip::collision()
{
	for ( int i = 0; i < _thaad->getVBullet().size(); i++ )
	{
		for ( int j = 0; j < _em->getVMinion().size(); j++ )
		{
			RECT temp;
			if ( IntersectRect(&temp, &_thaad->getVBullet()[i].rc, &_em->getVMinion()[j]->getRect()) )
			{
				_thaad->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}