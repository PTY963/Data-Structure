#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Swap(HpDataType* px, HpDataType* py)
{
	HpDataType tmp = *px;
	*px = *py;
	*py = tmp;
}
//���µ����㷨
void AdjustDown(HpDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����ĺ���
		if (a[child] > a[child + 1] && child + 1 < n)
		{
			++child;
		}

		//�жϺ��ӵĸ��׵Ĵ�С�����򽻻���С��ֹͣ
		if (a[child] < a[parent])
		{
			//����
			Swap(&a[child], &a[parent]);
			//���º��Ӻ͸��׵��±�
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

	//malloc����n���ռ�
	php->a = (HpDataType*)malloc(sizeof(HpDataType) * n);
	if (php->a == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//��arr�����е����ݿ������ո�malloc�����Ŀռ���
	memcpy(php->a, arr, sizeof(HpDataType) * n);

	//����-�����
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
	//parent >= 0�����Ǵ���ģ���Ϊparent����С��0��������ȷ����Ϊ0��С��0
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

	//���ϵ����㷨
	AdjustUp(php->a, php->size - 1);
}

//ɾ����ֵ���ҵ���ֵ
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