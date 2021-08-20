#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//��̬��
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//ջ����λ��
	int capcity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);
STDataType StackTop(Stack* ps);