/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 01 Oct 2018 09:47:24 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

void QuickSort(int *arr,int low,int high)
{
	assert(arr);
	if(low>=high)
		throw "error";
	int i=low;   //赋值给i只是为了用于操作，不想打字。。。
	int j=high;
	stack<int> s;
	s.push(i);   //将序列最左边下标入栈
	s.push(j);  //将最右边下标入栈
	while(!s.empty())  //当栈不空证明还有序列需要处理
	{
		j=s.top();   //因为先入左边，所以先出右边
		high=j;      //将当前的左右端记录，下边要进行判断
		s.pop();
		i=s.top();
		low=i;
		s.pop();
		int tmp=arr[i];
		while(i<j)
		{
			
			while(i<j&&arr[j]>=tmp)
				j--;
			if(i<j)
			{
				arr[i]=arr[j];
				i++;
			}
			while(i<j&&arr[i]<=tmp)
				i++;
			if(i<j)
			{
				arr[j]=arr[i];
				j--;
			}
		}
		arr[i]=tmp;   //此时的i和j都是分段的下标
		if(high-j>1)  //判断分割点右边是否还有数据需要入栈进行排序
		{
			s.push(j+1);  //入分割点右边序列的最左边的下标
			s.push(high); //入分割点右边序列的最右边的下标
		}
		if(i-low>1)
		{
			s.push(low);
			s.push(i-1);
		}
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
	int arr[]={47,47,55,1,47,47};
	int len=sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,len-1);
	Show(arr,len);
}
