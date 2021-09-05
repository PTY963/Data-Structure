#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode*  BuyNode(BTDataType root)
{
	BTNode* node =(BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->_data = root;
	node->_left = NULL;
	node->_right = NULL;

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

	node1->_left = node2;
	node1->_right = node3;
	node2->_left = node4;
	node3->_left = node5;
	node3->_right = node6;
	return node1;
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

void TestTree()
{
	BTNode* root = CreatBinaryTree();
	//ÖÐÐò±éÀú
	InOrder(root);
}
int main()
{
	TestTree();
	return 0;
}


