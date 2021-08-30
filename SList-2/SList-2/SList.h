#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
SLTNode* BuySListNode(SLTDataType x);

void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);

int SListSize(SLTNode* phead);
bool SListEmpty(SLTNode* phead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//��pos֮ǰ��λ�ò���x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��posλ��ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);
//��posλ�õĺ���ɾ��
void SListEraseAfter(SLTNode* pos);
//��posλ�õĺ���ȥ����
void SListInsertAfter(SLTNode* pos, SLTDataType x);


