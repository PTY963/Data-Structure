#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType a;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;

}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	node->a = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode('A');
	BTNode* node2 = BuyNode('B');
	BTNode* node3 = BuyNode('C');
	BTNode* node4 = BuyNode('D');
	BTNode* node5 = BuyNode('E');
	BTNode* node6 = BuyNode('F');

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node3->left = node5;
	node3->right = node6;
	return node1;
}
//������������ĸ���
// 1������ - ȫ�ֱ���
//int size = 0;
//void BinaryTreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	else
//		size++;
//
//	BinaryTreeSize(root->left);
//	BinaryTreeSize(root->right);
//}
//2������ - �ֲ����� - ��ַ
//void BinaryTreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return;
//	else
//		++(*psize);
//
//	BinaryTreeSize(root->left, psize);
//	BinaryTreeSize(root->right, psize);
//}

//3���ݹ� - ���� - �߼�һ�����ǲ�����һ��
int BinaryTreeSize(BTNode* root)
{
	/*return root == NULL ? 0 : 1
		+ BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right);*/
	if (root == NULL)
		return 0;
	else
		return 1 + BinaryTreeSize(root->left)
		+ BinaryTreeSize(root->right);
	
}
//����Ҷ�ӽ��ĸ��� - ֻ�����Һ��Ӷ�ΪNULL����Ҷ�ӽ��
int BinaryTreeLeftSize(BTNode* root)
{
	if (root == NULL)//1�����ڵ���� 2��ֻ��һ������
	{
		return 0;
	}	
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}	
	else
	{
		return BinaryTreeLeftSize(root->left) 
			+ BinaryTreeLeftSize(root->right);
	}
}

//�����k����ĸ���
int BinaryTreeLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelSize(root->left, k - 1)
		+ BinaryTreeLevelSize(root->right, k - 1);
}
int main()
{
	BTNode* root = CreatBinaryTree();
	/*BinaryTreeSize(root);
	printf("BinaryTreeSize: %d\n", size);*/

	/*int size1 = 0;
	BinaryTreeSize(root, &size1);
	printf("BinaryTreeSize: %d\n", size1);

	int size2 = 0;
	BinaryTreeSize(root, &size2);
	printf("BinaryTreeSize: %d\n", size2);*/
	printf("BinaryTreeSize: %d\n", BinaryTreeSize(root));

	printf("BinaryTreeLeftSize: %d\n" , BinaryTreeLeftSize(root));

	printf("BinaryTreeLevelSize: %d\n", BinaryTreeLevelSize(root, 4));
	

	return 0;
}
