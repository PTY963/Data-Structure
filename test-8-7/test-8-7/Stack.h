#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//动态版
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶的位置
	int capcity;
}Stack;

//初始化
void StackInit(Stack* ps);
//销毁
void StackDestroy(Stack* ps);
//插入数据
void StackPush(Stack* ps, STDataType x);
//判断栈是否为空
bool StackEmpty(Stack* ps);
//删除数据
void StackPop(Stack* ps);
//栈的大小
int StackSize(Stack* ps);
//返回栈顶的值
STDataType StackTop(Stack* ps);
