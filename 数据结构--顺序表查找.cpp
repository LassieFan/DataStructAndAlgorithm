#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//顺序表查找最好的时间复杂度是O(1)，第一个就找到,最坏的情况为O(n)，最后一个才找到


int Find1(vector<int> vec, int key)
{
	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		if (vec[i] == key)
			return i;
	}
	return -1;      //-1是没有找到
}


//改进版，设置哨兵位，不用判断i和len的大小
int Find2(vector<int> vec, int key)
{
	int len = vec.size();
	vec.push_back(key);    //哨兵位可以放在头或者放在尾
	int i = 0;
	while (vec[i] != key)
		i++;
	return i;     //未找到返回vec长度

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
	cout << Find1(vec, 20) << endl;     //查找20
	cout << Find2(vec, 20) << endl;
}