#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (arr[child] > arr[child + 1] && child + 1 < n)
		{
			++child;
		}

		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//建小堆 - 向下调整法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}

}
int main()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}