#pragma once
#include "gameNode.h"
#include <vector>


class User;

struct tagBullet
{
	image* bulletImage; 
	RECT _rc;
	float _x;
	float _y;
	float _damage;
	float _angle;
	float _radius;
	float _speed;
	float _fireX;
	float _fireY;
	float _effectX;
	float _effectY;
	bool _isFire;
	bool _isfree;
	int _count;
	int _bulletCount;
	int _fireCount;
	int _cardCount;
	int _effectCount;
	int _deadCount;
	int _coinCount;
};

///////////////////////////////// 몬스터 탄환/////////////////////////////////////////////////
class Bullets : public gameNode  // 몬스터 기본사용 탄환
{

private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	const char* _imageName;
	float _range;
	int _bulletMax;
	bool _isHitAble;
	


public:
	HRESULT init(const char* imageName, int bulletMax, float range, bool isHitAble);
	void release(void);
	void update(void);
	void render(void);
	void fire(float x, float y, float angle, float speed);
	void fire2(float x, float y, int bulletNum, float speed);
	void move(void);
	void removeBullet(int arrNum);

	// 접근자를 만들어줘야겠다아
	vector<tagBullet> &getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator &getVIBullet() { return _viBullet; }
	
	Bullets();
	~Bullets();
};
///////////////////////////////// 몬스터 끝/////////////////////////////////////////////////

///////////////////////////////// 유저 탄환 시작 /////////////////////////////////////////////////
class bulletCard : public gameNode  // 유저 기본탄환
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	
	float _range;
	int _bulletMax;
	

public:
	bulletCard();
	~bulletCard();

	HRESULT init(int bulletMax, int range);
	void release();
	void update();
	void render();	
	void fire(float x, float y,float angle, int CharCondition);
	void move();
	void removeBulletCard(int arrNum);

	//접근자를 만들자
	
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


class bulletBird : public gameNode // 유저 호밍기
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	
	float _range;
	int _bulletMax;
	int _birdCount;

public:
	bulletBird();
	~bulletBird();

	HRESULT init();
	void release();
	void update(float x, float y, bool birdf);
	void render();
	void fire(float x, float y, int angle, int level, int CharCondition);
	void move(float x, float y, bool birdf);
	

	//접근자를 만들자

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};

class bulletBomb : public gameNode // 유저 필살기
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	
	float _range;
	int _bulletMax;

public:
	bulletBomb();
	~bulletBomb();

	HRESULT init(int bulletMax);
	void release();
	void update();
	void render();
	void fire(float x, float y, int level);
	void move();


	//접근자를 만들자

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


///////////////////////////////// 유저 탄환 끝 /////////////////////////////////////////////////


///////////////////////////////// 탄환 충돌 이펙트 /////////////////////////////////////////////
class bulletEffect : public gameNode // 유저 호밍기
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	bulletEffect* _bulletEffect;
	int _bulletMax;

public:
	bulletEffect();
	~bulletEffect();

	HRESULT init(int bulletMax);
	void release();
	void update();
	void render();
	void fire(float x, float y);
	void move();


	//접근자를 만들자

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletEffect* getBulletEffect() { return _bulletEffect; }
};


class bulletDead : public gameNode // 유저 호밍기
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	bulletDead* _bulletDead;
	User* _user;
	int _bulletMax;

public:
	bulletDead();
	~bulletDead();

	HRESULT init(int bulletMax);
	void release();
	void update();
	void render();
	void fire(float x, float y);
	void move();


	//접근자를 만들자

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletDead* getBulletDead() { return _bulletDead; }
	void setUsermemoryAddressLink(User* user) { _user = user; }
};

class bulletCoin : public gameNode // 유저 호밍기
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;
	bulletCoin* _bulletCoin;
	User* _user;
	int _bulletMax;

public:
	bulletCoin();
	~bulletCoin();

	HRESULT init(int bulletMax);
	void release();
	void update(int userX, int userY);
	void render();
	void fire(float x, float y,float angle, float speed);
	virtual void move(int userX, int userY);
	void removeBulletCoin(int arrNum);


	//접근자를 만들자

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletCoin* getBulletCoin() { return _bulletCoin; }
	void setUsermemoryAddressLink(User* user) { _user = user; }
};
