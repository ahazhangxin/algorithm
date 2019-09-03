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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL || pHead2 == NULL)
			return pHead1 == NULL ? pHead2 : pHead1;
		ListNode* res = NULL;
		ListNode* temp;
		int a;
		while (pHead1 || pHead2)
		{
			temp = new ListNode(0);
			if (pHead1->val > pHead2->val || a > pHead2->val)
			{
				temp->val = pHead2->val;
				a = pHead2->val;
				pHead2 = pHead2->next;
			}
			else{
				temp->val = pHead1->val;
				pHead1 = pHead1->next;
			}
			if (res == nullptr)
				res = temp;
			temp = temp->next;
		}
		return res;
	}
};

int main()
{
	ListNode t = 1;
	t.next = new ListNode(2);
	t.next->next = new ListNode(3);
	Solution s;
	s.Merge(&t,&t);
	return 0;
}