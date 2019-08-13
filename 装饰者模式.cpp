#include <iostream>
using namespace std;

class Component
{
public:
	Component() {}
	virtual ~Component() {}
	virtual void operation() = 0;
};

//���屻װ���࣬���Զ��
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

//װ������࣬���ֻ��һ������װ���࣬���Բ�Ҫװ�������
class Decorator :public Component
{
public:
	Decorator(Component* conn) {
		this->_conn = conn;
	}
	virtual ~Decorator() {
		delete _conn;
	}
	virtual void operation()      //���ö�̬װ�α�װ������󣬴˷���������ConcreteDecorator�б�����
	{
		_conn->operation();
	}
protected:
	Component* _conn;        //Dectorator����ֱ�ӷ�һ��ConcreteComponent��ָ�룬�������ôÿһ������ı������඼Ҫһ�������װ����������
};

//��һ��װ����
class ConcreteDecorator1 :public Decorator
{
public:
	ConcreteDecorator1(Component * conn):Decorator(conn){}
	~ConcreteDecorator1() {}
	void operation() {
		_conn->operation();    //���ñ�װ�����operation
		this->AddBehavior();   //����װ����ӹ���
	}
	void AddBehavior() {
		cout << "ConcreteDecorator1::AddBehavior" << endl;
	}
};

//�ڶ���װ����
class ConcreteDecorator2 :public Decorator
{
public:
	ConcreteDecorator2(Component * conn) :Decorator(conn) {}
	~ConcreteDecorator2() {}
	void operation() {
		_conn->operation();    //���ñ�װ�����operation
		this->AddBehavior();   //����װ����ӹ���
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