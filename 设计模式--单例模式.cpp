#include <iostream>
using namespace std;

//����ģʽ���ӳټ��أ���Ҫ�õ�ʵ�������ʱ���ȥʵ����
class LazySingleton
{
public:
	static LazySingleton* GetInstance()
	{
		if (lazy_instance == NULL)
			lazy_instance = new LazySingleton();
		return lazy_instance;
	}
private:
	LazySingleton() {}
	static LazySingleton * lazy_instance;
};


//����ģʽ��һ��ʼ�ʹ�����ʵ������ÿ���õ�ֱ�ӷ��أ��������̰߳�ȫ����
class HungrySingleton
{
public:
	static HungrySingleton* GetInstance()
	{
		return hungry_instance;
	}
private:
	HungrySingleton() {}
	static HungrySingleton * hungry_instance;
};
HungrySingleton * HungrySingleton::hungry_instance = new HungrySingleton();


//˫�ؼ��汾����֤���̰߳�ȫ��Ч��(����ģʽ)
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (instance == NULL)
		{
			pthread_mutex_lock(&mutex);
			if (instance == NULL)
				instance = new Singleton();   //��̬���Ե��ù��죬������ò�������������������
			pthread_mutex_unlock(&mutex);
		}
		return instance;
	}
private:
	Singleton(){}
	static Singleton* instance;
};


