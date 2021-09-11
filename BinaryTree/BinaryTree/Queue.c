#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
}
//插入数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	//生成一个新结点
	QueueNode* newNode =(QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//改变新结点的数据域和指针域
	newNode->data = x;
	newNode->next = NULL;

	//链接到队列
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
//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	return pq->ptail == NULL;
}
//删除数据
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->phead->next == NULL)
	{
		//只剩一个结点的情况
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//还剩多个结点的情况

		//先保存phead的next
		QueueNode* next = pq->phead->next;
		//free掉phead
		free(pq->phead);//不用置为空，因为会给phead改变指向
		//更新phead
		pq->phead = next;
	}
}

//销毁队列
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

//记录队列中数据的个数
//如果频繁调用这个接口函数，可以在Queue中给一个size记录数据的个数
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