#include <iostream>
using namespace std;

//������ͱ�������Ĺ�������,Ϊ�˱�֤�ͻ���ʹ�õ�͸�����ô������ʵ�壬Ҫ����ͬ�Ľӿ�
class Subject
{
public:
	virtual ~Subject() {}
	virtual void Request() = 0;
protected:
	Subject(){}
};

//���屻������
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

//������
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
	Subject * _sub;     //ʹ�ô�����Է��ʱ����������
};


int main()
{
	Subject* sub = new ConcreteSubject();
	Proxy* p = new Proxy(sub);
	p->Request();
	return 0;
}