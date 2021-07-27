#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

//���룺nums = [1, 2, 10, 4, 1, 4, 3, 3]
//�����[2, 10] ��[10, 2]

//0001 -1
//0010
//0011 -3
//1010
//1001 -9
//0100
//1101 -13
//0001
//1100 -12
//0100
//1000 -8
//0011
//1011 -11
//0011
//1000 -8
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	//���������������һ�𣬵õ�һ����Ϊ0������
	int i = 0;
	int sum = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum ^= nums[i];//8
	}
	//�ӵ�λ����λ������������ҳ���һ�����ֵ�1 
	//1000
	//0001
	int pos = 0;
	for (i = 1; i <= 32; i++)
	{
		if (((sum >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//����1 �ֳ�����  ÿ����� �ҳ�����
	for (i = 0; i < numsSize; i++)//
	{
		if (((nums[i] >> pos) & 1) == 1)//1, 2, 10, 4, 1, 4, 3, 3
			returnSize[0] ^= nums[i];//
		else
			returnSize[1] ^= nums[i];
	}

	return returnSize;

}
int main()
{
	int nums[] = { 1, 2, 10, 4, 1, 4, 3, 3 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int returnSize[2] = { 0 };
	singleNumbers(nums, numsSize, returnSize);
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("%d ", returnSize[i]);
	}
	return 0;
}