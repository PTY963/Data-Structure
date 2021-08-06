#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//����һ���½��
LTNode* BuyListNode(LTDataType x)
{
	//����һ���½��
	LTNode* newNode = (LTNode*)malloc(sizeof(LTNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	//��ʼ���½��
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = x;

	return newNode;
}
//��ʼ������
void ListInit(LTNode** pphead)
{
	*pphead = BuyListNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

//β��
//void ListPushBack(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//	//��β
//	LTNode* tail = phead->prev;
//	//�����½��
//	LTNode* newnode = BuyListNode(x);
//	//�ı����ӹ�ϵ
//	tail->next = newnode;
//	newnode->prev = tail;
//
//	phead->prev = newnode;
//	newnode->next = phead;
//}

//��ӡ
void ListPrint(LTNode* phead)
{
	assert(phead);
	//�ڱ�λ�Ľ�㲻��ӡ
	LTNode* cur = phead->next;
	while (cur != phead)//cur = pheadѭ����ֹ
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	//����Ϊ�գ�˵��phead��nextָ�����Լ�
	return phead->next == phead;//�����ͬ�ͷ�����
}
//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	//�ж������Ƿ�Ϊ�գ�����ǿվͲ�����
	assert(!ListEmpty(phead));
	//�ҵ�β
	LTNode* tail = phead->prev;
	//�ҵ�β��ǰһ�����
	LTNode* tailPrev = tail->prev;
	//ɾ��β
	free(tail);
	//�ı����ӹ�ϵ
	phead->prev = tailPrev;
	tailPrev->next = phead;
}

//���������н��ĸ���
size_t ListSize(LTNode* phead)
{
	assert(phead);
	//���ܼ���ͷ���
	LTNode* cur = phead->next;
	size_t count = 0;
	while (cur != phead)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

//����posλ�õĽ��
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

//��pos֮ǰ��λ�ò���
void ListInsert( LTNode* pos, LTDataType x)
{
	assert(pos);

	//����һ���½��
	LTNode* newnode = BuyListNode(x);
	//�ҵ�posǰһ��λ��
	LTNode* prev = pos->prev;
	//�ı����ӹ�ϵprev newnode pos
	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}

//ͷ��
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->next, x);
}
//β��
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);
}

//��posλ��ɾ��
void ListErase(LTNode* pos)
{
	//�ж�pos�Ƿ�Ϊ��
	assert(pos);
	//�ҵ�pos��ǰһ���ͺ�һ��
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	//�ͷ�posλ�õĽ��
	free(pos);
	//�ı����ӹ�ϵ
	prev->next = next;
	next->prev = prev;
}
//��������
//��������ָ����Ϊ�˱��ֽӿڵ�һ���ԣ�������������Ұָ��
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
	phead = NULL;//�������ڲ��óɿ�Ҳ����Ӱ������
}
