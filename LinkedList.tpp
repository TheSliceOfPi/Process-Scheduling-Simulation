#include <iostream>
using namespace std;
template <class item_t>

LinkedList<item_t>::LinkedList()
{
	head= 0;
	tail= 0;
	size=0;
} 

template <class item_t>
LinkedList<item_t>::~LinkedList()
{
	while(size>0)
	{
		remove(0);
	}
	head=0;
	tail=0;
	
}
template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item) //add to back
{	
	insert(size,item);
}

template <class item_t>
void LinkedList<item_t>::popBack() //remove back
{
	if(size==1)
	{
		head=0;
		tail=0;
	}
	if(size>1)
	{
	LinkedListNode<item_t>* next=head;
	for(int i=0;i<size-2;i++)
	{
		next=(*next).getNext();
	}
	tail=next;
	(*next).setNext(0);
	}
	size=size-1;
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const //return back
{
	return (*tail).getItem();
	
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item)  //add front
{
	insert(0,item);
	
}

template <class item_t>
void LinkedList<item_t>::popFront() //remove front
{
	remove(0);
	
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const //return front
{
	return (*head).getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const //return index
{
	LinkedListNode<item_t>* next=head;
	for(int i=0;i<index;i++)
	{
		next=(*next).getNext();
	}
	return (*next).getItem();
}

template <class item_t>
void LinkedList<item_t>::setItem(int index,const item_t& item)  //return index
{
	if(index==0)
	{
		(*head).setItem(item);
		
	}
	if(index>0)
	{
	LinkedListNode<item_t>* next=head;
	for(int i=0;i<index;i++)
	{
		next=(*next).getNext();
	}
		(*next).setItem(item);
	}
}

template <class item_t>
void LinkedList<item_t>::insert(int index,const item_t& item)  //insert at index
{
	if(index==0)
	{
		LinkedListNode<item_t>* pushItem = new LinkedListNode<item_t>(head,item);
		head=pushItem;
	if(size==0)
	{
		tail=head;
	}
	}
	
	if(index>0)
	{
	LinkedListNode<item_t>* next=head;
	for(int i=0;i<index-1;i++)
	{
		next=(*next).getNext();
	}
	
	LinkedListNode<item_t>* curNext=(*next).getNext();
	LinkedListNode<item_t>* pushItem = new LinkedListNode<item_t>(curNext,item);
	(*next).setNext(pushItem);
	if(index==size)
	{
		tail=pushItem;
	}
	}
	size=size+1;
	
}

template <class item_t>
void LinkedList<item_t>::remove(int index)  //remove index
{
	if(index==0)
	{
		LinkedListNode<item_t>* prev=head;
		head=(*head).getNext();
		delete prev;
	}
	
	else if(index>0)
	{
	LinkedListNode<item_t>* next=head;
	for(int i=0;i<index-1;i++)
	{
		next=(*next).getNext();
	}
	LinkedListNode<item_t>* prev=(*next).getNext();
	LinkedListNode<item_t>* curNext=(*prev).getNext();
	(*next).setNext(curNext);
	delete prev;
	}
	
	if(index==size-1)
	{
		tail=head;
	}
	if(size>0)
	{
	size=size-1;
	}

}

template <class item_t>
int LinkedList<item_t>::getSize() const  //return size
{
	return size;

}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const  //return empty
{
	if(head==0 && tail==0)
	{
		return true;
	}
	return false;
}




