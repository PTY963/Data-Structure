#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];   //待排序的数据放在有序区间的后面，保存数据防止被覆盖
		while (end >= 0)        //循环终止的条件是end = -1
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;          //tmp如果大于等于的话，直接插入，无需再判断
			}
		}

		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//整体而言除以3的效率更好，加1是为了保证最后一次是直接插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}

}	
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int maxi = begin, mini = begin;
	while (begin < end)
	{
		for (int i = begin; i <= end; ++i)  //选出数组中最大的还最小的下标
		{
			if (a[maxi] < a[i])
				maxi = i;
			if (a[mini] > a[i])
				mini = i;
		}

		Swap(&a[begin], &a[mini]); //将大的放在最右边，小的放在最左边

		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}

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
	//建堆 - 排升序 - 建大堆
	for (int i = (n - 1 - 1) / 2; i <= 0; ++i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}