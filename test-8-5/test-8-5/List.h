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

//��ʼ������
void ListInit(LTNode** pphead);
//����һ���½��
LTNode* BuyListNode(LTDataType x);
//β��
void ListPushBack(LTNode* phead, LTDataType x);
//��ӡ
void ListPrint(LTNode* phead);
//βɾ
void ListPopBack(LTNode* phead);
//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead);
//���������н��ĸ���
size_t ListSize(LTNode* phead);
//��pos֮ǰ��λ�ò���
void ListInsert(LTNode* pos, LTDataType x);
//ͷ��
void ListPushFront(LTNode* phead, LTDataType x);
//����posλ�õĽ��
LTNode* ListFind(LTNode* phead, LTDataType x);
//��posλ��ɾ��
void ListErase(LTNode* pos);
//��������
void ListDestory(LTNode* phead);
