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

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}

	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
	{
		//头插
		SListPushFront(pphead, x);
	}
	else
	{
		//在中间插入
		//找到pos的前一个位置
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//申请一个新结点
		SLTNode* newnode = BuySListNode(x);
		//改变链接关系
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);

	//1.pos在第一个节点的位置
	//2.pos在中间位置
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		//找到pos的前一个位置
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//改变链接关系
		prev->next = pos->next;

		free(pos);
	}
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//pos的下一个位置不能是NULL

	SLTNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

