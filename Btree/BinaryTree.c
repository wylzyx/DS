#include <stdio.h>
#include <malloc.h>
#include "BinaryTree.h"
#include "Stack.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
		return NULL;
}
void BinaryTreeDestory(BTNode** root)
//void BinaryTreeDestory(BTNode* root)
{
	BTNode* curRoot = *root;
	if (curRoot)
	{
		BinaryTreeDestory(&curRoot->_left);
		BinaryTreeDestory(&curRoot->_right);
		free(curRoot);
		*root = NULL;
	}
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->_left)
		+ BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	//root 为叶子节点
	if (root->_left == NULL
		&& root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left)
		+ BinaryTreeLeafSize(root->_right);
}
//第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);

}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	//空树， 没有找到
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
		return ret;
	return NULL;
}
// 遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	/*else
		printf("# ");*/
}
void BinaryTreeInOrder(BTNode* root){
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	/*else
		printf("# ");*/
}
void BinaryTreePostOrder(BTNode* root){
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	/*else
		printf("# ");*/
}

//层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	//根节点入队
//	if (root)
//		QueuePush(&q, root);
//	//每次出队头元素，带出孩子节点，入队
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//遍历
//		printf("%c ", front->_data);
//		//孩子入队
//		if (front->_left)
//			QueuePush(&q, front->_left);
//		if (front->_right)
//			QueuePush(&q, front->_right);
//	}
//	printf("\n");
//
//}
//// 判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//判断是否为空
//		if (front)
//		{
//			QueuePush(&q, front->_left);
//			QueuePush(&q, front->_right);
//		}
//		else
//			//判断后面是否都为空
//			break;
//	}
//	while (QueueEmpty(&q) == 0)
//	{
//		BTNode* front = QueueFront(&q);
//		//判断是否为空，非空，说明不连续
//		if (front)
//		{
//			QueueDestroy(&q);
//			return 0;
//		}
//		QueuePop(&q);
//
//	}
//	return 1;
//}
void BinaryTreePrevOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//访问最后一棵子树的右子树
		top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
	printf("\n");

}
void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		//访问左子树，根入栈
		while (cur){
			StackPush(&st, cur);
			cur = cur->_left;
		}

		//访问根
		top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);

		//访问右子树
		cur = top->_right;
	}
	printf("\n");

}
void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode* cur = root;
	BTNode* top, *prev;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) == 0)
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		//访问最后一棵子树的右子树
		top = StackTop(&st);
		//判断是否存在右子树
		//不存在右： 访问根，出栈
		//存在：如果右子树已经访问完，可以访问根
		if (top->_right == NULL || top->_right == prev)
		{
			printf("%c ", top->_data);
			StackPop(&st);
			prev = top;
		}
		//存在右子树，且没有访问，先访问右子树
		else
			cur = top->_right;
	}
	printf("\n");
}

void testBTree1()
{
	int i = 0;
	// ABD##E#H##CF##G##
	char a[] = {'A', 'B', 'D', '#', '#', 'E', '#', 'H',
		'#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };

	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreePrevOrderNonR(root);
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreeInOrderNonR(root);
	//printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreePostOrderNonR(root);
	////BinaryTreeDestory(&root);
	//i = BinaryTreeLeafSize(root);
	//i = BinaryTreeLevelKSize(root, 1);
	//i = BinaryTreeLevelKSize(root, 2);
	//i = BinaryTreeLevelKSize(root, 3);
	//i = BinaryTreeLevelKSize(root, 4);



}

//void testBTree2()
//{
//	int i = 0;
//	int ret;
//	// ABD##E#H##CF##G##
//	char a[] = { 'A', 'B', 'D', 'G', '#', '#', 'H', '#',
//		'#', '#', 'C', 'E', '#', 'I', '#', '#', 'F', '#', '#' };
//	//ABDG##H###CE#I##F##
//
//	char a2[] = { 'A', 'B', 'D', 'G', '#', '#', 'H', '#',
//		'#', 'Z', '#','#', 'C', 'E', '#', '#', 'F', '#', '#' };
//
//	BTNode* root = BinaryTreeCreate(a, &i);
//	i = 0;
//	BTNode* root2 = BinaryTreeCreate(a2, &i);
//	
//	//BinaryTreePrevOrder(root);
//	printf("\n");
//	BinaryTreeLevelOrder(root);
//	BinaryTreeLevelOrder(root2);
//
//	ret = BinaryTreeComplete(root);
//	ret = BinaryTreeComplete(root2);
//
//	
//
//
//}

int main()
{
	testBTree1();
	//testBTree2();
	return 0;
}


struct TreeNode* _build(int* preorder, int* pindex, int* inorder,
	int inbegin, int inend)
{
	struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	root->val = preorder[*pindex];
	//在中序遍历中搜索根的位置
	int rootindex = inbegin;
	for (; rootindex <= inend; ++rootindex)
	{
		if (inorder[rootindex] == root->val)
			break;
	}
	//判断当前树是否有左右子树
	//左子树： inbegin  < rootindex
	if (inbegin < rootindex)
	{
		++(*pindex);
		root->left = _build(preorder, pindex, inorder, inbegin, rootindex - 1);
	}
	else
	{
		root->left = NULL;
	}
	//右子树： rootindex + 1 <= inend
	if (rootindex + 1 <= inend)
	{
		++(*pindex);
		root->right = _build(preorder, pindex, inorder, rootindex + 1, inend);
	}
	else
	{
		root->right = NULL;
	}

	return root;
}


