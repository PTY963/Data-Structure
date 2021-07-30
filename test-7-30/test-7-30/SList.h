#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

//定义一个单链表数据结构
typedef struct SListNode
{
	int data;//int val
	struct SListNode* next;
}SLTNode;

//打印单链表
void SListPrint(SLTNode* phead);
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
//尾删
void SListPopBack(SLTNode** pphead);
//头删
void SListPopFront(SLTNode** pphead);
//开辟一个节点的空间
SLTNode* BuySListNode(SLTDataType x);