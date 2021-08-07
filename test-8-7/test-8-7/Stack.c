#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capcity = 0;
	ps->top = 0;//-1 ��0��ôtop�������ݵ���һ��λ�ã���-1top�������ݵ�λ��
}
//����
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
	}
	ps->capcity = 0;
	ps->top = 0;
}
//��������
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//��������Ƿ��㹻����������
	if (ps->capcity == ps->top)
	{
		int newcapcity = ps->capcity == 0 ? 4 : 2 * (ps->capcity);
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapcity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}

		ps->a = tmp;
		ps->capcity = newcapcity;
	}

	//��������
	ps->a[ps->top] = x;
	ps->top++;//topָ��������ݵ�ǰһ��λ��
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
//ɾ������
void StackPop(Stack* ps)
{
	assert(ps);
	//�ж�ջ�Ƿ�Ϊ�գ����Ϊ�ճ�����ֹ
	assert(!StackEmpty(ps));
	//ɾ��
	--ps->top;
}
//ջ�Ĵ�С
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//����ջ����ֵ
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
