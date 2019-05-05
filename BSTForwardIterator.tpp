#include <iostream>
using namespace std;

template <class key_t, class val_t>
BSTForwardIterator<key_t,val_t>:: BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel)
{
	current=node;
	this->sentinel=sentinel;
	
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t,val_t>:: next()
{
	if(current!=sentinel)
	{
	BSTNode<key_t, val_t>* temp=current;
	BSTNode<key_t, val_t>* nNext;
	if((*temp).getRightChild()!=sentinel)
		{	
			nNext=(*temp).getRightChild();
			while((*nNext).getLeftChild()!=sentinel)
			{
				nNext=(*nNext).getLeftChild();
			}
			current=nNext;
		}
	else
	{
	BSTNode<key_t, val_t>* y=(*temp).getParent();
	while(y!=sentinel && temp==(*y).getRightChild()) 
	    {
			temp=y;
			y=(*y).getParent();
	    }
	
	current= y;
	}
}
	
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t,val_t>:: isPastEnd() const
{
	if(current==sentinel)
	{
	return true;
	}
	return false;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t,val_t>:: getKey() const
{

	return (*current).getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t,val_t>:: getValue() const
{
	return (*current).getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t,val_t>:: setValue(const val_t& newVal)
{
	(*current).setValue(newVal);
}
