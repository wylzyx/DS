#include "List.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
void ListInit(List* lst)
{
	assert(lst);
	lst->_head = CreatListNode(0);
	lst->_head->_next = lst->_head;
	lst->_head->_prev = lst->_head;

}
void ListDestory(List* lst)
{
	assert(lst);
	ListNode* cur = lst->_head->_next;
	while (cur != lst->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	//头节点最后释放
	free(lst->_head);
}

ListNode* CreatListNode(DataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;
}

void ListPushBack(List* lst, DataType x)
{
	/*assert(lst);
	ListNode* tail;
	ListNode* newNode = CreatListNode(x);
	tail = lst->_head->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
*/
	ListInsert(lst, lst->_head, x);
}
void ListPushFront(List* lst, DataType x)
{
	/*assert(lst);
	ListNode* next = lst->_head->_next;
	ListNode* newNode = CreatListNode(x);

	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	newNode->_next = next;
	next->_prev = newNode;*/
	ListInsert(lst, lst->_head->_next, x);

}
void ListPopBack(List* lst)
{
	//assert(lst);
	//ListNode* prev, *tail;
	////头节点不能删除
	//if (lst->_head == lst->_head->_next)
	//	return;
	//tail = lst->_head->_prev;
	//prev = tail->_prev;

	//prev->_next = lst->_head;
	//lst->_head->_prev = prev;
	//free(tail);
	//tail = NULL;
	ListErase(lst, lst->_head->_prev);
}
void ListPopFront(List* lst)
{
	//assert(lst);
	//ListNode* next, *nextnext;
	////头节点不能删除
	//if (lst->_head == lst->_head->_next)
	//	return;

	//next = lst->_head->_next;
	//nextnext = next->_next;

	//lst->_head->_next = nextnext;
	//nextnext->_prev = lst->_head;

	//free(next);
	//next = NULL;
	ListErase(lst, lst->_head->_next);
	
}
//在pos前面插入数据
void ListInsert(List* lst, ListNode* pos, DataType x)
{
	assert(lst && pos);
	ListNode* prev = pos->_prev;
	ListNode* newNode = CreatListNode(x);
	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;

}
void ListErase(List* lst, ListNode* pos)
{
	assert(lst && pos);
	ListNode* prev, *next;
	//头节点不能删除
	if (lst->_head == pos)
		return;
	prev = pos->_prev;
	next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;

}

void ListPrint(List* lst)
{
	assert(lst);

	//第一个数据： head->next
	ListNode* cur = lst->_head->_next;
	while(cur != lst->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void testList()
{
	List lst;
	ListInit(&lst);
	ListPushBack(&lst, 1);
	ListPushBack(&lst, 2);
	ListPushBack(&lst, 3);
	ListPushBack(&lst, 4);
	ListPushFront(&lst, 0);
	ListPushFront(&lst, -1);
	ListPushFront(&lst, -2);  // -2, -1, 0, 1234
	ListPrint(&lst);
	/*ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);
	ListPopFront(&lst);
	ListPrint(&lst);*/
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);
	ListPopBack(&lst);
	ListPrint(&lst);

	ListDestory(&lst);
}

//int main()
//{
//	testList();
//	return 0;
//}