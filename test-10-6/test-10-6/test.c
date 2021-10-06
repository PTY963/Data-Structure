#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//1���ݹ�ֽ�����
	//����ֻʣ��һ�����ݻ���û������
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	//[left mid] [mid + 1 right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2���鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//index����ʱ����tmp���±�

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	//ѭ��������֮�󣬻���һ������û������
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
    //3������ʱ����������ݿ�����ԭ����
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp =(int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);//tmpָ�������ÿգ����˺�����û�˿����õ�tmp
}
//int main()
//{
//	int arr[] = { 12, 6, 15, 8, 32, 36, 10, 4 , 18, 23};
//	int size = sizeof(arr) / sizeof(arr[0]);
//	MergeSort(arr, size);
//	Print(arr, size);
//	return 0;
//}

//��������ֻ�����������������ݵ�ֵ�ܼ���
void CountSort(int* a, int n)
{
	//�ҳ�ԭ�����е����ֵ����Сֵ����������count����Ĵ�С
	int min = a[0], max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}

	int range = max - min + 1;
	int* count = calloc(range, sizeof(int));

	//����ԭ���飬��ÿ��ֵ���ֵĴ��������Ӧ��count����
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//��count�����ж�Ӧλ�õĴ���������д��ԭ����
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
		}
	}

}
int main()
{
	int arr[] = { 1000, 1001, 1200, 1500, 1001, 1999, 1999, 1998 };
	int size = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, size);
	Print(arr, size);
	return 0;
}
