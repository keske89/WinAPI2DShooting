#include "stdafx.h"
#include "mainGame.h"

void mainGame::imageSet()
{
	IMAGEMANAGER->addImage("플레이어", "image//frontChar.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("초록카드", "image//bulletCardG.bmp", 880, 40,22,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("노랑카드", "image//bulletCardY.bmp", 880, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("빨강카드", "image//bulletCardR.bmp", 880, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("초록배경", "image//backCharG.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("노랑배경", "image//backCharY.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨강배경", "image//backCharR.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("필살기", "image//bulletbomb.bmp", 6474, 498, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("초록새", "image//bulletBirdG.bmp", 90,60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("노랑새", "image//bulletBirdY.bmp", 90, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨강새", "image//bulletBirdR.bmp", 90, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배경","image//backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("구름", "image//backGroundCloud.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("보스", "image//boss.bmp", 3000, 4300, 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("탄환1", "image//bulletball1.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("탄환2", "image//bulletball2.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("탄환3", "image//bulletball3.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("탄환4", "image//bulletball4.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("탄환5", "image//bulletball5.bmp", 900, 60, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("동전", "image//coin.bmp", 968, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("충돌", "image//hitEffect.bmp", 300, 50, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("박쥐", "image//Minion1.bmp", 640, 40, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("유령", "image//Minion2.bmp", 840, 60, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("호박", "image//Minion2.bmp", 1040, 64, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("죽음", "image//deadEffect.bmp", 900, 100, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피통뒤", "image//HpBarEmpty.bmp", 600, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("피통앞", "image//HpBarFull.bmp", 600, 30, true, RGB(255, 0, 255));

}