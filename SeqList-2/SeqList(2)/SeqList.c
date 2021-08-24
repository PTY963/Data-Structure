#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListInit(SeqList* psl)
{
	assert(psl);

	psl->arr = NULL;
	psl->size = 0;
	psl->capcity = 0;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);

	if (psl->arr)
	{
		free(psl->arr);
		psl->arr = NULL;
	}

	psl->capcity = psl->size = 0;
}
void SeqListCheckCapcity(SeqList* psl)
{
	if (psl->capcity == psl->size)
	{
		int newcapcity = psl->capcity == 0 ? 4 : 2 * psl->capcity;
		psl->capcity = newcapcity;
		SLDataType* ptr = (SLDataType*)realloc(psl->arr, newcapcity * sizeof(SLDataType));
		if (ptr == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		psl->arr = ptr;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	//检查容量是否够
	SeqListCheckCapcity(psl);

	//插入数据
	psl->arr[psl->size] = x;
	psl->size++;
}
void SeqListPrint(SeqList* psl)
{
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	//检查容量
	SeqListCheckCapcity(psl);

	//挪动数据
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	psl->arr[0] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	psl->size--;
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	int front = 1;
	while (front != psl->size)
	{
		psl->arr[front - 1] = psl->arr[front];
		front++;
	}
	psl->size--;
}