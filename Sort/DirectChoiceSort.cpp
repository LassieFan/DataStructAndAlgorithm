/*************************************************************************
    > File Name: main.cpp
    > Created Time: Wed 26 Sep 2018 06:50:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void SelectionSort(int *arr,int len)
{
	int min;      //记录每趟中元素最小的下标
	for(int i=0;i<len-1;i++)   //控制循环的趟数
	{
		min=i;
		for(int j=i+1;j<len;j++)    //控制每次循环中寻找最小的数
		{
			if(arr[min]>arr[j])
				min=j;
		}
		if(min!=i)
			swap(arr[min],arr[i]);
	}
}
void Show(int *arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int arr[]={3,15,7,9,4,2,6,10,1};
	int len=sizeof(arr)/sizeof(arr[0]);
	SelectionSort(arr,len);
	Show(arr,len);
	return 0;
}
