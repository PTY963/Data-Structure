#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//插入排序：1、直接插入排序 2、希尔排序
void InsertSort(int* a, int n)
{
	//for循环用来控制end
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//控制单趟排序
		{
			if (tmp < a[end])//[end + 1]会被覆盖
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//end + 1 位置的值大于end位置的值时
				//end+1就应该在end的后面，无需移动，所以不可以在循环内
				break;
			}

		}

		a[end + 1] = tmp;
	}
}
int main()
{
	int arr[] = { 12, 34, 73, 15, 18, 6, 27, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

