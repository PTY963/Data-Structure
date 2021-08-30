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
		//ͷ��
		SListPushFront(pphead, x);
	}
	else
	{
		//���м����
		//�ҵ�pos��ǰһ��λ��
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//����һ���½��
		SLTNode* newnode = BuySListNode(x);
		//�ı����ӹ�ϵ
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

	//1.pos�ڵ�һ���ڵ��λ��
	//2.pos���м�λ��
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		//�ҵ�pos��ǰһ��λ��
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//�ı����ӹ�ϵ
		prev->next = pos->next;

		free(pos);
	}
}
void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);//pos����һ��λ�ò�����NULL

	SLTNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

