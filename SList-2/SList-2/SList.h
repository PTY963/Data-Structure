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
//在pos之前的位置插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//在pos位置删除
void SListErase(SLTNode** pphead, SLTNode* pos);
//在pos位置的后面删除
void SListEraseAfter(SLTNode* pos);
//在pos位置的后面去插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);


