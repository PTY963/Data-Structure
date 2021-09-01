#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//������ʱ�临�Ӷ���O��N*logN��
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//���µ����㷨���Ӹ���ʼ����������С�ѣ�
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����н�С�ĺ���
		//����������С
		if (child + 1 < n && a[child] > a[parent])//���������++���ӣ����Һ���֮���±��1��
		{
			++child;
		}

		//�Ƚ�С�ĺ��Ӻ͸��ף��������С�ڸ����򽻻�����С����ֹͣ
		if (a[child] < a[parent])
		{
			//����
			Swap(&a[child], &a[parent]);
			//parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//ѡ�����Һ����нϴ�ĺ���
//		//���������Ӵ�
//		if (child + 1 < n && a[child] < a[parent])//���������++���ӣ����Һ���֮���±��1��
//		{
//			++child;
//		}
//
//		//�Ƚϴ�ĺ��Ӻ͸��ף�������Ӵ��ڸ����򽻻���С����ֹͣ
//		if (a[child] > a[parent])
//		{
//			//����
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

void HeapSort(int* arr, int n)
{
	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}
	
}
int main()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

