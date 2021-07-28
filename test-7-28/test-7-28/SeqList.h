#pragma once

#define N 100
typedef int SQDataType;

//静态顺序表结构 实际上是很不方便的
typedef struct SeqList
{
	SQDataType arr[N];
	int sz;
}SLT;