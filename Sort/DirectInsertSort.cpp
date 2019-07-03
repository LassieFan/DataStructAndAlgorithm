/*************************************************************************
    > File Name: main.cpp
    > Created Time: Wed 05 Sep 2018 07:22:34 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<stdio.h>
using namespace std;

void InsertSort(int arr[],int len)
{
	int i,j;
	for(int x=0;x<len;x++)
		cout<<arr[x]<<" ";
	cout<<endl;
	for(i=1;i<len;i++)  //从下标为1的元素与之前的元素进行比较
	{
		if(arr[i]<arr[i-1])  //如果当前比较的元素小于它的前一个，则交换
		{
			int k=arr[i];  //保存当前元素
			arr[i]=arr[i-1];  //将前一个元素后移一位
			for(j=i-2;k<arr[j]&&j>=0;j--) //判断当前元素前2位及其之前的元素
			{
				arr[j+1]=arr[j];  //大于当前判断的元素k则后移j所指位
			}
			arr[j+1]=k;   //将当前判断元素k放置所找到的位置
		}
		for(int m=0;m<len;m++)
			cout<<arr[m]<<" ";
		cout<<endl;
	}
}

int main(int argc,char* argv[])
{
	int arr[]={2,1,4,99,6,2,7,9,31,52};
	int len=sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,len);
	return 0;
}

