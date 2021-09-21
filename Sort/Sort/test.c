#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
void TestInsert()
{
	int arr[] = { 54,38,96,23,15,72,60,45,83 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	Print(arr, size);
}
void TestShellSort()
{
	int arr[] = { 54,38,96,23,15,72,60,45,83 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	Print(arr, size);
}
void TestSelectSort()
{
	int arr[] = { 54,38,96,23,15,72,60,45,12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	Print(arr, size);
}
void TestHeapSort()
{
	int arr[] = { 54,38,96,23,15,72,60,45,12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	Print(arr, size);
}
void TestBubbleSort()
{
	int arr[] = { 54,38,96,23,15,72,60,45,12 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, size);
	Print(arr, size);
}
void TestQuickSort()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	perror("Quick");
}
void TestMergeSort()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	//6 1 2 7 9 3 4 5 10 8
	//6 1

	int size = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, size);
	Print(arr, size);
}
int main()
{
	//TestInsert();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	//TestQuickSort();
	TestMergeSort();
	return 0;
}
