#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//�۰���ұ���Ҫ��������ݲ�����


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

//��Find1��ͬ�����滻�˲�ֵ��ʽ�����������ֵ��ʽ���������ݷֲ�����һ��ģ������ݼ��˲����ȣ���ֵ���Ҳ����Ǻܺ�
int HalfFind2(vector<int> vec, int key)
{
	int len = vec.size();
	int low = 0;
	int high = len - 1;
	while (low <= high)
	{
		int tmp = (key - vec[low]) / (vec[high] - vec[low]);    //��ֵ��ʽ����1/2�滻�����ٲ��Ҵ���
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

//�ݹ�д��
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