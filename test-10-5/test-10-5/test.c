#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Stack.h"
void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int PartSort(int* a, int begin, int end)
{
	int keyi = begin;
	int prev = begin;
	int cur = prev + 1;

	while (cur <= end)
	{
		if (a[cur] <= a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		++cur;
	}

	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}



//�ݹ���������ѭ���������������
//1���ݹ�����̫�����ջ���
//2���������⣨���ڱ������Ż��ĺܺã�����ʲô�����⣩- ����ջ֡����Ҫ�Ļ���

void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);

		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort(a, begin, end);

		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
		
		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
		
	}

	StackDestory(&st);
}

int main()
{
	int arr[] = { 36, 12, 45, 65, 36, 72, 15, 30, 36, 89 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}