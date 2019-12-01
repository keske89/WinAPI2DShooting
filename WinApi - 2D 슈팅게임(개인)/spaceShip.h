#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//상호참조를 위한 전방선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	THAAD* _thaad;

	enemyManager* _em;

	progressBar* _hpBar;

	float _currentHP, _maxHP;
	int _alphaValue;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void removeMissile(int arrNum);

	void collision();

	void hitDamage(float damage);

	image* getShipImage() { return _ship; }

	THAAD* getThaadMissile() { return _thaad; }

	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }

	spaceShip();
	~spaceShip();
};

