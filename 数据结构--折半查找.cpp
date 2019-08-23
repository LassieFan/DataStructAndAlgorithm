#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//折半查找必须要有序的数据才适用


int HalfFind1(vector<int> vec, int key)
{
	int len = vec.size();
	int low = 0;
	int high = len - 1;
	while (low <= high)
	{
		int mid = low + 1 / 2 * (high-low);
		if (vec[mid] == key)
			return mid;
		else if (vec[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

//与Find1不同的是替换了插值公式，但是这个插值公式适用于数据分布均匀一点的，若数据极端不均匀，插值查找并不是很好
int HalfFind2(vector<int> vec, int key)
{
	int len = vec.size();
	int low = 0;
	int high = len - 1;
	while (low <= high)
	{
		int tmp = (key - vec[low]) / (vec[high] - vec[low]);    //插值公式，将1/2替换，减少查找次数
		int mid = low + tmp * (high - low);
		if (vec[mid] == key)
			return mid;
		else if (vec[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

//递归写法
int HalfFind3(vector<int> vec, int low,int high, int key)
{
	int len = vec.size();
	if (low <= high)
	{
		int mid = (low + high) >> 1;
		if (vec[mid] == key)
			return mid;
		else if (vec[mid] > key)
			return HalfFind3(vec, low, mid - 1, key);
		else
			return HalfFind3(vec, mid+1, high, key);
	}
	return -1;
}


int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i*2+5);
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << HalfFind1(vec,11) << endl;
	cout << HalfFind2(vec,11) << endl;
	cout << HalfFind3(vec, 0,9,11) << endl;
}