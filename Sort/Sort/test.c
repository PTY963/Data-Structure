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
int main()
{
	//TestInsert();
	TestShellSort();
	return 0;
}

