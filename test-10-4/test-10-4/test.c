#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//快速排序递归实现
//单趟：hoare版本 - 左右指针法

//排升序 - left找大，right找小 排降序 - left找小，right找大
//key在左边，right先走，key在右边left先走
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
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] > a[mid])
	{
		if (a[right] > a[left])
			return left;
		else if (a[mid] > a[right])
			return mid;
		else
			return right;
	}
	else//a[left] < a[mid]
	{
		if (a[right] > a[mid])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}
//单趟排的时间复杂度是O(N)
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);//交换的原因是不想改变写好的代码
	int keyi = left;//必须是下标而不是临时变量

	while (left < right)
	{
		//为保证相遇点一定是小于key的值，让right先走
		while (a[right] >= a[keyi] && left < right)
		{
			--right;
		}

		//left找大
		while (a[left] <= a[keyi] && left < right)
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);

	return left;
}
//2、挖坑法 
//挖坑法很容易明白为什么key选左边，right先走
//挖坑法不用证明相遇点为什么一定是小值
int PartSort2(int* a, int left, int right)
{
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	
	int key = a[left];
	int hole = left;//初始情况left是key，所以left先作为坑
	while (left < right)
	{
		//right去找小填到左边的坑里
		while (a[right] >= key && left < right)
		{
			--right;
		}

		//填坑，填完坑之后，自己成为新的坑
		a[hole] = a[right];
		hole = right;

		//left去找大，填到右边的坑
		while (a[left] <= key && left < right)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}




//在最好的情况下：每次选出的key都在中间 - 那么只需高度次单趟排就可以
//最好情况的时间复杂度O(N*logN)
//在最坏的情况下：每次选的key都在第一个或者最后一次，那么就要N次单趟排
//最坏的时间复杂度是O(N^2)
//针对最坏的情况，提出的解决办法是：三数取中法 left mid right
//因为在有序的情况下，mid就是中间值
void QuickSort(int* a, int left, int right)
{
	//递归返回的条件: 区间只剩一个元素或者一个元素都没有
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort2(a, left, right);
	//[0, keyi - 1] keyi [keyi + 1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}
