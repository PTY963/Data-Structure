#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//¶¯Ì¬°æ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//Õ»¶¥µÄÎ»ÖÃ
	int capcity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);
STDataType StackTop(Stack* ps);