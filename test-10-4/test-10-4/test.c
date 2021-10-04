#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��������ݹ�ʵ��
//���ˣ�hoare�汾 - ����ָ�뷨

//������ - left�Ҵ�right��С �Ž��� - left��С��right�Ҵ�
//key����ߣ�right���ߣ�key���ұ�left����
void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] > a[mid])
	{
		if (a[right] > a[left])
			return left;
		else if (a[mid] > a[right])
			return mid;
		else
			return right;
	}
	else//a[left] < a[mid]
	{
		if (a[right] > a[mid])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}
//�����ŵ�ʱ�临�Ӷ���O(N)
int PartSort1(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[midi], &a[left]);//������ԭ���ǲ���ı�д�õĴ���
	int keyi = left;//�������±��������ʱ����

	while (left < right)
	{
		//Ϊ��֤������һ����С��key��ֵ����right����
		while (a[right] >= a[keyi] && left < right)
		{
			--right;
		}

		//left�Ҵ�
		while (a[left] <= a[keyi] && left < right)
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyi]);

	return left;
}
//2���ڿӷ� 
//�ڿӷ�����������Ϊʲôkeyѡ��ߣ�right����
//�ڿӷ�����֤��������Ϊʲôһ����Сֵ
int PartSort2(int* a, int left, int right)
{
	int keyi = GetMidIndex(a, left, right);
	Swap(&a[keyi], &a[left]);
	
	int key = a[left];
	int hole = left;//��ʼ���left��key������left����Ϊ��
	while (left < right)
	{
		//rightȥ��С���ߵĿ���
		while (a[right] >= key && left < right)
		{
			--right;
		}

		//��ӣ������֮���Լ���Ϊ�µĿ�
		a[hole] = a[right];
		hole = right;

		//leftȥ�Ҵ���ұߵĿ�
		while (a[left] <= key && left < right)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}




//����õ�����£�ÿ��ѡ����key�����м� - ��ôֻ��߶ȴε����žͿ���
//��������ʱ�临�Ӷ�O(N*logN)
//���������£�ÿ��ѡ��key���ڵ�һ���������һ�Σ���ô��ҪN�ε�����
//���ʱ�临�Ӷ���O(N^2)
//���������������Ľ���취�ǣ�����ȡ�з� left mid right
//��Ϊ�����������£�mid�����м�ֵ
void QuickSort(int* a, int left, int right)
{
	//�ݹ鷵�ص�����: ����ֻʣһ��Ԫ�ػ���һ��Ԫ�ض�û��
	if (left >= right)
	{
		return;
	}

	int keyi = PartSort2(a, left, right);
	//[0, keyi - 1] keyi [keyi + 1, right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}
