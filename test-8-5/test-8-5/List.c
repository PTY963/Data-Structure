#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//生成一个新结点
LTNode* BuyListNode(LTDataType x)
{
	//生成一个新结点
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	//初始化新结点
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = x;

	return newNode;
}
//初始化链表
void ListInit(LTNode** pphead)
{
	*pphead = BuyListNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

//尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//找尾
	LTNode* tail = phead->prev;
	//生成新结点
	LTNode* newnode = BuyListNode(x);
	//改变链接关系
	tail->next = newnode;
	newnode->prev = tail;

	phead->prev = newnode;
	newnode->next = phead;
}

//打印
void ListPrint(LTNode* phead)
{
	assert(phead);
	//哨兵位的结点不打印
	LTNode* cur = phead->next;
	while (cur != phead)//cur = phead循环终止
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//判断链表是否为空
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	//链表为空，说明phead的next指向了自己
	return phead->next == phead;//如果相同就返回真
}
//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	//判断链表是否为空，如果是空就不继续
	assert(!ListEmpty(phead));
	//找到尾
	LTNode* tail = phead->prev;
	//找到尾的前一个结点
	LTNode* tailPrev = tail->prev;
	//删除尾
	free(tail);
	//改变链接关系
	phead->prev = tailPrev;
	tailPrev->next = phead;
}

//计算链表中结点的个数
size_t ListSize(LTNode* phead)
{
	assert(phead);
	//不能计算头结点
	LTNode* cur = phead->next;
	size_t count = 0;
	while (cur != phead)
	{
		++count;
		cur = cur->next;
	}
	return count;
}