#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//��ӡ������
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//β��
//����һ���ڵ�Ŀռ�
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	node->data = x;
	return node;
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		SLTNode* newnode = BuySListNode(x);
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//����һ���ڵ�Ŀռ�
		SLTNode* newnode = BuySListNode(x);
		//����
		tail->next = newnode;
	}
	
	
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//*pphead��ŵ��ǵ�һ���ڵ�ĵ�ַ
	*pphead = newnode;
}