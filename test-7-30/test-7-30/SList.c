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

		//����һ���ڵ�Ŀռ�
		SLTNode* newnode = BuySListNode(x);
		//����
		tail->next = newnode;
	}
	
	
}

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;//*pphead��ŵ��ǵ�һ���ڵ�ĵ�ַ
	*pphead = newnode;
}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);//һ����㶼û��

	//1.��һ�����
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//2.�ж�����
		//�е�β
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;

	}

}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead != NULL);//һ����㶼û��
	//��һ�����
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
//����
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
//�����size
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
//�ж������Ƿ�Ϊ��
bool SListEmpty(SLTNode* phead)
{
	return phead == NULL;
}
//��pos֮ǰ��λ�ò���X
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	if (*pphead == NULL)//������
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
//��posλ��ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)//pos�ڵ�һ��λ��
	{
		SListPopFront(pphead);//ͷɾ
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
