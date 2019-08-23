#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//˳��������õ�ʱ�临�Ӷ���O(1)����һ�����ҵ�,������ΪO(n)�����һ�����ҵ�


int Find1(vector<int> vec, int key)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		if (vec[i] == key)
			return i;
	}
	return -1;      //-1��û���ҵ�
}


//�Ľ��棬�����ڱ�λ�������ж�i��len�Ĵ�С
int Find2(vector<int> vec, int key)
{
	int len = vec.size();
	vec.push_back(key);    //�ڱ�λ���Է���ͷ���߷���β
	int i = 0;
	while (vec[i] != key)
		i++;
	return i;     //δ�ҵ�����vec����

}

int main()
{
	vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 100);
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << Find1(vec, 20) << endl;     //����20
	cout << Find2(vec, 20) << endl;
}