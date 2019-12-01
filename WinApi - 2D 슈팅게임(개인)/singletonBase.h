#pragma once

template <typename T>
class singletonBase
{
protected:
	static T* singleton;

	singletonBase(){};
	~singletonBase(){};

public:

	static T* getSingleton(void);

	void releaseSingleton(void);

};

//�̱��� �ʱ�ȭ
template <typename T>
T* singletonBase<T>::singleton = 0;

//�̱��� �ҷ����� �Լ�
template <typename T>
T* singletonBase<T>::getSingleton()
{
	//�̱����� ������ �̱����� �����ض�
	if (!singleton) singleton = new T;

	return singleton;
}

//�̱��� ���� �Լ�

template <typename T>
void singletonBase<T>::releaseSingleton(void)
{
	if (singleton)
	{
		delete singleton;

		singleton = 0;
	}
}
