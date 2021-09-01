#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//堆排序，时间复杂度是O（N*logN）
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//向下调整算法（从根开始左右子树是小堆）
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中较小的孩子
		//假设是左孩子小
		if (child + 1 < n && a[child] > a[parent])//如果不是则++左孩子（左右孩子之间下标差1）
		{
			++child;
		}

		//比较小的孩子和父亲，如果孩子小于父亲则交换，不小于则停止
		if (a[child] < a[parent])
		{
			//交换
			Swap(&a[child], &a[parent]);
			//parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//选出左右孩子中较大的孩子
//		//假设是左孩子大
//		if (child + 1 < n && a[child] < a[parent])//如果不是则++左孩子（左右孩子之间下标差1）
//		{
//			++child;
//		}
//
//		//比较大的孩子和父亲，如果孩子大于父亲则交换，小于则停止
//		if (a[child] > a[parent])
//		{
//			//交换
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

void HeapSort(int* arr, int n)
{
	//创建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}
	
}
int main()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

