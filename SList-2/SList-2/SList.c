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
		//��β
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//mallocһ���½��
		SLTNode* newnode = BuySListNode(x);
		//�ı����ӹ�ϵ
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
//βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//1.����Ϊ�յ����
	if ((*pphead)->next == NULL)
	{
		//2.ֻ��һ���������
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//3.�������
		//�ҵ�β����ǰһ�����
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		//ɾ��β���
		free(tail->next);
		//����ǰ�����β���
		tail->next = NULL;
	}
}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);//����Ϊ�յ����

	SLTNode* front = (*pphead)->next;
	free(*pphead);
	*pphead = front;
}
//��������ĸ���
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

