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
	//��������Ƿ�
	//SeqListCheckCapcity(psl);

	//��������
	//psl->arr[psl->size] = x;
	//psl->size++;
	SeqListInsert(psl, psl->size, x);
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

	//�������
	//SeqListCheckCapcity(psl);

	//Ų������
	/*int end = psl->size - 1;
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}

	psl->arr[0] = x;
	psl->size++;*/

	SeqListInsert(psl, 0, x);
}
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	assert(psl->size > 0); //û�����ݵ��������ֹ����
	/*psl->size--;*/
	SeqListErase(psl, psl->size - 1);
}
void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	assert(psl->size > 0); //û�����ݵ��������ֹ����
	/*int front = 1;
	while (front < psl->size)
	{
		psl->arr[front - 1] = psl->arr[front];
		front++;
	}
	psl->size--;*/
	SeqListErase(psl, 0);
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; ++i)
	{
		if (psl->arr[i] == x)
		{
			return i;    //�ҵ��ˣ����������±�
		}
	}

	return -1;   //�Ҳ���������-1
}

//һ�������ͱ������ó�size_t���ͣ�һ��Ҫ�����������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);

	//��������Ƿ��㹻
	SeqListCheckCapcity(psl);

	//Ų������
	size_t end = psl->size;
	while (end > pos)
	{
		psl->arr[end] = psl->arr[end - 1];
		--end;
	}
	//��������
	psl->arr[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);

	size_t begin = pos + 1;
	while (begin < psl->size)//ѭ����ֹ��������begin����size
	{
		psl->arr[begin - 1] = psl->arr[begin];
		++begin;
	}
	psl->size--;
}
