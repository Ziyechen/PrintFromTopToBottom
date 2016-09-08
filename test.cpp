#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <stdlib.h>
#include "PrintFromTopToBottom.h"
using namespace std;

//测试用例
void TestPrintFromTopToBottom()
{
	int arr[] = { 8, 6, 5, '#', '#', 7, '#', '#', 10, 9, '#', '#', 11 };
	BinaryTreeNode *bt = BinaryTree(arr, sizeof(arr) / sizeof(arr[0]));

	PrintFromTopToBottom(bt);
}

int main()
{
	TestPrintFromTopToBottom();

	system("pause");
	return 0;
}
