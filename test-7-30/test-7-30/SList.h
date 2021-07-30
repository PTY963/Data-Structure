#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

//����һ�����������ݽṹ
typedef struct SListNode
{
	int data;//int val
	struct SListNode* next;
}SLTNode;

//��ӡ������
void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷɾ
void SListPopFront(SLTNode** pphead);
//����һ���ڵ�Ŀռ�
SLTNode* BuySListNode(SLTDataType x);