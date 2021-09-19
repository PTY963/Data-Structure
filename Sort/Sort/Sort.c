#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
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

//冒泡排序
//void BubbleSort(int* a, int n)
//{
//	for (int j = 0; j < n; ++j)
//	{
//		for (int i = 1; i < n - j; ++i)      //i=1,用前一个和后一个比
//		{
//			if (a[i - 1] > a[i])             
//			{
//				Swap(&a[i - 1], &a[i]);
//			}
//		}
//	}
//}

void BubbleSort(int* a, int n)
{
	for (int end = n; end > 1; --end)      //end控制排序的趟数
	{
		int exchange = 0;                  //标志位，检查两个数是否交换
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)                //exchange未改变，数组本身有序，无需交换
		{
			break;
		}
	}
}

//int PartSort(int* a, int left, int right)
//{
//	int key = left;
//	while (left < right)
//	{
//		//right先出发，找到比key小的位置
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//
//		//right找到之后停止，left接着出发，找到比key大的值
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[key], &a[left]);
//
//	return left;
//}
////时间复杂度是O(N*logN)
////最坏：O(N^2)  ---  优化
////1、随机选key 不靠谱
////2、三数取中
//void QuickSort(int* a, int left, int right)
//{
//	if (left < right)
//	{
//		int keyi = PartSort(a, left, right);
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}


int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right  && a[right] >= a[keyi])
		{
			--right;
		}

		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		//right走到了小的位置，left走到了大的位置
		Swap(&a[left], &a[right]);
	}
	//right和left相遇了
	Swap(&a[left], &a[keyi]);

	return left;
}
void QuickSort(int* a, int left, int right)
{
	if (left < right)
	{
		int keyi = PartSort(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}