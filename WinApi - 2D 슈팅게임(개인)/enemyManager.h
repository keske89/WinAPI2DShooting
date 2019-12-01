#pragma once
#include "gameNode.h"
#include "Bullets.h"
#include "progressBar.h"
#include "boss.h"
#include "Minion1.h"
#include "Minion2.h"
#include <vector>


class User;

class enemyManager :public gameNode

{
private :
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

	vEnemy _vMinion;
	viEnemy _viMinion;
	Bullets* _bullet;
	Bullets* _bullet2;
	Bullets* _bullet3;
	Bullets* _bullet4;
	Bullets* _bullet5;
	User* _user;

	int stageNum;
	int moveCountBoss;
	int moveCountMinion;
	int wave;


	


public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMinion();

	void minionBulletFire(void);
	void removeMinion(int arrNum);
	void removeBullet(int arrNum);
	void collison();
	void setUsermemoryAddressLink(User* user) { _user = user; }
	void UserState();
	int getStageNum() { return stageNum; }
	void hitDamage(int arrNum, float damage);
	vector<enemy*>& getVMinion() { return _vMinion; }
	vector<enemy*>::iterator getVIMinion() { return _viMinion; }
	Bullets* getBullet() { return _bullet; }
	
};

