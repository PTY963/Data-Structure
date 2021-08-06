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
//void ListPushBack(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	//找尾
//	LTNode* tail = phead->prev;
//	//生成新结点
//	LTNode* newnode = BuyListNode(x);
//	//改变链接关系
//	tail->next = newnode;
//	newnode->prev = tail;
//
//	phead->prev = newnode;
//	newnode->next = phead;
//}

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

//查找pos位置的结点
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

//在pos之前的位置插入
void ListInsert( LTNode* pos, LTDataType x)
{
	assert(pos);

	//生成一个新结点
	LTNode* newnode = BuyListNode(x);
	//找到pos前一个位置
	LTNode* prev = pos->prev;
	//改变链接关系prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

//头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->next, x);
}
//尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);
}

//在pos位置删除
void ListErase(LTNode* pos)
{
	//判断pos是否为空
	assert(pos);
	//找到pos的前一个和后一个
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	//释放pos位置的结点
	free(pos);
	//改变链接关系
	prev->next = next;
	next->prev = prev;
}
//销毁链表
//不传二级指针是为了保持接口的一致性，但是外面会产生野指针
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead;
	while (cur)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;//就算在内部置成空也不会影响外面
}
