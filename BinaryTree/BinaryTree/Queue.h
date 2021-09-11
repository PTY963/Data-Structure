#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

//用单链表来实现队列
typedef BTNode QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
//队列的入队列就是尾插（找尾），出队列就是头删（找头）
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//初始化
void QueueInit(Queue* pq);
//插入数据
void QueuePush(Queue* pq, QDataType x);
//删除数据
void QueuePop(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
//销毁队列
void QueueDestory(Queue* pq);
//记录队列的结点个数
int QueueSize(Queue* pq);
//得到队头的数据
QDataType QueueFront(Queue* pq);
