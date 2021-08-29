#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

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

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->data = x;
	node->next = NULL;

	return node;
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		*pphead = BuySListNode(x);
	}
	else
	{
		//找尾
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//malloc一个新结点
		SLTNode* newnode = BuySListNode(x);
		//改变链接关系
		tail->next = newnode;
	}
}
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//1.链表为空的情况
	if ((*pphead)->next == NULL)
	{
		//2.只有一个结点的情况
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//3.常规情况
		//找到尾结点的前一个结点
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		//删除尾结点
		free(tail->next);
		//将当前结点变成尾结点
		tail->next = NULL;
	}
}
//头删
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//链表为空的情况

	SLTNode* front = (*pphead)->next;
	free(*pphead);
	*pphead = front;
}
//计算链表的个数
int SListSize(SLTNode* phead)
{
	int size = 0;
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		++size;
		cur = cur->next;
	}

	return size;
}
bool SListEmpty(SLTNode* phead)
{
	return  phead == NULL;
}

