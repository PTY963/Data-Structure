#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1、预排序 - 让数据接近有序
//2、直接插入排序 - 在接近有序的情况下，直接插入排序的时间复杂度为O(N)
//void ShellSort(int* a, int n)
//{
//	
//	int gap = 3;
//	for (int j = 0; j < gap; ++j)
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = i;//end会改变，但是i不会
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			a[end + gap] = tmp;
//		}
//	}
//}

//O(N^1.3)
//gap要和排序的元素的数量进行关联
void  ShellSort(int* a, int n)
{
	
	//gap > 1 预排序
	//gap == 1 直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1是让最后一次gap为1
		//各组并行
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


void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//最烂的排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		//在[begin end]区间中选出最大的和最小的
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		//交换，小的放在begin，大的放在end
		Swap(&a[begin], &a[mini]);

		//最大值在第一个位置的情况
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}





//堆排序
void AdjustDown(int* a, int n, int parent)
{
	//选出parent的左孩子和右孩子当中的最大值
	//假设是左孩子最大
	int child = parent * 2 + 1;
	while (child < n)//终止条件2，到叶子结点结束
	{
		//如果右孩子存在且大于左孩子，则child + 1
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}

		//最大的孩子child和parent比较
		//大于parent则交换

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//终止条件1.最大的孩子小于parent
		}
	}
}
//void HeapSort(int* a, int n)
//{
//	//建堆 - 排升序 - 建大堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}


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

//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// 选出左右孩子中小 or 大的那个
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		// 1、如果小 or 大的孩子比父亲小 or 大，则交换，继续往下调整
//		// 2、如果小 or 大 的孩子比父亲大 or 小，则结束调整
//		if (a[child] > a[parent])
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
//
//// 堆排序 -> 效率更高
//// O(N*logN)
//void HeapSort(int* a, int n)
//{
//	// 排升序-》建大堆   
//	// 排降序-》建小堆
//	// O（N）
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}