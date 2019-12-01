#pragma once
#include "gameNode.h"
#include "Bullets.h"
#include "progressBar.h"


class enemyManager;

enum tagCharDistance
{
	CHARGREEN,
	CHARYELLOW,
	CHARRED,
	END
};
class User : public gameNode
{
private:
	//User* _user;
	image* _userFrontImage;
	image* _userBackImage;
	Bullets* _bullets;
	bulletCard* _bulletCard;
	bulletBomb* _bulletBomb;
	bulletBird* _bulletBird;
	bulletEffect* _bulletEffect;
	bulletDead* _bulletDead;
	bulletCoin* _bulletCoin;
	RECT _rc;
	float x;
	float y;
	int _bombCount;
	int _lifeCount;
	int _score;
	int _level;
	int _alphaValue;
	int _charCondition;
	bool _birdFire;
	float _speed;
	float _currentHP, _maxHP;
	int _fireCount;
	bool _fireAble;
	enemyManager* _em;

	//progressbar* _hpBar;
	


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void removeMissile(int arrNum);

	void collison();

	void hitDamage(float damage);

	int getUserLevel() { return _level; }
	image* getUserImage() { return _userFrontImage; }  // 유저 이미지 접근자
	float getUserX() { return x; }
	float getUserY() { return y; }
	bulletCard* getBulletCard() { return _bulletCard; }
	bulletBird* getBulletBird() { return _bulletBird; }
	bulletBomb* getBulletBomb() { return _bulletBomb; }
	bulletEffect* getBulletEffect() { return _bulletEffect; }
	bulletDead* getBulletDead() { return _bulletDead; }
	bulletCoin* getBulletCoin() { return _bulletCoin; }
	void setEmMemoryAddressLink(enemyManager* em) { _em = em; }
	void setUserCon (int userCon) {_charCondition = userCon;}
	void setUserScore(int score) { _score += score; }
	int getUserScore() { return _score; }
	RECT getUserRect() { return _rc; }
	int getUserLife() { return _lifeCount; }
	void setUserLife(int Life) { _lifeCount -= Life; }
	User();
	~User();
};

