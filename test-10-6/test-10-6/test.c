#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//1、递归分解区间
	//区间只剩下一个数据或者没有数据
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	//[left mid] [mid + 1 right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2、归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//index是临时数组tmp的下标

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//循环跳出来之后，还有一组数据没有走完
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
    //3、将临时数组里的数据拷贝到原数组
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp =(int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);//tmp指针无需置空，出了函数，没人可以拿到tmp
}
//int main()
//{
//	int arr[] = { 12, 6, 15, 8, 32, 36, 10, 4 , 18, 23};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	MergeSort(arr, size);
//	Print(arr, size);
//	return 0;
//}

//计数排序，只适用于整数并且数据的值很集中
void CountSort(int* a, int n)
{
	//找出原数组中的最大值和最小值，用来开辟count数组的大小
	int min = a[0], max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* count = calloc(range, sizeof(int));

	//遍历原数组，将每个值出现的次数放入对应的count数组
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//将count数组中对应位置的次数，依次写入原数组
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
		}
	}

}
int main()
{
	int arr[] = { 1000, 1001, 1200, 1500, 1001, 1999, 1999, 1998 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	Print(arr, size);
	return 0;
}
