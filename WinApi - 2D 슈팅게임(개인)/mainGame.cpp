#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()			//초기화 함수
{
	gameNode::init(true);
	
	imageSet();
		
	_user = new User;
	_user->init();

	_em = new enemyManager;
	_em->init();
	_em->setMinion();
	

	_user->setEmMemoryAddressLink(_em);
	_em->setUsermemoryAddressLink(_user);

	_slt = new saveLoadTest;

	_loopX = _loopY = 0;

	

	return S_OK;
}

void mainGame::release()			//메모리 해제 함수
{
	gameNode::release();


}

void mainGame::update()				
{
	gameNode::update();

	_loopY -= 5;
	_user->update();
	_em->update();
	//_slt->update();

	collision();
	 collisionBird();
	 collisionBomb();
	 collisonCoin();
}

void mainGame::render()		
{
	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	

	IMAGEMANAGER->findImage("배경")->render(getMemDC(), 0, 0 );

	IMAGEMANAGER->findImage("구름")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopX, _loopY);
	

	_user->render();
	_em->render();

	
	this->getBackBuffer()->render(getHDC(), 0, 0);

}
