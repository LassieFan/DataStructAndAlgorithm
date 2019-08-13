#include <iostream>
using namespace std;

//代理类和被代理类的公共基类,为了保证客户端使用的透明性用代理代替实体，要有相同的接口
class Subject
{
public:
	virtual ~Subject() {}
	virtual void Request() = 0;
protected:
	Subject(){}
};

//具体被代理类
class ConcreteSubject :public Subject
{
public:
	ConcreteSubject(){}
	~ConcreteSubject() {}
	void Request()
	{
		cout << "ConcreteSubject request" << endl;
	}
};

//代理类
class Proxy:public Subject
{
public:
	Proxy(){}
	Proxy(Subject * sub)
	{
		_sub = sub;
	}
	~Proxy()
	{
		delete _sub;
	}
	void Request()
	{
		cout << "Proxy request" << endl;
		_sub->Request();
	}
protected:
	Subject * _sub;     //使得代理可以访问被代理类对象
};


int main()
{
	Subject* sub = new ConcreteSubject();
	Proxy* p = new Proxy(sub);
	p->Request();
	return 0;
}