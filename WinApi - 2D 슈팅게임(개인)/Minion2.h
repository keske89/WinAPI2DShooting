#pragma once
#include "enemy.h"
class Minion2 : public enemy
{
public:
	Minion2();
	~Minion2();

	virtual void fire();
	virtual void move();
};

