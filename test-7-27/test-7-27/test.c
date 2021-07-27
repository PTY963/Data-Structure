#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

//输入：nums = [1, 2, 10, 4, 1, 4, 3, 3]
//输出：[2, 10] 或[10, 2]

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
	//把所以数字异或在一起，得到一个不为0的数字
	int i = 0;
	int sum = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum ^= nums[i];//8
	}
	//从低位到高位遍历这个数字找出第一个出现的1 
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
	//根据1 分成两组  每组异或 找出数字
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