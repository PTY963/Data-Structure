#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int  main()
//{
//	//Խ�粻һ������ϵͳ��Խ��ļ����һ�ֳ��
//	//Խ���һ���鲻����
//	//Խ��д����޸ĵ���־λ�Ż������
//	int arr[10];//0-9
//	//arr[9] = 9;
//	//arr[10] = 9;
//	//arr[11] = 9;
//	//arr[12] = 9;
//	//arr[20] = 9;
//	//arr[30] = 9;
//	return 0;
//}

//����һ������nums ��һ��ֵval������Ҫԭ���Ƴ�����ֵ����val��Ԫ��,
//�������Ƴ���������³���
//ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(1)
//int RemoveElement(int* nums, int numsSize, int val)
//{
//	int src = 0;//���srcָ������ݲ�����val���Ͱ����ݸ�ֵ��dst��ָ��Ŀռ�
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

//����һ����������nums������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ��
//����ɾ����������³���
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