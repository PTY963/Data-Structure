#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"
#include"Stack.h"
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];   //����������ݷ�����������ĺ��棬�������ݷ�ֹ������
		while (end >= 0)        //ѭ����ֹ��������end = -1
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;          //tmp������ڵ��ڵĻ���ֱ�Ӳ��룬�������ж�
			}
		}

		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//������Գ���3��Ч�ʸ��ã���1��Ϊ�˱�֤���һ����ֱ�Ӳ�������
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
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int maxi = begin, mini = begin;
	while (begin < end)
	{
		for (int i = begin; i <= end; ++i)  //ѡ�����������Ļ���С���±�
		{
			if (a[maxi] < a[i])
				maxi = i;
			if (a[mini] > a[i])
				mini = i;
		}

		Swap(&a[begin], &a[mini]); //����ķ������ұߣ�С�ķ��������

		if (begin == maxi)
			maxi = mini;

		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
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

//ð������
//void BubbleSort(int* a, int n)
//{
//	for (int j = 0; j < n; ++j)
//	{
//		for (int i = 1; i < n - j; ++i)      //i=1,��ǰһ���ͺ�һ����
//		{
//			if (a[i - 1] > a[i])             
//			{
//				Swap(&a[i - 1], &a[i]);
//			}
//		}
//	}
//}

void BubbleSort(int* a, int n)
{
	for (int end = n; end > 1; --end)      //end�������������
	{
		int exchange = 0;                  //��־λ������������Ƿ񽻻�
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)                //exchangeδ�ı䣬���鱾���������轻��
		{
			break;
		}
	}
}

//int PartSort(int* a, int left, int right)
//{
//	int key = left;
//	while (left < right)
//	{
//		//right�ȳ������ҵ���keyС��λ��
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//
//		//right�ҵ�֮��ֹͣ��left���ų������ҵ���key���ֵ
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[key], &a[left]);
//
//	return left;
//}
////ʱ�临�Ӷ���O(N*logN)
////���O(N^2)  ---  �Ż�
////1�����ѡkey ������
////2������ȡ��
//void QuickSort(int* a, int left, int right)
//{
//	if (left < right)
//	{
//		int keyi = PartSort(a, left, right);
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}


//int PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right  && a[right] >= a[keyi])
//		{
//			--right;
//		}
//
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//
//		//right�ߵ���С��λ�ã�left�ߵ��˴��λ��
//		Swap(&a[left], &a[right]);
//	}
//	//right��left������
//	Swap(&a[left], &a[keyi]);
//
//	return left;
//}
//void QuickSort(int* a, int left, int right)
//{
//	if (left < right)
//	{
//		int keyi = PartSort(a, left, right);
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}

//������������ʱ�临�Ӷ�O(N*logN)
//�����������£�O(N^2)
//1�����ѡkey

//2������ȡ�� left mid right ѡ���������Ҳ������С��
//���������������ȡͷ��ȡ�ľ�����Сֵ
//���ȡβ��ȡ�ľ������ֵ
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;//?
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else//a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}

	
}
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			--right;
		}

		while (left < right && a[left] <= a[key])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);

	return left;
}

//2���ڿӷ�
int PartSort2(int* a, int left, int right)
{
	//����ȡ�� -- ȡ��left mid right�в���Ҳ��С����
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//right��ȥ��С��
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;//right�ͳ��˿�

		//leftȥ�Ҵ��
		while (left < right && a[left] <= key)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

//3��ǰ��ָ��汾
int PartSort3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)//prev�Ѿ�++��
		{
			Swap(&a[prev], &a[cur]);
		}

		++cur;

		/*while (a[cur] >= a[key] && cur <= right)
		{
			++cur;
		}

		if (cur <= right)
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}
		
		++cur;*/
	}
	//����prev��key��ֵ
	Swap(&a[prev], &a[key]);

	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort3(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
	
}
//�ǵݹ�汾
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))//ѭ��������������ջ�Ѿ�û��������
	{
		int begin = StackTop(&st);
		StackPop(&st);

		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, begin, end);

		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}
	
	StackDestory(&st);
	
}

//�鲢����
void _MergeSort(int* a, int left, int right, int* tmp)
{
	//1���ֽ⣬������������
	if (left >= right)//�ݹ鷵�ص�����
	{
		return;
	}
	int mid = (left + right) / 2;
	//[left mid] [mid + 1 right]
	
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//2���鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2= right;
	int tmpi = left;

	//ѭ�������������ǣ�������������һ���ߵ�β
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[tmpi] = a[begin1];
			++begin1;
		}
		else//a[begin1] > a[begin2]
		{
			tmp[tmpi] = a[begin2];
			++begin2;
		}

		++tmpi;
	}
	//�����ߵ������˵����һ���Ѿ��ߵ���β
	while (begin1 <= end1)
	{
		tmp[tmpi++] = a[begin1++];
		
	}
	while (begin2 <= end2)
	{
		tmp[tmpi++] = a[begin2++];
		
	}

	//3������ʱ��������ݿ�����ԭ����
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);//�����ÿգ�tmp��������������ͻ�����
}