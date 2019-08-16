
/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向*/
#include<iostream>
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* pre = NULL;//此处需要初始化，否则循环输入程序判错
		MiddleList(pRootOfTree, pre);
		while (pre->left != NULL)
			pre = pre->left;
		return pre;
	}
	void MiddleList(TreeNode* pRoot, TreeNode* &pre)//中序遍历可得双向链表
	{
		if (pRoot == NULL)
			return;
		MiddleList(pRoot->left, pre);
		if (pre != NULL)//改变指针的指向
		{
			pRoot->left = pre;
			pre->right = pRoot;
		}
		pre = pRoot;//记录前一个指针
		MiddleList(pRoot->right, pre);
	}
};

int main(){

	system("pause");
	return 0;
}