#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
template<class W>
struct HuffmanTreeNode{

	HuffmanTreeNode(const W& weight)
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _weight(weight)
	{}

	HuffmanTreeNode<W>* _pLeft;
	HuffmanTreeNode<W>* _pRight;
	HuffmanTreeNode<W>* _pParent;
	W _weight;
};

template<class W>
struct  Compare{
	typedef HuffmanTreeNode<W>* PNode;
	bool operator()(const PNode pLeft, const PNode pRight)
	{
		return pLeft->_weight > pRight->_weight;    //仿函数构造小堆
	}
};



template<class W>

class HuffmanTree
{
private:
	HuffmanTreeNode<W >* _root;
public:
	HuffmanTree()
		: _root(nullptr)
	{}

	void CreateHuffmanTree(const vector<W>& v,const W& invalid)
	{
		if (v.empty())
		{
			return;
		}

		priority_queue<HuffmanTreeNode<W>*, vector<HuffmanTreeNode<W>*>, Compare<W>> minheap;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] != invalid)
			{
				minheap.push(new HuffmanTreeNode<W>(v[i]));
			}
		}
		while (minheap.size() > 1)
		{
			HuffmanTreeNode<W>* pLeft = minheap.top();
			minheap.pop();
			HuffmanTreeNode<W>* pRight = minheap.top();
			minheap.pop();
			HuffmanTreeNode<W>* pParent = new HuffmanTreeNode<W>(pLeft->_weight + pRight->_weight);
			pParent->_pLeft = pLeft;
			pLeft->_pParent = pParent;
			pParent->_pRight = pRight;
			pRight->_pParent = pParent;
			minheap.push(pParent);
		}
		_root = minheap.top();
	}
	HuffmanTreeNode<W>* GetRoot()
	{
		return _root;
	}
	~HuffmanTree()
	{
		Destory(_root);
		//delete _root;
	}
private:
	void Destory(HuffmanTreeNode<W>*& root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destory(root->_pLeft);
		Destory(root->_pRight);
		delete root;
		root = nullptr;
	}
};
