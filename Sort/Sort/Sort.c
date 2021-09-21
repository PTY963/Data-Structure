#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
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


//int PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right  && a[right] >= a[keyi])
//		{
//			--right;
//		}
//
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//
//		//right走到了小的位置，left走到了大的位置
//		Swap(&a[left], &a[right]);
//	}
//	//right和left相遇了
//	Swap(&a[left], &a[keyi]);
//
//	return left;
//}
//void QuickSort(int* a, int left, int right)
//{
//	if (left < right)
//	{
//		int keyi = PartSort(a, left, right);
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}

//在理想条件下时间复杂度O(N*logN)
//在有序条件下：O(N^2)
//1、随机选key

//2、三数取中 left mid right 选出不是最大也不是最小的
//针对有序情况，如果取头，取的就是最小值
//如果取尾，取的就是最大值
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;//?
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else//a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}

	
}
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			--right;
		}

		while (left < right && a[left] <= a[key])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);

	return left;
}

//2、挖坑法
int PartSort2(int* a, int left, int right)
{
	//三数取中 -- 取出left mid right中不大也不小的数
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//right先去找小的
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;//right就成了坑

		//left去找大的
		while (left < right && a[left] <= key)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//3、前后指针版本
int PartSort3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)//prev已经++了
		{
			Swap(&a[prev], &a[cur]);
		}

		++cur;

		/*while (a[cur] >= a[key] && cur <= right)
		{
			++cur;
		}

		if (cur <= right)
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
		
		++cur;*/
	}
	//交换prev和key的值
	Swap(&a[prev], &a[key]);

	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
	
}
//非递归版本
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))//循环结束的条件是栈已经没有数据了
	{
		int begin = StackTop(&st);
		StackPop(&st);

		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, begin, end);

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

//归并排序
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//1、分解，让子区间有序
	if (left >= right)//递归返回的条件
	{
		return;
	}
	int mid = (left + right) / 2;
	//[left mid] [mid + 1 right]
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2、归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2= right;
	int tmpi = left;

	//循环结束的条件是：两个数组中有一个走到尾
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[tmpi] = a[begin1];
			++begin1;
		}
		else//a[begin1] > a[begin2]
		{
			tmp[tmpi] = a[begin2];
			++begin2;
		}

		++tmpi;
	}
	//程序走到这儿，说明有一个已经走到了尾
	while (begin1 <= end1)
	{
		tmp[tmpi++] = a[begin1++];
		
	}
	while (begin2 <= end2)
	{
		tmp[tmpi++] = a[begin2++];
		
	}

	//3、将临时数组的内容拷贝到原数组
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);//无需置空，tmp变量出了作用域就会销毁
}