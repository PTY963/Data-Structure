#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������1��ֱ�Ӳ������� 2��ϣ������
void InsertSort(int* a, int n)
{
	//forѭ����������end
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)//���Ƶ�������
		{
			if (tmp < a[end])//[end + 1]�ᱻ����
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//end + 1 λ�õ�ֵ����endλ�õ�ֵʱ
				//end+1��Ӧ����end�ĺ��棬�����ƶ������Բ�������ѭ����
				break;
			}

		}

		a[end + 1] = tmp;
	}
}
int main()
{
	int arr[] = { 12, 34, 73, 15, 18, 6, 27, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

