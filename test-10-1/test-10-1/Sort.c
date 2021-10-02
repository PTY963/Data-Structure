#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1��Ԥ���� - �����ݽӽ�����
//2��ֱ�Ӳ������� - �ڽӽ����������£�ֱ�Ӳ��������ʱ�临�Ӷ�ΪO(N)
//void ShellSort(int* a, int n)
//{
//	
//	int gap = 3;
//	for (int j = 0; j < gap; ++j)
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = i;//end��ı䣬����i����
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//
//			a[end + gap] = tmp;
//		}
//	}
//}

//O(N^1.3)
//gapҪ�������Ԫ�ص��������й���
void  ShellSort(int* a, int n)
{
	
	//gap > 1 Ԥ����
	//gap == 1 ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1�������һ��gapΪ1
		//���鲢��
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}


void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
//���õ�����
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;

	while (begin < end)
	{
		//��[begin end]������ѡ�����ĺ���С��
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		//������С�ķ���begin����ķ���end
		Swap(&a[begin], &a[mini]);

		//���ֵ�ڵ�һ��λ�õ����
		if (begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}





//������
void AdjustDown(int* a, int n, int parent)
{
	//ѡ��parent�����Ӻ��Һ��ӵ��е����ֵ
	//�������������
	int child = parent * 2 + 1;
	while (child < n)//��ֹ����2����Ҷ�ӽ�����
	{
		//����Һ��Ӵ����Ҵ������ӣ���child + 1
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}

		//���ĺ���child��parent�Ƚ�
		//����parent�򽻻�

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//��ֹ����1.���ĺ���С��parent
		}
	}
}
//void HeapSort(int* a, int n)
//{
//	//���� - ������ - �����
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}


void HeapSort(int* a, int n)
{
	//���� - ������ - �����
	for (int i = (n - 1 - 1) / 2; i <= 0; ++i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

//void AdjustDown(int* a, int n, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		// ѡ�����Һ�����С or ����Ǹ�
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//
//		// 1�����С or ��ĺ��ӱȸ���С or ���򽻻����������µ���
//		// 2�����С or �� �ĺ��ӱȸ��״� or С�����������
//		if (a[child] > a[parent])
//		{
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
//
//// ������ -> Ч�ʸ���
//// O(N*logN)
//void HeapSort(int* a, int n)
//{
//	// ������-�������   
//	// �Ž���-����С��
//	// O��N��
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		AdjustDown(a, n, i);
//	}
//
//	// O(N*logN)
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}