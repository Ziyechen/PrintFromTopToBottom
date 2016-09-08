#pragma once

//层次遍历，从上到下打印二叉树，同一层从左到右遍历

#include <queue>

//二叉树结点定义如下
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;

	BinaryTreeNode(const int data)
		:m_nValue(data)
		, m_pLeft(NULL)
		, m_pRight(NULL)
	{}
};

//构造一棵二叉树

//size为数组长度,invalid是非法值，本次给的非法值为'#'
BinaryTreeNode * CreateBinaryTree(const int *arr, size_t size, size_t& index, const int &invalid)
{
	BinaryTreeNode * root = NULL;
	if (index < size && arr[index] != invalid)
	{
		root = new BinaryTreeNode(arr[index]);
		root->m_pLeft = CreateBinaryTree(arr, size, ++index, invalid);
		root->m_pRight = CreateBinaryTree(arr, size, ++index, invalid);
	}

	return root;
}

BinaryTreeNode * BinaryTree(const int *arr, size_t size)
{
	size_t index = 0;
	BinaryTreeNode *root = NULL;
	root = CreateBinaryTree(arr, size, index, '#');

	return root;
}

////先序遍历
//void _PrevOrder(BinaryTreeNode *cur)
//{
//	if (cur)
//	{
//		std::cout << cur->m_nValue << " ";
//		_PrevOrder(cur->m_pLeft);
//		_PrevOrder(cur->m_pRight);
//	}
//}
//
//void PrevOrder(BinaryTreeNode *root)
//{
//	_PrevOrder(root);
//	std::cout << std::endl;
//}

//层次遍历
void PrintFromTopToBottom(BinaryTreeNode *root)
{
	if (root == NULL)
		return;

	std::queue<BinaryTreeNode *> q;
	q.push(root);

	BinaryTreeNode *cur = root;
	while (!q.empty())
	{
		cur = q.front();

		BinaryTreeNode *left = cur->m_pLeft;
		BinaryTreeNode *right = cur->m_pRight;

		if (left)
			q.push(left);
		if (right)
			q.push(right);

		std::cout << q.front()->m_nValue << " ";
		q.pop();

		//if (!q.empty())
		//	cur = q.front();
	}

	std::cout << std::endl;
}
