#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capcity = 0;
	ps->top = 0;//-1 给0那么top就在数据的下一个位置，给-1top就在数据的位置
}
//销毁
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
//插入数据
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	//检查容量是否足够，不够增容
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

	//插入数据
	ps->a[ps->top] = x;
	ps->top++;//top指向的是数据的前一个位置
}
//判断栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
//删除数据
void StackPop(Stack* ps)
{
	assert(ps);
	//判断栈是否为空，如果为空程序终止
	assert(!StackEmpty(ps));
	//删除
	--ps->top;
}
//栈的大小
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//返回栈顶的值
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
