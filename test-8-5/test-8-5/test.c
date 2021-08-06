#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//void TestList1()
//{
//	LTNode* plist = NULL;
//	ListInit(&plist);
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 4);
//
//	ListPrint(plist);
//
//	ListPopBack(plist);//4
//	ListPrint(plist);
//	ListPopBack(plist);//3
//	ListPrint(plist);
//	ListPopBack(plist);//2
//	ListPrint(plist);
//	ListPopBack(plist);//1
//	ListPrint(plist);
//	ListPopBack(plist);//删除头结点
//	ListPrint(plist);
//	ListPopBack(plist);//出错
//	ListPrint(plist);
//}

void TestList2()
{
	LTNode* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPushFront(plist, 11);
	ListPushFront(plist, 22);
	ListPushFront(plist, 33);
	ListPushFront(plist, 44);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 33);
	ListInsert(pos, 333);
	ListPrint(plist);
}
void TestList3()
{
	LTNode* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 3);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}
int main()
{
	//TestList1();
	//TestList2();
	TestList3();
	return 0;
}
