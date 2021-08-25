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

//查找某个数据
int SeqListFind(SeqList * psl, SLDataType x);
//在任意位置插入
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//在任意位置删除
void SeqListErase(SeqList* psl, size_t pos);