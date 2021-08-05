#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void TestList1()
{
	LTNode* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	ListPopBack(plist);//4
	ListPrint(plist);
	ListPopBack(plist);//3
	ListPrint(plist);
	ListPopBack(plist);//2
	ListPrint(plist);
	ListPopBack(plist);//1
	ListPrint(plist);
	ListPopBack(plist);//删除头结点
	ListPrint(plist);
	ListPopBack(plist);//出错
	ListPrint(plist);
}
int main()
{
	TestList1();
	return 0;
}
