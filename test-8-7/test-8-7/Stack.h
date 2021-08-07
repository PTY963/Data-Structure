#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//��̬��
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//ջ����λ��
	int capcity;
}Stack;

//��ʼ��
void StackInit(Stack* ps);
//����
void StackDestroy(Stack* ps);
//��������
void StackPush(Stack* ps, STDataType x);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps);
//ɾ������
void StackPop(Stack* ps);
//ջ�Ĵ�С
int StackSize(Stack* ps);
//����ջ����ֵ
STDataType StackTop(Stack* ps);
