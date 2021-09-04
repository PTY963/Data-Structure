#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Swap(HpDataType* px, HpDataType* py)
{
	HpDataType tmp = *px;
	*px = *py;
	*py = tmp;
}
//向下调整算法
void AdjustDown(HpDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出最大的孩子
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			++child;
		}

		//判断孩子的父亲的大小，大则交换，小则停止
		if (a[child] < a[parent])
		{
			//交换
			Swap(&a[child], &a[parent]);
			//更新孩子和父亲的下标
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* php, HpDataType* arr, int n)
{
	assert(php);

	//malloc出来n个空间
	php->a = (HpDataType*)malloc(sizeof(HpDataType) * n);
	if (php->a == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//将arr数组中的数据拷贝到刚刚malloc出来的空间里
	memcpy(php->a, arr, sizeof(HpDataType) * n);

	//建堆-建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, n, i);
	}

	php->size = n;
	php->capcity = n;
}

void HeapDestory(Heap* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capcity = php->size = 0;
}

void HeapPrint(Heap* php)
{
	assert(php);

	for (int i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}


void AdjustUp(HpDataType* a, int child)
{
	assert(a);

	int parent = (child - 1) / 2;
	//parent >= 0条件是错误的，因为parent不会小于0，程序正确是因为0不小于0
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* php, HpDataType x)
{
	assert(php);

	if (php->capcity == php->size)
	{
		HpDataType* ptr = (HpDataType*)realloc(php->a, sizeof(HpDataType) * php->capcity * 2);
		if (ptr == NULL)
		{
			perror("realloc");
			exit(-1);
		}

		php->capcity *= 2;
		php->a = ptr;
	}

	php->a[php->size] = x;
	php->size++;

	//向上调整算法
	AdjustUp(php->a, php->size - 1);
}

//删除最值，找到次值
void HeapPop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);

}

bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->size == 0;
}

HpDataType HeapTop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->a[0];
}