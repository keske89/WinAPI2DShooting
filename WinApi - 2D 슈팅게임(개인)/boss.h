#pragma once
#include "enemy.h"
#include "progressBar.h"

class boss : public enemy

{	private:

	//int _count;
	//int _fireCount;
	//int _rndFireCount;
	//int _dirCount;
	//float _x;
	//float _y;
	//float _fireX;
	//float _fireY;
	//float _angle;
	//float _speed;


	int _fireCountBoss;
	

	progressBar* _progressBar;
	

public:
	boss();
	~boss();
	
	
	HRESULT init(const char* imagename, float Ex, float Ey, float anlge, float speed, int pattern, int movePhase, float currentHP, float maxHP);
	virtual void update();

	virtual void render();

	virtual void fire();
	virtual void move();

};

