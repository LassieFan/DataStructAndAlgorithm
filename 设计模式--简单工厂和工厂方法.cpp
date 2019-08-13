#include <iostream>
using namespace std;

//�����Ʒ��
class Product
{
public:
	Product(){}
	virtual ~Product(){}
	virtual void show() = 0;
};

//��ƷA
class ConcreteProductA :public Product
{
public:
	ConcreteProductA() {}
	~ConcreteProductA(){}
	void show()
	{
		cout << "ConcreteProductA" << endl;
	}
};

//��ƷB
class ConcreteProductB :public Product
{
public:
	ConcreteProductB() {}
	~ConcreteProductB() {}
	void show()
	{
		cout << "ConcreteProductB" << endl;
	}
};

//�򵥹���ģʽ
class SimpleFactory
{
public:
	Product* Create(char name)
	{
		switch (name)
		{
		case 'A':
			return new ConcreteProductA;
			break;
		case 'B':
			return new ConcreteProductB;
			break;
		default:
			break;
		}
	}
};


//��������ģʽ�Ĺ�������
class Factory
{
public:
	virtual Product * create() = 0;
};

//������ƷA�ľ��幤��
class ConcreateFactoryA :public Factory
{
public:
	ConcreateFactoryA()
	{
		cout << "ConcreateFactoryA...." << endl;
	}
	Product* create()
	{
		return new ConcreteProductA();
	}
};

//������ƷB�ľ��幤��
class ConcreateFactoryB :public Factory
{
public:
	ConcreateFactoryB()
	{
		cout << "ConcreateFactoryB...." << endl;
	}
	Product* create()
	{
		return new ConcreteProductB();
	}
};


int main()
{
	SimpleFactory * factory = new SimpleFactory();
	factory->Create('A')->show();
	factory->Create('B')->show();
	cout << "---------------------------" << endl;
	Factory* facA = new ConcreateFactoryA();
	Factory* facB = new ConcreateFactoryB();
	facA->create()->show();
	facB->create()->show();
	return 0;
}