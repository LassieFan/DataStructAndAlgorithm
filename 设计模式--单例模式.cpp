#include <iostream>
using namespace std;

//懒汉模式，延迟加载，需要用到实例对象的时候才去实例化
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


//饿汉模式，一开始就创建了实例对象，每次用到直接返回，不存在线程安全问题
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


//双重检查版本，保证了线程安全和效率(懒汉模式)
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (instance == NULL)
		{
			pthread_mutex_lock(&mutex);
			if (instance == NULL)
				instance = new Singleton();   //静态可以调用构造，构造调用不依赖对象，析构不可以
			pthread_mutex_unlock(&mutex);
		}
		return instance;
	}
private:
	Singleton(){}
	static Singleton* instance;
};


