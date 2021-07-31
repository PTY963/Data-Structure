#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//打印单链表
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

//尾插
//开辟一个节点的空间
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
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

		//开辟一个节点的空间
		SLTNode* newnode = BuySListNode(x);
		//链接
		tail->next = newnode;
	}
	
	
}

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//*pphead存放的是第一个节点的地址
	*pphead = newnode;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);//一个结点都没有

	//1.有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//2.有多个结点
		//招到尾
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;

	}

}
//头删
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);//一个结点都没有
	//有一个结点
	if ((*pphead)->next == NULL)
	{
		free(pphead);
		pphead = NULL;
	}
	else
	{
		SLTNode* front = *pphead;
		*pphead = (*pphead)->next;
		free(front);
		front = NULL;
	}
}
//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
//链表的size
int SListSize(SLTNode* phead)
{
	int size = 0;
	while (phead != NULL)
	{
		size++;
		phead = phead->next;
	}
	return size;
}
//判断链表是否为空
bool SListEmpty(SLTNode* phead)
{
	return phead == NULL;
}
//在pos之前的位置插入X
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)//空链表
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		if (prev->next != pos)
		{
			prev = prev->next;
		}

		SLTNode* newnode = BuySListNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}
}
//在pos位置删除
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)//pos在第一个位置
	{
		SListPopFront(pphead);//头删
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
