#pragma once
#include "gameNode.h"
#include "User.h"
#include "enemyManager.h"
#include "saveLoadTest.h"

class mainGame : public gameNode
{
private:
	User* _user;
	enemyManager* _em;
	saveLoadTest* _slt;

	int _fadeIn, _fadeOut;
	int _loopX, _loopY;
	bool _start;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	
	void imageSet();
	void collision();
	void collisionBird();
	void collisionBomb();
	void collisonCoin();
	
	

	mainGame();
	~mainGame();
};

