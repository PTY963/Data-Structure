#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capcity = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->a != NULL)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->top = 0;
	ps->capcity = 0;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//检查空间是否足够，不够则需要增容
	if (ps->top == ps->capcity)
	{
		int newcapcity = ps->capcity == 0 ? 4 : ps->capcity * 2;
		STDataType* ptr = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapcity);
		if (ptr == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = ptr;
		ps->capcity = newcapcity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	--ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}