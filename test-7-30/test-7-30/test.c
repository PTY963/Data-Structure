#define _CRT_SECURE_NO_WARNINGS 1
//ȥ���㷨
//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//		return 0;
//
//	int src = 0, dst = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] == nums[dst])
//		{
//			++src;
//		}
//		else
//		{
//			++dst;
//			nums[dst] = nums[src];
//			++src;
//		}
//	}
//	return dst + 1;
//}
//int main()
//{
//	int nums[] = { 1,1,1,2,3,3,4 };
//	
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = removeDuplicates(nums, numsSize);
//	printf("%d\n", ret);
//	return 0;
//}

//��������������������nums1��nums2�����㽫nums2�ϲ���nums1�У�ʹnums1��Ϊһ����������
//void merge(int* nums1, int m, int* nums2, int n)
//{
//	int i1 = m - 1, i2 = n - 1;
//	int dst = m + n - 1;
//
//	//�Ӻ���ǰ����ȡ���ߵ����ֵ
//	while (i1 >= 0 && i2 >= 0)
//	{
//		if (nums1[i1] > nums2[i2])
//			nums1[dst--] = nums1[i1--];
//		else
//			nums1[dst--] = nums2[i2--];
//	}
//	//���������˵��������������һ���Ѿ�����
//	//�����nums2����������Ͳ���Ҫ���������nums1�����������nums2ʣ�µ����ݿ�����nums1
//	while(i2 >= 0)
//		nums1[dst--] = nums2[i2];
//
//
//	
//}
//int main()
//{
//	int nums1[6] = { 1,2,3,0,0,0 };
//	int nums2[3] = { 4,7,8};
//	merge(nums1, 3, nums2, 3);
//	int sz = sizeof(nums1) / sizeof(nums1[0]);
//	for (int i = 0; i < sz; ++i)
//	{
//		printf("%d ", nums1[i]);
//	}
//	return 0;
//}

#include"SList.h"
void Test1()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	n2->data = 2;
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	n3->data = 3;
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	SLTNode* plist = n1;
	SListPrint(plist);

}

void Test2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
}
void Test3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	SListErase(&plist, pos);
	SListPrint(plist);
}
	

int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}
