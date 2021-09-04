#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//void TestHeap()
//{
//	int arr[] = { 27, 37, 28, 18, 19, 34, 65, 25, 49, 15 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	Heap hp;
//	HeapInit(&hp, arr, size);
//	HeapPrint(&hp);
//
//	/*HeapPush(&hp, 18);
//	HeapPrint(&hp);
//	HeapPush(&hp, 98);
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);*/
//	int k = 0;
//	scanf("%d", &k);
//	printf("输出数组中前%d个数据：", k);
//	while (!HeapEmpty(&hp) && k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);//k*logN
//	}
//	printf("\n");
//}

void PrintTopk(HpDataType* a, HpDataType k, HpDataType N)
{
	Heap hp;
	HeapInit(&hp, a, k);

	for (int i = k; i < N; ++i)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
	HeapDestory(&hp);
}
void TopK()
{
	HpDataType N = 4000;
	HpDataType* a = (HpDataType*)malloc(sizeof(HpDataType) * N);
	if (a == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		a[i] = rand() % 1000000;//让随机数不超过一百万
	}

	a[500] = 1000001;
	a[1000] = 1000002; 
	a[1001] = 1000003;
	a[2004] = 1000004;
	a[3005] = 1000005;
	a[1314] = 1000006;
	a[42] = 1000007;
	a[123] = 1000008;
	a[456] = 1000009;
	a[897] = 1000010;

	PrintTopk(a, 10, N);

}
int main()
{
	//TestHeap();
	TopK();
	return 0;
}

