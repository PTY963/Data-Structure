#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int HpDataType;
typedef struct Heap
{
	HpDataType* a;
	int size;
	int capcity;
}Heap;

void Swap(HpDataType* px, HpDataType* py);
void AdjustDown(HpDataType* a, int n, int parent);
void AdjustUp(HpDataType* a, int child);

void HeapInit(Heap* php, HpDataType* arr, int n);
void HeapDestory(Heap* php);
void HeapPrint(Heap* php);
void HeapPush(Heap* php, HpDataType x);