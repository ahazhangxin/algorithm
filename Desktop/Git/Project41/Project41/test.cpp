//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//	vector<int> v1;
//	vector<int> v2;
//	int count = 0;
//	string s;
//	s = cin.get();
//	string temp;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != ' ')
//		{
//			temp += s[i];
//		}
//		else
//		{
//			v1.push_back(atoi(temp.c_str()));
//			temp = "";
//		}
//	}
//	s = cin.get();
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != ' ')
//		{
//			temp += s[i];
//		}
//		else
//		{
//			v2.push_back(atoi(temp.c_str()));
//			temp = "";
//		}
//	}
//	while (true)
//	{
//
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define ERROR -1
//typedef struct TreeNode *Tree;
//struct TreeNode
//{
//	int Key;
//	Tree Left;
//	Tree Right;
//};
//
//Tree BuildTree();
//int LCA(Tree T, int u, int v);
//
//int main()
//{
//	Tree T;
//	int u, v, ans;
//
//	T = BuildTree();
//
//	scanf("%d %d", &u, &v);
//	ans = LCA(T, u, v);
//	if (ans == ERROR)
//		printf("Wrong input\n");
//	else
//		printf("LCA = %d\n", ans);
//
//	return 0;
//}
//
//Tree insertNode(Tree root, int value)
//{
//	Tree newnode;
//	Tree current;
//	Tree back;
//	newnode = (Tree)malloc(sizeof(struct TreeNode));
//	if (newnode == NULL)
//	{
//		printf("\nmemory overflow!\n");
//		exit(1);
//	}
//	newnode->Key = value;
//	newnode->Left = NULL;
//	newnode->Right = NULL;
//	if (root == NULL)
//	{
//		return newnode;
//	}
//	else
//	{
//		current = root;
//		while (current != NULL)
//		{
//			back = current;
//			if (current->Key > value)
//				current = current->Left;
//			else
//				current = current->Right;
//		}
//		if (back->Key > value)
//			back->Left = newnode;
//		else
//			back->Right = newnode;
//	}
//	return root;
//}
//
//Tree BuildTree() //创建二叉树搜索树
//{
//	Tree root = NULL;
//	int len;
//	int num;
//	int i;
//
//	//输入结点的个数
//	scanf("%d", &len);
//	//连续输入len个数据(用空格隔开)
//	for (i = 0; i<len; i++)
//	{
//		scanf("%d", &num);
//		root = insertNode(root, num);
//	}
//
//	return root;
//}
//int LCA(Tree T, int u, int v)
//{
//	Tree p;
//	int isHere;
//	p = T;
//	isHere = 0;
//	while (p != NULL)
//	{
//		if (p->Key == u)
//		{
//			isHere = 1;
//			break;
//		}
//		else
//		{
//			if (p->Key > u)
//			{
//				p = p->Left;
//			}
//			else
//			{
//				p = p->Right;
//			}
//		}
//	}
//	if (isHere == 0) //二叉树没有u
//	{
//		return ERROR;
//	}
//	p = T;
//	isHere = 0;
//	while (p != NULL)
//	{
//		if (p->Key == v)
//		{
//			isHere = 1;
//			break;
//		}
//		else
//		{
//			if (p->Key > v)
//			{
//				p = p->Left;
//			}
//			else
//			{
//				p = p->Right;
//			}
//		}
//	}
//	if (isHere == 0) //二叉树没有v
//	{
//		return ERROR;
//	}
//	p = T;
//	while (p != NULL)
//	{
//		//如果u和v都小于Key，则LCA位于左子树中
//		if (p->Key > u && p->Key > v)
//		{
//			p = p->Left;
//		}
//		//如果u和v都大于Key,则LCA位于右子树中
//		else if (p->Key < u && p->Key < v)
//		{
//			p = p->Right;
//		}
//		else //找到最近公共祖先
//		{
//			break;
//		}
//	}
//	return p->Key;
//}


#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> vv;
		vector<TreeNode*> v;
		if (pRoot == nullptr)
			return vv;
		queue<TreeNode*> q;
		q.push(pRoot);
		vector<int> temp;
		while (!q.empty())
		{
			while (!q.empty())
			{
				v.push_back(q.front());
				temp.push_back(q.front()->val);
				q.pop();
			}
			for (int i = 0; i < v.size(); ++i)
			{
				if (v[i]->left)
					q.push(v[i]);
				if (v[i]->right)
					q.push(v[i]);
			}
			v.clear();
			vv.push_back(temp);
			temp.clear();
		}
		return vv;
	}
};

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	Solution s;
	s.Print(t1);
	return 0;
}