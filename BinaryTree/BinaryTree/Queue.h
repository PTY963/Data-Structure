#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

//�õ�������ʵ�ֶ���
typedef BTNode QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
//���е�����о���β�壨��β���������о���ͷɾ����ͷ��
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//��������
void QueuePush(Queue* pq, QDataType x);
//ɾ������
void QueuePop(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//���ٶ���
void QueueDestory(Queue* pq);
//��¼���еĽ�����
int QueueSize(Queue* pq);
//�õ���ͷ������
QDataType QueueFront(Queue* pq);
