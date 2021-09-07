#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���κ�һϵ�е����ݶ����������������ɶ�
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//С��
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//�ҳ����Һ����н�С�ĺ���
//		if (a[child + 1] < a[child] && child + 1 < n)
//		{
//			++child;
//		}
//
//		//1���������С�ڸ��׾ͽ��������ھ�ֹͣ
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
//���
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//�ҳ����Һ����н�С�ĺ���
		if (a[child + 1] > a[child] && child + 1 < n)
		{
			++child;
		}

		//1���������С�ڸ��׾ͽ��������ھ�ֹͣ
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
	//���� - ���µ����㷨 - �����������
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
