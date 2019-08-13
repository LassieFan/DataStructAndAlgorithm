#include <iostream>
using namespace std;

//抽象产品类
class Product
{
public:
	Product(){}
	virtual ~Product(){}
	virtual void show() = 0;
};

//产品A
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

//产品B
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

//简单工厂模式
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


//工厂方法模式的工厂基类
class Factory
{
public:
	virtual Product * create() = 0;
};

//产生产品A的具体工厂
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

//产生产品B的具体工厂
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