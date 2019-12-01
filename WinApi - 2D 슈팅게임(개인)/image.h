#pragma once
//======================================
// ## 2017. 10. 25 ## - image Class - ##
//======================================

class image
{
public:
	//�̹��� �ҷ����� ����
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//���ҽ��κ���
		LOAD_FILE,			//�̹��� ���Ϸκ���
		LOAD_EMPTY,			//�� ��Ʈ�� ����
		LOAD_END			
	};

	typedef struct tagImageInfo
	{
		DWORD resID;			//���ҽ� �ҷ��ö� ���Ǵ� �������� �Ⱦ����� �Ƹ� �� _��
		HDC hMemDC;				//�޸� DC
		HBITMAP hBit;			//��Ʈ��
		HBITMAP hOBit;			//�õ� ��Ʈ��
		float x;
		float y;
		int width;				//���� ũ�� (�̹���)
		int height;				//���� ũ�� (�̹���)
		int currentFrameX;		//���� ������ ��ȣX
		int currentFrameY;		//���� ������ ��ȣY
		int maxFrameX;			//�ִ� ������ ��ȣ
		int maxFrameY;
		int frameWidth;			//�̹��� �� ��� ũ��
		int frameHeight;
		BYTE loadType;			//�̹��� ũ��ʹ� ����

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;		//�̹��� ���� ���� ����ü
	CHAR*			_fileName;		//���� �̸�
	BOOL			_trans;			//Ʈ�����÷� ó�� ��/��
	COLORREF		_transColor;	//� �÷��� ������

	BLENDFUNCTION	_blendFunc;		//���ĺ��带 ����ϱ����� ����ü
	LPIMAGE_INFO	_blendImage;	//���ĺ��带 ���̱����� �̹��� ����

public:
	image();
	~image();

	//�� ��Ʈ�� �̹����� ����Ҷ�
	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans, COLORREF transColor);

	HRESULT init(const char* fileName, int width, int height,
		int frameX, int frameY, BOOL trans, COLORREF transColor);

	void release(void);

	//Ʈ���� �÷� ���� �Լ�
	void setTransColor(BOOL trans, COLORREF transColor);


	void render(HDC hdc);
	//        �Ѹ� DC����  X��ǥ(LEFT), Y��ǥ(TOP)
	void render(HDC hdc, int destX, int destY);
	//        �Ѹ� DC����, �ѷ��� X,Y��ǥ        ������ X, Y(Left, Top) ������ ����, ���� ũ��  
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//   �����ӷ���   �Ѹ�DC����  ��ǥ X   ��ǥ Y (left Top)
	void frameRender(HDC hdc, int destX, int destY);
	//   ������ ����  �Ѹ�DC����  ��ǥ X    ��ǥ Y (left, top) ������ ��ȣ X  �����ӹ�ȣ Y
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);


	void alphaFrameRender(HDC hdc, int destX, int destY , BYTE alpha);
	void alphaFrameRender(HDC hdc, int destX, int destY,int currentFrameX, int currentFrameY, BYTE alpha);

	void loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	//====================================================
	// �̹��� ���� ����ϰ� ���ٲ�
	//====================================================

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX(void) { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY(void) { return _imageInfo->y; }

	//��� ��ǥ�� ����
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) :
				_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (_imageInfo->maxFrameX < frameX) _imageInfo->maxFrameX = frameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (_imageInfo->maxFrameY < frameY) _imageInfo->maxFrameY = frameY;
	}

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

};


