#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void TestSList1()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;

	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	n2->data = 2;

	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	n3->data = 3;

	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	SListPrint(n1);

}
void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, -1);
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushFront(&plist, 0);

	SListPrint(plist);
}
int main()
{
	//TestSList1();
	TestSList2();
	return 0;
}
