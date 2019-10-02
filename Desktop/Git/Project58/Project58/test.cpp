#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	class CMP
	{
	public:
		bool operator()(const ListNode* node1,const ListNode* node2)
		{
			return node1->val <= node2->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* p;
		vector<ListNode*> v;
		for (int i = 0; i < lists.size(); ++i)
		{
			p = lists[i];
			while (p){
				v.push_back(p);
				p = p->next;
			}
		}
		if (v.size() == 0)
			return nullptr;
		sort(v.begin(), v.end(), CMP());
		for (int i = 1; i < v.size(); ++i)
		{
			v[i - 1]->next = v[i];
		}
		v[v.size() - 1]->next = nullptr;
		return v[0];
	}
};

int main()
{
	ListNode* node11 = new ListNode(1);
	ListNode* node12 = new ListNode(1);
	ListNode* node13 = new ListNode(2);
	ListNode* node21 = new ListNode(1);
	ListNode* node22 = new ListNode(2);
	ListNode* node23 = new ListNode(2);
	//ListNode* node31 = new ListNode(7);
	//ListNode* node32 = new ListNode(8);
	node11->next = node12;
	node12->next = node13;
	node13->next = nullptr;
	node21->next = node22;
	node22->next = node23;
	node23->next = nullptr;
	//node31->next = node32;
	//node32->next = nullptr;
	//node31->next = node32;
	vector<ListNode*> lists{ node11, node21};
	Solution s;
	s.mergeKLists(lists);
	return 0;
}