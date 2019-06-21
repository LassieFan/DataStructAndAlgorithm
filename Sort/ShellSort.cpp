/*************************************************************************
    > File Name: main.cpp
    > Created Time: Mon 10 Sep 2018 06:49:37 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//希尔排序是对直接插入排序的优化，缩小增量排序
void ShellSort(int *arr,int len)
{
	for(int step=len/2;step>0;step/=2) //增量可以自己输入增量因子，但最后一个增量因子肯定是1，我这里用的是每次增量为之前增量的一半
	{
		for(int k=0;k<step;k++) //增量之前的都是独立的一组，循环的次数即增量
		{
			for(int i=k+step;i<len;i+=step) //实际上将直接插入排序的增量1改变而已，每次不是+1，而是加当前增量
			{
				if(arr[i]<arr[i-step]) //从这里往下的代码与直接插入没什么大的不同
				{
					int temp=arr[i];
					arr[i]=arr[i-step];
					int j=i-2*step;
					for(;j>=0&&arr[j]>temp;j-=step)
					{
						arr[j+step]=arr[j];
					}
					arr[j+step]=temp;
				}
			}
		}
	}
}

int main()
{
	int arr[]={49,38,65,97,76,13,27,49,55,04};
	int len=sizeof(arr)/sizeof(arr[0]);
	ShellSort(arr,len);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
