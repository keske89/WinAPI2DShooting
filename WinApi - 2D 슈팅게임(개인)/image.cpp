#include "stdafx.h"
#include "image.h"

//�����Ϸ� ���ñ�
#pragma comment(lib, "msimg32.lib")

//��� �̴ϼȶ����� == const �Ӽ��� �ʱ�ȭ ���ֱ� ���� ��ȵ� ���(������)
//�ʹ��� ���ؼ� �ٸ� �ǹ̷� ���� Ȱ�� ��
image::image()
	: _imageInfo(NULL),
	_fileName(NULL),
	_trans(false),
	_transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

//�� ��Ʈ�� �̹����� ����Ҷ�
HRESULT image::init(int width, int height)
{
	//�̹��� ������ ���� �����ִٸ�? -> �������Ѷ�
	if (_imageInfo != NULL) release();

	//DC������ �����´�
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;											//�̹����� �����Ҵ�
	_imageInfo->loadType = LOAD_EMPTY;										//Ÿ���� �� ��Ʈ�� Ÿ��
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);							//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);	//�� ��Ʈ�� �̹��� ����
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP) CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP) SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �ȵǾ��ٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�����ߴٰ� �˷���
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor)
{
	//�̹��� ������ ���� �����ִٸ�? -> �������Ѷ�
	if (_imageInfo != NULL) release();

	//DC������ �����´�
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;											//�̹����� �����Ҵ�
	_imageInfo->loadType = LOAD_FILE;										//Ÿ���� �� ��Ʈ�� Ÿ��
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);							//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP) CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP) SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �ȵǾ��ٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�����ߴٰ� �˷���
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, float x, float y, int width, int height,
	BOOL trans, COLORREF transColor)
{
	//�̹��� ������ ���� �����ִٸ�? -> �������Ѷ�
	if (_imageInfo != NULL) release();

	//DC������ �����´�
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;											//�̹����� �����Ҵ�
	_imageInfo->loadType = LOAD_FILE;										//Ÿ���� �� ��Ʈ�� Ÿ��
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);							//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP) CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP) SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �ȵǾ��ٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�����ߴٰ� �˷���
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, float x, float y, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//�̹��� ������ ���� �����ִٸ�? -> �������Ѷ�
	if (_imageInfo != NULL) release();

	//DC������ �����´�
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;											//�̹����� �����Ҵ�
	_imageInfo->loadType = LOAD_FILE;										//Ÿ���� �� ��Ʈ�� Ÿ��
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);							//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;


	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP) CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP) SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �ȵǾ��ٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�����ߴٰ� �˷���
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//�̹��� ������ ���� �����ִٸ�? -> �������Ѷ�
	if (_imageInfo != NULL) release();

	//DC������ �����´�
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;											//�̹����� �����Ҵ�
	_imageInfo->loadType = LOAD_FILE;										//Ÿ���� �� ��Ʈ�� Ÿ��
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);							//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;


	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//���ĺ��� ����
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP) CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP) SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//��Ʈ���� ������ �ȵǾ��ٸ�
	if (_imageInfo->hBit == NULL)
	{
		//������Ű��
		release();
		//�����ߴٰ� �˷���
		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);


	return S_OK;
}

void image::release(void)
{
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);	//�õ� ��Ʈ�ʻ���
		DeleteObject(_imageInfo->hBit);							//��Ʈ�� ����
		DeleteDC(_imageInfo->hMemDC);							//DC���� ����

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

//Ʈ���� �÷� ���� �Լ�
void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

void image::render(HDC hdc)
{
	//Ư�� �÷��� ����ߵǴ���?
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ������ DC
			_imageInfo->x,			//����� ��ǥ X
			_imageInfo->y,			//����� ��ǥ Y
			_imageInfo->width,		//����� ����ũ��
			_imageInfo->height,		//����� ����ũ��
			_imageInfo->hMemDC,		//������ DC
			0, 0,					//�����ؿ� ��ǥ
			_imageInfo->width,		//�����ؿ� ũ��
			_imageInfo->height,
			_transColor);			//������ �÷���
	}
	else
	{
		//����ۿ� ������ HDC�������� ��Ӻ��� ���ش�
		BitBlt(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			SRCCOPY);
	}
}

//        �Ѹ� DC����  X��ǥ(LEFT), Y��ǥ(TOP)
void image::render(HDC hdc, int destX, int destY)
{
	//Ư�� �÷��� ����ߵǴ���?
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ������ DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			_imageInfo->width,		//����� ����ũ��
			_imageInfo->height,		//����� ����ũ��
			_imageInfo->hMemDC,		//������ DC
			0, 0,					//�����ؿ� ��ǥ
			_imageInfo->width,		//�����ؿ� ũ��
			_imageInfo->height,
			_transColor);			//������ �÷���
	}
	else
	{
		//����ۿ� ������ HDC�������� ��Ӻ��� ���ش�
		BitBlt(hdc, destX, destY,
			_imageInfo->width, 
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0, 
			SRCCOPY);
	}

}

//				�Ѹ� DC����, �ѷ��� X,Y��ǥ        ������ X, Y(Left, Top) ������ ����, ���� ũ��  
void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	//Ư�� �÷��� ����ߵǴ���?
	if (_trans)
	{
		GdiTransparentBlt(
			hdc,					//����� ������ DC
			destX,					//����� ��ǥ X
			destY,					//����� ��ǥ Y
			sourWidth,				//����� ����ũ��
			sourHeight,				//����� ����ũ��
			_imageInfo->hMemDC,		//������ DC
			sourX, sourY,			//�����ؿ� ��ǥ
			sourWidth,				//�����ؿ� ũ��
			sourHeight,
			_transColor);			//������ �÷���
	}
	else
	{
		//����ۿ� ������ HDC�������� ��Ӻ��� ���ش�
		BitBlt(hdc, destX, destY,
			sourWidth,
			sourHeight,
			_imageInfo->hMemDC,
			sourX, sourY,
			SRCCOPY);
	}
}

//   �����ӷ���   �Ѹ�DC����  ��ǥ X   ��ǥ Y (left Top)
void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}

}

//   ������ ����  �Ѹ�DC����  ��ǥ X    ��ǥ Y (left, top) ������ ��ȣ X  �����ӹ�ȣ Y
void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//���ĸ� ������ ��ġ�� �޴´�
	_blendFunc.SourceConstantAlpha = alpha;

	if ( _trans )
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, _imageInfo->x, _imageInfo->y, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width,
			_imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, _imageInfo->x, _imageInfo->y, _imageInfo->width,
			_imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}

}

void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	//���ĸ� ������ ��ġ�� �޴´�
	_blendFunc.SourceConstantAlpha = alpha;

	if ( _trans )
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width,
			_imageInfo->height, _blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width,
			_imageInfo->height, _imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	//(!ȣȣ��ȫ) ���� ȣȣ��ȫ���� �� ��.
	//���ĸ� ������ ��ġ�� �޴´�
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0,0, sourWidth,sourHeight, _imageInfo->hMemDC, sourX,sourY, sourWidth, sourHeight, _transColor);

		AlphaBlend(hdc, destX, destY, sourWidth,sourHeight, _blendImage->hMemDC, 0,0,sourWidth,sourHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, sourWidth,sourHeight, _imageInfo->hMemDC, sourX,sourY,sourWidth,sourHeight, _blendFunc);
	}
}


void image::alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC,
			0,0,
			_imageInfo->frameWidth,_imageInfo->frameHeight,
			hdc,
			destX, destY,
			SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC,
			0,0,
			_imageInfo->frameWidth,_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_transColor);

		AlphaBlend(hdc,
			destX,destY,
			_imageInfo->frameWidth,_imageInfo->frameHeight,
			_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc, 
			destX, destY, 
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY*_imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, 
			_blendFunc);
	}
}


void image::alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;
	_blendFunc.SourceConstantAlpha = alpha;



	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, 
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC,
			0,
			0,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);

		AlphaBlend(hdc,
			destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendImage->hMemDC,
			0,0,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendFunc);
	}
	else
	{
		AlphaBlend(hdc,
			destX, destY,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY*_imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendFunc);
	}

}


void image::loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	//���� ������ ���� ������ ����
	if (offSetX < 0) offSetX = _imageInfo->width + (offSetX % _imageInfo->width);
	if (offSetY < 0) offSetY = _imageInfo->height + (offSetY % _imageInfo->height);

	RECT rcSour;
	int sourWidth;
	int sourHeight;

	RECT rcDest;

	//ȭ�鿡 �׷����� ������ ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//Y Axis
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + offSetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		//�׷��ִ� ���������� �̹����� ������
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + offSetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}

	}
}