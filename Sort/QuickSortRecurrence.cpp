/*************************************************************************
    > File Name: main.cpp
    > Created Time: Sun 30 Sep 2018 06:45:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int Partition(int *arr,int low,int high) //划分算法，找到元素正确位置
{

	int tmp=arr[low];  //从第一个元素作为基准进行划分
	while(low<high)   //从序列两端交替向中间扫描
	{
		while(arr[high]>=tmp&&low<high) //从右向左扫描查找第一个小于基准的
			high--;
		if(low<high)    //找到小于基准的数，将其交换到表的左边
		{
			arr[low]=arr[high];
			low++;     //因为本位low已存从右边拿来的数据，所以low往后移
		}

		while(arr[low]<=tmp&&low<high) //从左往右找第一个大于基准的元素
			low++;
		if(high>low) //找到大于基准的数，将其交换到表的右边
		{
			arr[high]=arr[low];
			high--;
		}
	}
	arr[low]=tmp;  //最终的low/high位置即是基准在序列中的最终位置，放入即可
	return low;  //返回基准的最终位置下标
}
void QuickSort(int *arr,int low,int high)
{
	int i;
	if(low<high)
	{
		i=Partition(arr,low,high); //以i为基准将序列分为两部分
		if(i-low>1)   //避免一次递归调用，左边没有元素或者只有一个就不用排序
			QuickSort(arr,low,i-1);  //左半边进行排序
		if(high-i>1)
			QuickSort(arr,i+1,high);
	}
}
void Show(int *arr,int len)
{
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int arr[]={61,33,48,82,72,11,25,48};
	int len=sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,len-1);
	Show(arr,len);

}
