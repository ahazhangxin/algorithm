#include<iostream>
#include<string>

using namespace std;

template<typename T>
class A
{
public:
	int a;
	T t;
};

template<typename T>
class B : public A<T>
{
public:
	int b;
};

struct Node
{
	int data;
	Node * next;
};

Node* Merge(Node* head1, Node* head2)
{
	if (head1 == nullptr)  return head2;
	if (head2 == nullptr)  return head1;
	if (head1->data < head2->data){
		head1->next = Merge(head1->next, head2);
		return head1;
	}
	else{
		head2->next = Merge(head2->next, head1);
		return head2;
	}
}



class SealedClass
{
public:
	static SealedClass* getInstance()
	{
		return new SealedClass();
	}
	static void Delete(SealedClass* p)
	{
		delete p;
	}

private:
	SealedClass()       //将构造函数和析构函数设为私有
	{}
	~SealedClass()
	{}
};

struct BNode {
	int val;
	BNode* left;
	BNode* right;
	BNode() :
		val(0), left(nullptr), right(nullptr) {
	}
	BNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
private:
	BNode* maxNode = new BNode(INT_MIN);
	BNode* minNode = new BNode(INT_MAX);
private:
	BNode* getLCANode(BNode* root, BNode* p, BNode* q) {
		if (root == nullptr || root == p || root == q) {
			return root;
		}
		BNode* left = getLCANode(root->left, p, q);
		BNode* right = getLCANode(root->right, p, q);
		if (left && right) {
			return root;
		}
		if (left == nullptr)
			return right;
		else // right == nullptr;
			return left;
	}

	void getMaxMinNode(BNode* root){
		if (root == nullptr) return;
		if (root->val > maxNode->val){
			maxNode = root;
		}
		if (root->val < minNode->val){
			minNode = root;
		}
		getMaxMinNode(root->left);
		getMaxMinNode(root->right);
	}

	//get distance between maxNode or minNode and LCAnode
	int getDis(BNode* LCANode, BNode* node){
		if (LCANode == nullptr) return -1;
		if (LCANode->val == node->val)
			return 0;
		int dis = getDis(LCANode->left, node);
		if (dis == -1){
			dis = getDis(LCANode->right, node);
		}
		if (dis != -1){
			return dis + 1;
		}
		return -1;
	}
public:
	int getMaxMinNodeDis(BNode* root){
		if (root == nullptr) return 0;
		getMaxMinNode(root);
		BNode* LCANode = getLCANode(root, maxNode, minNode);
		int a = getDis(LCANode, maxNode);
		int b = getDis(LCANode, minNode);
		return a + b;
	}
};


#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	vector < vector<int>> v(m, vector<int>(n, 0));
	for (int o = 0; o < m; ++o){
		for (int p = 0; p < n; ++p){
			cin >> v[o][p];
		}
	}
	int i = 0, j = 0;
	int count = 0;
	while ((i+1)<m && (j+1)<n)
	{
		count += v[i][j];
		if (v[i + 1][j]>v[i][j + 1]){
			i++;
		}
		else{
			j++;
		}
	}
	if ((i + 1) == m){
		while (j < n)
		{
			count += v[i][j];
			j++;
		}
	}
	else if ((j+1) == n){
		while (i<m)
		{
			count += v[i][j];
			i++;
		}
	}
	cout << count << endl;
	return 0;
}