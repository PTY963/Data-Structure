#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
   SLDataType* arr;
   int size;       //有效数据的个数
   int capcity;    //空间容量的大小
}SeqList;

void SeqListInit(SeqList* psl);
void SeqListDestory(SeqList* psl);

//尾插尾删
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
//头插头删
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

void SeqListPrint(SeqList* psl);
void SeqListCheckCapcity(SeqList* psl);