#include <iostream>
using namespace std;

template <class key_t,class val_t>

BSTNode<key_t,val_t>:: BSTNode(const key_t& initialKey,const val_t& initialValue) //Node with No children
{
key=initialKey;
value=initialValue;
leftChild=0;
rightChild=0;
parent=0;
}

template <class key_t,class val_t>

const val_t& BSTNode<key_t,val_t>::getValue() const
{
	return value;
}
template <class key_t,class val_t>
void BSTNode<key_t,val_t>::setValue(const val_t& newValue)
{
	value=newValue;
	cout<<value<<endl;
}
template <class key_t,class val_t>

const key_t&  BSTNode<key_t,val_t>::getKey() const
{
	return key;
}
template <class key_t,class val_t>
void BSTNode<key_t,val_t>::setKey(const key_t& newKey)
{
	key=newKey;
}

template <class key_t,class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getLeftChild() const
{
	return leftChild;
}

template <class key_t,class val_t>
void BSTNode<key_t,val_t>::setLeftChild(BSTNode* newChild)
{
	leftChild=newChild;
}

template <class key_t,class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getRightChild() const
{
	return rightChild;
}

template <class key_t,class val_t>
void BSTNode<key_t,val_t>::setRightChild(BSTNode* newChild)
{
	rightChild=newChild;
}


template <class key_t,class val_t>
BSTNode<key_t,val_t>* BSTNode<key_t,val_t>::getParent() const
{
	return parent;
}

template <class key_t,class val_t>
void BSTNode<key_t,val_t>::setParent(BSTNode* newParent)
{
	parent=newParent;
}
template <class key_t,class val_t>
BSTNode<key_t,val_t>::~BSTNode<key_t,val_t>()
{
}
