/*************************************************************************
    > File Name: hello.cpp
    > Created Time: Tue 02 Oct 2018 03:28:03 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//堆排序是时间复杂度最稳定的，不论它的次序如何，都是一样
//本代码是逆序输出，所以我们建立小根堆

//将完全二插树调整为最小堆
void HeapAdjust(int *arr,int i,int len)//i为调整堆的起始位置，从上往下找
{
	int j=2*i+1;   //j记录孩子节点的下标
	int tmp=arr[i];
	while(j<len)
	{
		if(j+1<len&&arr[j]>arr[j+1])//判断是否存在右孩子并比较与左孩子的大小
			j+=1;
		if(tmp>arr[j])  //当前的tmp大于其孩子节点
		{
			arr[i]=arr[j];
			i=j;   //将当前的i元素往下移动，实际上是移动它的孩子节点
			j=i*2+1;
		}
		else        //当前的tmp就是这个堆中最小的元素，不用再往下找
			break;
	}
	arr[i]=tmp;
}
void HeapSort(int *arr,int len)
{
	int i=(len/2)-1;
	//建立初始堆
	for(;i>=0;i--)
	{
		HeapAdjust(arr,i,len);
	}
	//调整建立完成的最小堆成为按顺序存储的新堆
	for(int j=1;j<len;j++)
	{
		int tmp=arr[0];     //交换第一个元素和逻辑上的最后一个元素
		arr[0]=arr[len-j];
		arr[len-j]=tmp;
		HeapAdjust(arr,0,len-j); //从0号位置调整堆，逻辑长度改变
	}
}
int main()
{
	int arr[]={1,23,14,53,24,15,87,5,96};
	int len=sizeof(arr)/sizeof(arr[0]);
 	HeapSort(arr,len);
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}




#if 0
void CreatHeap(int *arr,int size)
{
	int i=(size-1)/2;   //计算出第一个要调整的堆的跟节点的下标
	for(;i>=0;i--)   //每次减1是向上调整每一个以i为根的堆，直到回溯到0号元素
	{
		Adjust(arr,i,size);  //调整以i为根的堆，size是最后一个元素下标
	}
}
void HeapSort(int *arr,int len)
{
	assert(arr!=NULL);
	CreatHeap(arr,len-1);  //创建堆，将最后一个元素下标传入
}
void Adjust(int *arr,int start,int end)
{
	int tmp=arr[start]; //先将start位的
	int i=start*2+1;   //i表示孩子节点的下标
}
#endif
