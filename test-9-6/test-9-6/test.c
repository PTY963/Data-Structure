#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//对任何一系列的数据都可以做到把它建成堆
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//小堆
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//找出左右孩子中较小的孩子
//		if (a[child + 1] < a[child] && child + 1 < n)
//		{
//			++child;
//		}
//
//		//1、如果孩子小于父亲就交换，大于就停止
//		if (a[child] < a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//大堆
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子中较小的孩子
		if (a[child + 1] > a[child] && child + 1 < n)
		{
			++child;
		}

		//1、如果孩子小于父亲就交换，大于就停止
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//建堆 - 向下调整算法 - 针对特殊数据
	//O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
	
	
}
int main()
{
	//int arr[] = {27,15,19,18,28,34,65,49,25,37};
	int arr[] = { 27,25,19,18,65,34,38,49,15,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
