#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ʧ������
//1.��0��0-n���������
//2.����0���������������� �õ��Ľ������ȱʧ������
//ʱ�临�Ӷ�ΪO(N)
//F(N)=N+N+1
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	//1.x=0����������������
//	for (int i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	//2.x=0��0-n���������
//	for (int i = 0; i <= numsSize; i++)
//	{
//		x ^= i;
//	}
//
//	return x;
//}
//int main()
//{
//	int nums[] = { 0,1,3 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = missingNumber(nums,numsSize);
//	printf("%d\n", ret);
//	return 0;
//}

//����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�kΪ�Ǹ���
//�ⷨ1��
//����1�� ���������һ��ֵ����tmp�����У������е�ֵ����Ų��1�Σ��ٰ�tmp�ŵ������
//������һ��ѭ�� ����תk�� ʱ�临�Ӷ�O(N*(K%N) �ռ临�Ӷ�O(1)

//�ⷨ2��
//��������һ������ ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(N) �ռ任ʱ��

//�ⷨ3�� ������ת�� ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(1)
//nums[]={1,2,3,4,5,6,7} k=3
//1.ǰn-k������ 4,3,2,1�� 5,6,7
//2.��k������   4,3,2,1, 7,6,5
//2.��������    5,6,7��1,2,3,4

//void reverse(int* nums, int begin, int end)
//{
//	while (begin < end)
//	{
//		int tmp = nums[begin];
//		nums[begin] = nums[end];
//		nums[end] = tmp;
//		begin++;
//		end--;
//	}
//}
//void rotate(int* nums, size_t k, int numsSize)
//{
//	k = k % numsSize;
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//	
//}
//int main()
//{
//	int nums[] = { 1,2,3,4,5,6,7 };
//	size_t k = 3;
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	rotate(nums, k, numsSize);
//	for (int i = 0; i < numsSize; i++)
//	{
//		printf("%d ", nums[i]);//5 6 7 1 2 3 4
//	}
//	return 0;
//}


void rotate(int* nums, int numsSize, size_t k)
{
    k = k % numsSize;

    while (k--)//3 2 1 0
    {
        
        int tmp = nums[numsSize-1];

        for (int i = numsSize - 2; i >= 0; i--)
        {
            nums[i + 1] = nums[i];
        }

        nums[0] = tmp;

    }
}

int main()
{
    int nums[] = { 1,2,3,4,5,6,7 };
    size_t k = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    rotate(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", nums[i]);//5 6 7 1 2 3 4
    }
    return 0;
}