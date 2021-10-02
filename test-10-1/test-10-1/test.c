#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
void TestShellSort()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	//0 8 7 3 5 4 6 3 1 9
	Print(arr, size);
}
void TestSelectSort()
{
	int arr[] = { 12, 16, 43, 27, 76, 54, 27, 52,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, size);
	Print(arr, size);
}
void TestHeapSort()
{
	int arr[] = { 189, 45, 42, 18, 15, 38, 2, 73, 69, 128 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	Print(arr, size);
}
int main()
{
	//TestShellSort();
	//TestSelectSort();
	TestHeapSort();
	
	return 0;
}