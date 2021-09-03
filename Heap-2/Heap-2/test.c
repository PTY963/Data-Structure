#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void TestHeap()
{
	int arr[] = { 27, 37, 28, 18, 19, 34, 65, 25, 49, 15 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	HeapInit(&hp, arr, size);
	HeapPrint(&hp);

	HeapPush(&hp, 18);
	HeapPrint(&hp);
	HeapPush(&hp, 98);
	HeapPrint(&hp);
}
int main()
{
	TestHeap();
	return 0;
}

