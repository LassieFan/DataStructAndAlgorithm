#include <iostream>
using namespace std;

class Component
{
public:
	Component() {}
	virtual ~Component() {}
	virtual void operation() = 0;
};

//具体被装饰类，可以多个
class ConcreteComponent : public Component
{
public:
	ConcreteComponent() {}
	~ConcreteComponent(){}
	void operation()
	{
		cout << "ConcreteComponent operation" << endl;
	}
};

//装饰类基类，如果只有一个具体装饰类，可以不要装饰类基类
class Decorator :public Component
{
public:
	Decorator(Component* conn) {
		this->_conn = conn;
	}
	virtual ~Decorator() {
		delete _conn;
	}
	virtual void operation()      //调用多态装饰被装饰类对象，此方法在子类ConcreteDecorator中被覆盖
	{
		_conn->operation();
	}
protected:
	Component* _conn;        //Dectorator不能直接放一个ConcreteComponent的指针，如果是那么每一个具体的被修饰类都要一个具体的装饰类来服务
};

//第一个装饰类
class ConcreteDecorator1 :public Decorator
{
public:
	ConcreteDecorator1(Component * conn):Decorator(conn){}
	~ConcreteDecorator1() {}
	void operation() {
		_conn->operation();    //调用被装饰类的operation
		this->AddBehavior();   //给被装饰类加功能
	}
	void AddBehavior() {
		cout << "ConcreteDecorator1::AddBehavior" << endl;
	}
};

//第二个装饰类
class ConcreteDecorator2 :public Decorator
{
public:
	ConcreteDecorator2(Component * conn) :Decorator(conn) {}
	~ConcreteDecorator2() {}
	void operation() {
		_conn->operation();    //调用被装饰类的operation
		this->AddBehavior();   //给被装饰类加功能
	}
	void AddBehavior() {
		cout << "ConcreteDecorator2::AddBehavior" << endl;
	}
};

int main()
{
	Component* com = new ConcreteComponent();
	Decorator* dec1 = new ConcreteDecorator1(com);       
	Decorator* dec2 = new ConcreteDecorator2(dec1);
	dec2->operation();
	return 0;
}