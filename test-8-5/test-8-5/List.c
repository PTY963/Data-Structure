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
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//��β
	LTNode* tail = phead->prev;
	//�����½��
	LTNode* newnode = BuyListNode(x);
	//�ı����ӹ�ϵ
	tail->next = newnode;
	newnode->prev = tail;

	phead->prev = newnode;
	newnode->next = phead;
}

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