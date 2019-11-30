
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* gH, *gT, *lH, *lT, *cur;
		gH = gT = lH = lT = NULL;
		if (pHead == NULL)
			return pHead;
		cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				if (lH == NULL)
				{
					lT = lH = cur;
				}
				else
				{
					lT->next = cur;
					lT = lT->next;
				}
			}
			else
			{
				if (gH == NULL)
				{
					gT = gH = cur;
				}
				else
				{
					gT->next = cur;
					gT = gT->next;
				}
			}

			cur = cur->next;
		}
		if (lH == NULL)
		{
			return gH;
		}
		else
		{
			lT->next = gH;
			return lH;
		}
	}
};

int main()
{
	Partition s;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(10);
	head->next->next = new ListNode(5);
	ListNode* newhead = s.partition(head, 6);
	return 0;
}