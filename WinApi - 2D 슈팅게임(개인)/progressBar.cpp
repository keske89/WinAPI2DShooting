#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(const char* frontBarImageName, const char* BackBarImageName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->findImage(frontBarImageName);


	_progressBarBottom = IMAGEMANAGER->findImage(BackBarImageName);

	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
	_rcProgress = RectMake(_x, _y,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
}

void progressBar::render()
{
	_progressBarTop->render(getMemDC(), _rcProgress.left, _y, 0, 0, _width, _progressBarTop->getHeight());
	_progressBarBottom->render(getMemDC(), _rcProgress.left, _y, 0, 0, _progressBarBottom->getWidth(), _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	//퍼센테이지 산출한다
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}

