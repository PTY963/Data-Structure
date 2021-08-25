#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
   SLDataType* arr;
   int size;       //��Ч���ݵĸ���
   int capcity;    //�ռ������Ĵ�С
}SeqList;

void SeqListInit(SeqList* psl);
void SeqListDestory(SeqList* psl);

//β��βɾ
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
//ͷ��ͷɾ
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

void SeqListPrint(SeqList* psl);
void SeqListCheckCapcity(SeqList* psl);

//����ĳ������
int SeqListFind(SeqList * psl, SLDataType x);
//������λ�ò���
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//������λ��ɾ��
void SeqListErase(SeqList* psl, size_t pos);