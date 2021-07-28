#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//消失的数字
//1.用0和0-n的数字异或
//2.再用0和数组里的数字异或 得到的结果就是缺失的数字
//时间复杂度为O(N)
//F(N)=N+N+1
//int missingNumber(int* nums, int numsSize)
//{
//	int x = 0;
//	//1.x=0和数组里的数字异或
//	for (int i = 0; i < numsSize; i++)
//	{
//		x ^= nums[i];
//	}
//	//2.x=0和0-n的数字异或
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

//给定一个数组，将数组中的元素向右移动k个位置，k为非负数
//解法1：
//右旋1次 ：保留最后一个值到天tmp变量中，数组中的值向右挪动1次，再把tmp放到最左边
//外面套一层循环 就旋转k次 时间复杂度O(N*(K%N) 空间复杂度O(1)

//解法2：
//额外申请一个数组 时间复杂度O(N) 空间复杂度O(N) 空间换时间

//解法3： 三步翻转法 时间复杂度O(N) 空间复杂度O(1)
//nums[]={1,2,3,4,5,6,7} k=3
//1.前n-k个逆置 4,3,2,1， 5,6,7
//2.后k个逆置   4,3,2,1, 7,6,5
//2.整体逆置    5,6,7，1,2,3,4

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