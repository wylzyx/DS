
#include "SingleList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
//无头单向非循环
void SingleListInit(SingleList* sl)
{
	assert(sl);
	sl->_head = NULL;
}
void SingleListDestroy(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	while (cur)
	{
		SingleListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	sl->_head = NULL;
}

//尾插： O(N)
void SingleListPushBack(SingleList* sl, DataType x)
{
	assert(sl);
	//空链表
	if (sl->_head == NULL)
	{
		/*sl->_head = (SingleListNode* )malloc(sizeof(SingleListNode));
		sl->_head->_data = x;
		sl->_head->_next = NULL;*/
		sl->_head = CreatNode(x);
	}
	else
	{
		//遍历单链表
		SingleListNode* cur = sl->_head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		//找到最后一个节点
		cur->_next = CreatNode(x);
	}
}


SingleListNode* CreatNode(DataType x)
{
	SingleListNode* newNode = (SingleListNode*)malloc(sizeof(SingleListNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

//尾删： O(N)
void SingleListPopBack(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	SingleListNode* prev = NULL;
	if (cur == NULL)
		return;
	
	while (cur->_next)
	{
		prev = cur;
		cur = cur->_next;
	}

	free(cur);
	cur = NULL;
	if (prev == NULL)
	{
		//删除的为头节点
		sl->_head = NULL;
	}
	else
		prev->_next = NULL;
}
// 头插： O(1)
void SingleListPushFront(SingleList* sl, DataType x)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	SingleListNode* newNode = CreatNode(x);
	//头插
	newNode->_next = cur;
	sl->_head = newNode;
}

//头删：O(1)
void SingleListPopFront(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur, *next; 
	if (sl->_head == NULL)
		return;

	cur = sl->_head;
	next = sl->_head->_next;
	free(cur);
	cur = NULL;
	sl->_head = next;
}

void SingleListInsertAfter(SingleListNode* pos, DataType x)
{
	assert(pos);
	SingleListNode* newNode = CreatNode(x);
	SingleListNode* next = pos->_next;
	pos->_next = newNode;
	newNode->_next = next;
}
void SingleEraseAfter(SingleListNode* pos)
{
	assert(pos);
	SingleListNode* next = pos->_next;
	if (next == NULL)
		return;
	else
	{
		SingleListNode* next2 = next->_next;
		pos->_next = next2;
		free(next);
		next = NULL;
	}
}

void SingleListRemove(SingleList* sl, DataType x)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	SingleListNode* prev = NULL;
	while (cur)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
			{
				sl->_head = cur->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SingleListPrint(SingleList* sl)
{
	assert(sl);
	SingleListNode* cur = sl->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void testSL1()
{
	SingleList sl;
	SingleListInit(&sl);
	//SingleListPopFront(&sl);
	SingleListPushFront(&sl, 0);
	//SingleListPopFront(&sl);
	//SingleListPrint(&sl);
	SingleListPushBack(&sl, 1);
	SingleListPushBack(&sl, 2);
	SingleListPushBack(&sl, 3);
	/*SingleListInsertAfter(sl._head->_next->_next, 33);
	SingleListPushBack(&sl, 4);
	SingleListPrint(&sl);
	SingleEraseAfter(sl._head);
*/
	SingleListPushBack(&sl, 4);
	SingleListPushBack(&sl, 3);
	SingleListPrint(&sl);
	/*SingleListRemove(&sl, 3);
	SingleListPrint(&sl);*/
	SingleListDestroy(&sl);
	//SingleListPrint(&sl);

	/*SingleListPushFront(&sl, -1);
	SingleListPrint(&sl);*/

	/*SingleListPopBack(&sl);
	SingleListPrint(&sl);
	SingleListPopBack(&sl);
	SingleListPrint(&sl);
	SingleListPopBack(&sl);
	SingleListPrint(&sl);
	SingleListPopBack(&sl);
	SingleListPrint(&sl);
	SingleListPopBack(&sl);
	SingleListPrint(&sl);*/
}

//int main()
//{
//	testSL1();
//	return 0;
//}