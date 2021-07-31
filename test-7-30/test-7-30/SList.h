#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
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
//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x);
//�����size
int SListSize(SLTNode* phead);
//�ж������Ƿ�Ϊ��
bool SListEmpty(SLTNode* phead);
//��pos֮ǰ��λ�ò���x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��posλ��ɾ��
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListEraseAfter(SLTNode* pos);