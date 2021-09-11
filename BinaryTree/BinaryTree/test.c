#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
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
//计算二叉树结点的个数
// 1、遍历 - 全局变量
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
//2、遍历 - 局部变量 - 传址
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

//3、递归 - 分治 - 逻辑一样但是参数不一样
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
//计算叶子结点的个数 - 只有左右孩子都为NULL才是叶子结点
int BinaryTreeLeftSize(BTNode* root)
{
	if (root == NULL)//1、根节点存在 2、只有一个孩子
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

//计算第k层结点的个数
int BinaryTreeLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelSize(root->left, k - 1)
		+ BinaryTreeLevelSize(root->right, k - 1);
}

//计算二叉树的深度/高度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//查找二叉树中值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->a == x)
		return root;

	//说明该节点不为空，并且该节点不是要查找的结点
	//先找左子树，找到了返回，找不到找右子树，还找不到，说明整棵树都没有，返回空
	
	//简化写法
	/*BTNode* retleft = BinaryTreeFind(root->left, x);
	if (retleft)
		return retleft;

	return BinaryTreeFind(root->right, x);*///右子树总要返回值

	//标准的写法
	BTNode* retleft = BinaryTreeFind(root->left, x);
	if (retleft != NULL)
		return retleft;
	BTNode* retright = BinaryTreeFind(root->right, x);
	if (retright != NULL)
		return retright;

	return NULL;

	
}
//二叉树的销毁
//传的是一级指针相当于传值
//对形参的置空，不会影响实参
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	//后序销毁
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//二叉树的层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	
//}

//判断一颗二叉树是不是完全二叉树

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
	
	printf("BinaryTreeDepth: %d\n", BinaryTreeDepth(root));

	BTNode* ret = BinaryTreeFind(root, 'V');
	if (ret == NULL)
		printf("没找到\n");
	else
		printf("找到了\n");


	BinaryTreeDestroy(root);
	root = NULL;

	return 0;
}
