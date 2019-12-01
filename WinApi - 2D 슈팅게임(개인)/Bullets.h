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

///////////////////////////////// ���� źȯ/////////////////////////////////////////////////
class Bullets : public gameNode  // ���� �⺻��� źȯ
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

	// �����ڸ� �������߰ڴپ�
	vector<tagBullet> &getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator &getVIBullet() { return _viBullet; }
	
	Bullets();
	~Bullets();
};
///////////////////////////////// ���� ��/////////////////////////////////////////////////

///////////////////////////////// ���� źȯ ���� /////////////////////////////////////////////////
class bulletCard : public gameNode  // ���� �⺻źȯ
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

	//�����ڸ� ������
	
	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


class bulletBird : public gameNode // ���� ȣ�ֱ�
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
	

	//�����ڸ� ������

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};

class bulletBomb : public gameNode // ���� �ʻ��
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


	//�����ڸ� ������

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};


///////////////////////////////// ���� źȯ �� /////////////////////////////////////////////////


///////////////////////////////// źȯ �浹 ����Ʈ /////////////////////////////////////////////
class bulletEffect : public gameNode // ���� ȣ�ֱ�
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


	//�����ڸ� ������

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletEffect* getBulletEffect() { return _bulletEffect; }
};


class bulletDead : public gameNode // ���� ȣ�ֱ�
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


	//�����ڸ� ������

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletDead* getBulletDead() { return _bulletDead; }
	void setUsermemoryAddressLink(User* user) { _user = user; }
};

class bulletCoin : public gameNode // ���� ȣ�ֱ�
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


	//�����ڸ� ������

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
	bulletCoin* getBulletCoin() { return _bulletCoin; }
	void setUsermemoryAddressLink(User* user) { _user = user; }
};
