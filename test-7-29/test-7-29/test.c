#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int  main()
//{
//	//越界不一定报错，系统对越界的检查是一种抽查
//	//越界读一般检查不出来
//	//越界写如果修改到标志位才会检查出来
//	int arr[10];//0-9
//	//arr[9] = 9;
//	//arr[10] = 9;
//	//arr[11] = 9;
//	//arr[12] = 9;
//	//arr[20] = 9;
//	//arr[30] = 9;
//	return 0;
//}

//给你一个数组nums 和一个值val，你需要原地移除所有值等于val的元素,
//并返回移除后数组的新长度
//时间复杂度O(N) 空间复杂度O(1)
//int RemoveElement(int* nums, int numsSize, int val)
//{
//	int src = 0;//如果src指向的数据不等于val，就把数据赋值给dst所指向的空间
//	int dst = 0;
//
//	while (src < numsSize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dst] = nums[src];
//			++src;
//			++dst;
//		}
//		else
//		{
//			++src;
//		}
//	}
//
//	return dst;
//
//}
//int main()
//{
//	int nums[] = { 4,3,4,5,6,3,3,0 };
//	int val = 3;
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int len = RemoveElement(nums, numsSize, val);
//	printf("%d\n", len);
//	return 0;
//}

//给你一个有序数组nums，请你原地删除重复出现的元素，使每个元素只出现一次
//返回删除后数组的新长度
int RemoveElement(int* nums, int numsSize)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] == nums[dst])
			++src;
		else
		{
			++dst;
			nums[dst] = nums[src];
		}
	}
	return dst + 1;
}
int main()
{
	int nums[] = { 1,1,1,1,2,3,3,3,4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = RemoveElement(nums, numsSize);
	printf("%d\n", ret);
	return 0;
}