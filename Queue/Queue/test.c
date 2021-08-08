#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	//QueuePop(&q);//1
	//QueuePop(&q);//2
	//QueuePop(&q);//3
	//QueuePop(&q);//4 出现了野指针

	return 0;
}

