#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* pFast = pHead;
		ListNode* pSlow = pHead;
		ListNode* temp = NULL;
		while (pFast->next)
		{			
			pFast = pFast->next->next;
			pSlow = pSlow->next;
			if (pFast == pSlow)
			{
				temp = pFast;
				break;
			}

		}

		if (pFast->next != NULL)
		{
			pFast = temp->next;
			pSlow = pHead;
			while (pFast != pSlow)
			{
				pFast = (pFast == temp ? pHead : pFast->next);
				pSlow = (pSlow == temp ? temp->next : pSlow->next);
			}
			return pFast;
		}

		return NULL;
	}
};


int main()
{
	ListNode* t1 = new ListNode(1);
	ListNode* t2 = new ListNode(2);
	ListNode* t3 = new ListNode(3);
	ListNode* t4 = new ListNode(4);
	ListNode* t5 = new ListNode(5);
	ListNode* t6 = new ListNode(6);
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;
	t5->next = t6;
	t6->next = t3;
	Solution s;
	s.EntryNodeOfLoop(t1);
	return 0;
}