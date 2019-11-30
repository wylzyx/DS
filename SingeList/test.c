#include <stdio.h>
//typedef struct ListNode {
//int val;
//struct ListNode *next;
//}ListNode;
//
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//
//		ListNode *fast, *slow;
//		if (pListHead == NULL)
//			return NULL;
//		fast = slow = pListHead;
//
//		while (k--)
//		{
//			if (fast == NULL)
//				return NULL;
//			fast = fast->next;
//
//		}
//
//		while (fast)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//
//	int main()
//	{
//		ListNode* head = (ListNode*) malloc(sizeof(ListNode));
//		ListNode* newNode;
//		head->val = 1;
//		head->next = (ListNode*)malloc(sizeof(ListNode));
//		head->next->val = 2;
//		head->next->next = (ListNode*)malloc(sizeof(ListNode));
//		head->next->next->val = 3;
//		head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
//		head->next->next->next->val = 4;
//		head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
//		head->next->next->next->next->val = 5;
//		head->next->next->next->next->next = NULL;
//		newNode = FindKthToTail(head, 5);
//
//		return 0;
//	}


//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		// write code here
//		ListNode* gH, *gT, *lH, *lT, *cur;
//		gH = gT = lH = lT = NULL;
//		if (pHead == NULL)
//			return pHead;
//		cur = pHead;
//		while (cur)
//		{
//			if (cur->val < x)
//			{
//				if (lH == NULL)
//				{
//					lT = lH = cur;
//				}
//				else
//				{
//					lT->next = cur;
//					lT = lT->next;
//				}
//			}
//			else
//			{
//				if (gH == NULL)
//				{
//					gT = gH = cur;
//				}
//				else
//				{
//					gT->next = cur;
//					gT = gT->next;
//				}
//			}
//
//			cur = cur->next;
//		}
//		if (lH == NULL)
//		{
//			return gH;
//		}
//		else
//		{
//			lT->next = gH;
//			return lH;
//		}
//	}
//};