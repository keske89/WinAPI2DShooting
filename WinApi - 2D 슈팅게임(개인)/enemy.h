#pragma once
#include "gameNode.h"

enum tagStageMinion
{
	MINION,
	MINION2,
	MINION3,
	BOSS,
	MINIONEND
};

class enemy :public gameNode
{
protected:
	image* _imageName;
	RECT _rc;
	

	int _currentFrameX;
	int _currentFrameY;

	int _count;
	int _fireCount;
	int _rndFireCount;
	int _dirCount;
	float _x;
	float _y;
	float _fireX;
	float _fireY;
	float _angle;
	float _speed;
	float _currentHP;
	float _maxHP;
	int _pattern;
	int _movePhase;

public:
	enemy();
	~enemy();

	HRESULT init();
	virtual HRESULT init(const char* imagename, float Ex, float Ey, float anlge, float speed, int pattern,int movePhase, float currentHP, float maxHP);
	

	void release();
	virtual void update();
	virtual void render();

	virtual void move();
	void draw();
	bool bulletCountFire();

	inline RECT getRect() { return _rc; }
	inline float getHP() { return _currentHP; }
	void setHP(float currentHP) { _currentHP = currentHP; }
	void setPattern(int pattern) { _pattern = pattern; }
	int getPattern() { return _pattern; }
	void setMovePhase(int movePhase) { _movePhase = movePhase; }
	int getMovePhase() { return _movePhase; }
	int getCenterX() { return _x; }
	int getCenterY() { return _y; }
	
};


