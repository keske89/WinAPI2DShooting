#include "stdafx.h"
#include "mainGame.h"

void mainGame::imageSet()
{
	IMAGEMANAGER->addImage("�÷��̾�", "image//frontChar.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ʷ�ī��", "image//bulletCardG.bmp", 880, 40,22,1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ī��", "image//bulletCardY.bmp", 880, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����ī��", "image//bulletCardR.bmp", 880, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ʷϹ��", "image//backCharG.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "image//backCharY.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "image//backCharR.bmp", 40, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ʻ��", "image//bulletbomb.bmp", 6474, 498, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ʷϻ�", "image//bulletBirdG.bmp", 90,60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����", "image//bulletBirdY.bmp", 90, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "image//bulletBirdR.bmp", 90, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���","image//backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "image//backGroundCloud.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image//boss.bmp", 3000, 4300, 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("źȯ1", "image//bulletball1.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("źȯ2", "image//bulletball2.bmp", 20, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("źȯ3", "image//bulletball3.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("źȯ4", "image//bulletball4.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("źȯ5", "image//bulletball5.bmp", 900, 60, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image//coin.bmp", 968, 40, 22, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�浹", "image//hitEffect.bmp", 300, 50, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image//Minion1.bmp", 640, 40, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image//Minion2.bmp", 840, 60, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ȣ��", "image//Minion2.bmp", 1040, 64, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "image//deadEffect.bmp", 900, 100, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����", "image//HpBarEmpty.bmp", 600, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����", "image//HpBarFull.bmp", 600, 30, true, RGB(255, 0, 255));

}