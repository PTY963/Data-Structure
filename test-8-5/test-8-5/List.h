#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//初始化链表
void ListInit(LTNode** pphead);
//生成一个新结点
LTNode* BuyListNode(LTDataType x);
//尾插
void ListPushBack(LTNode* phead, LTDataType x);
//打印
void ListPrint(LTNode* phead);
//尾删
void ListPopBack(LTNode* phead);
//判断链表是否为空
bool ListEmpty(LTNode* phead);
//计算链表中结点的个数
size_t ListSize(LTNode* phead);
//在pos之前的位置插入
void ListInsert(LTNode* pos, LTDataType x);
//头插
void ListPushFront(LTNode* phead, LTDataType x);
//查找pos位置的结点
LTNode* ListFind(LTNode* phead, LTDataType x);
//在pos位置删除
void ListErase(LTNode* pos);
//销毁链表
void ListDestory(LTNode* phead);
