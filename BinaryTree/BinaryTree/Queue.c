#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
}
//��������
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//����һ���½��
	QueueNode* newNode =(QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//�ı��½����������ָ����
	newNode->data = x;
	newNode->next = NULL;

	//���ӵ�����
	if (pq->ptail == NULL)
	{
		pq->phead = newNode;
		pq->ptail = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	return pq->ptail == NULL;
}
//ɾ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->phead->next == NULL)
	{
		//ֻʣһ���������
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//��ʣ����������

		//�ȱ���phead��next
		QueueNode* next = pq->phead->next;
		//free��phead
		free(pq->phead);//������Ϊ�գ���Ϊ���phead�ı�ָ��
		//����phead
		pq->phead = next;
	}
}

//���ٶ���
void QueueDestory(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->phead;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = pq->ptail = NULL;
}

//��¼���������ݵĸ���
//���Ƶ����������ӿں�����������Queue�и�һ��size��¼���ݵĸ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QueueNode* cur = pq->phead;
	while (cur)
	{
		++count;
		cur = cur->next;
	}

	return count;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}