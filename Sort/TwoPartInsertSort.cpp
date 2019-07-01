/*************************************************************************
    > File Name: main.cpp
    > Created Time: Wed 05 Sep 2018 07:22:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void BInsertSort(int arr[],int len)//在直接插入排序的基础上改进，处理更多的数量
{  
	for(int i=1;i<len;i++)
	{
		int k=arr[i];
		int low=0;
		int high=i-1;
		while(low<=high)    //二分查找，提高了查找效率，找到插入的位置
		{
			int m=(low+high)/2;
			if(k<arr[m])
			{
				high=m-1;  //插入位置在左边
			}
			else
			{
				low=m+1; //插入位置在右边
			}
		}
		for(int j=i;j>high+1&&j>0;j--)  //high+1为所要插入位置，将插入位置之后的元素都要往后移
		{
			arr[j]=arr[j-1];   //交换的时间其实并没有改变
		}
		arr[high+1]=k; //将当前进行比较的k元素放到high+1位置
	}
}
int main()
{
	int arr[]={2,1,4,99,6,2,7,9,31,52};
	int len=sizeof(arr)/sizeof(arr[0]);
	BInsertSort(arr,len);
	cout<<"排好序的数组为：";
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
