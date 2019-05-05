using namespace std;

template <class key_t,class val_t>

BSTMultimap<key_t,val_t>:: BSTMultimap() //Empty Tree
{
	sentinel=0;
	root=sentinel;
	numItems=0;
}

template <class key_t,class val_t>

void BSTMultimap<key_t,val_t>::insert(const key_t& key, const val_t& val)
{
	BSTNode<key_t,val_t>* newNode= new BSTNode<key_t,val_t>(key,val);
	BSTNode<key_t,val_t>* x=root;
	BSTNode<key_t,val_t>* y=sentinel;
	while(x !=sentinel)
	{
		y=x;
		if((*newNode).getKey()<(*x).getKey())
		{
			x=(*x).getLeftChild();
		}
		else
		{
			x=(*x).getRightChild();
		}
	}
	(*newNode).setParent(y);
	if(y==sentinel)
	{
		root=newNode;
	}
	else if((*newNode).getKey()<(*y).getKey())
	{
		(*y).setLeftChild(newNode);
	}
	else
	{
		(*y).setRightChild(newNode);
	}
	
	(*newNode).setRightChild(sentinel);
	(*newNode).setLeftChild(sentinel);
	numItems=numItems+1;
}

template <class key_t,class val_t>

int BSTMultimap<key_t,val_t>::getSize()
{
	return numItems;
}
template <class key_t,class val_t>

bool BSTMultimap<key_t,val_t>::isEmpty()
{
	if(numItems==0 && root==sentinel)
	{
	return true;
	}
	return false;
}

template <class key_t,class val_t>

string BSTMultimap<key_t,val_t>::toString()
{
	string treeString="";
	queue<BSTNode<key_t,val_t>*> treeCheck;
	BSTNode<key_t,val_t>* searching;
	treeCheck.push(root);
	while(!treeCheck.empty())
	{
		searching=treeCheck.front();
		treeString=treeString+to_string((*searching).getKey())+" ";
		treeCheck.pop();
		if((*searching).getLeftChild()!=sentinel)
		{
		treeCheck.push((*searching).getLeftChild());
		}
		if((*searching).getRightChild()!=sentinel)
		{
		treeCheck.push((*searching).getRightChild());
		}
	}
	return treeString;
}

template <class key_t,class val_t>

bool BSTMultimap<key_t,val_t>::contains(const key_t& key) const
{
	BSTNode<key_t,val_t>* curNode=root;
	while (curNode!=sentinel)
	{
		if((*curNode).getKey()==key)
		{
			return true;
		}
		else if((*curNode).getKey()>key)
		{
			curNode=(*curNode).getLeftChild();
		}
		else
		{
			curNode=(*curNode).getRightChild();
		}
	}
	return false;
	
}

template <class key_t,class val_t>

void BSTMultimap<key_t,val_t>::clear()
{
	queue<BSTNode<key_t,val_t>*> treeCheck;
	BSTNode<key_t,val_t>* searching;
	if(root!=sentinel)
	{
		treeCheck.push(root);
	}
	while(!treeCheck.empty())
	{
		
		searching =treeCheck.front();
		treeCheck.pop();
		if((*searching).getLeftChild()!=sentinel)
		{
		treeCheck.push((*searching).getLeftChild());
		}
		if((*searching).getRightChild()!=sentinel)
		{
		treeCheck.push((*searching).getRightChild());
		}
		delete searching;
	}
	
	root=sentinel;
	numItems=0;
	
}
template <class key_t,class val_t>
BSTMultimap<key_t,val_t>:: ~BSTMultimap() 
{
	clear();
}

template <class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>:: getMin() const
{
	if(numItems==0)
	{
		BSTForwardIterator<key_t,val_t> iterPoint=BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
		return iterPoint;
	}
	else
	{
		BSTNode<key_t, val_t>* nNext=root;
		while((*nNext).getLeftChild()!=sentinel)
		{	
			nNext=(*nNext).getLeftChild();
		}
		BSTForwardIterator<key_t,val_t> iterPoint=BSTForwardIterator<key_t,val_t>(nNext,sentinel);
		return iterPoint;
	}
}
template <class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>:: getMax() const
{
	if(numItems==0)
	{
		BSTForwardIterator<key_t,val_t> iterPoint=BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
		return iterPoint;
	}
	else
	{
		BSTNode<key_t, val_t>* nNext=root;
		while((*nNext).getRightChild()!=sentinel)
		{	
			nNext=(*nNext).getRightChild();
		}
		BSTForwardIterator<key_t,val_t> iterPoint=BSTForwardIterator<key_t,val_t>(nNext,sentinel);
		return iterPoint;
	}
}

template <class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>:: findFirst(const key_t& key) const
{
	BSTForwardIterator<key_t,val_t> iterPoint=getMin();
	while(iterPoint.isPastEnd()==false)
	{
		if(iterPoint.getKey()==key)
		{
			return iterPoint;
		}
		iterPoint.next();
	}
	return iterPoint;
}

template <class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>:: findLast(const key_t& key) const
{
	BSTForwardIterator<key_t,val_t> iterPoint=getMin();
	BSTForwardIterator<key_t,val_t> found=BSTForwardIterator<key_t,val_t>(sentinel,sentinel);
	while(iterPoint.isPastEnd()==false)
	{
		if(iterPoint.getKey()==key)
		{
			found=iterPoint;
		}
		iterPoint.next();
	}
	return found;
}

template <class key_t,class val_t>
BSTForwardIterator<key_t,val_t> BSTMultimap<key_t,val_t>:: remove(const BSTForwardIterator<key_t,val_t>& pos) 
{
	//Make sure to get the next iterator returned
  BSTForwardIterator<key_t,val_t> copy= pos;
  copy.next();
  if(pos.current->getLeftChild()==sentinel)
  {
	transplant(pos.current,pos.current->getRightChild());
	}
  else if(pos.current->getRightChild()==sentinel)
  {
	transplant(pos.current,pos.current->getLeftChild());
  }
  else
  {
	BSTNode<key_t,val_t>* y=copy.current;
	if(y->getParent()!=pos.current)
	{
		transplant(y,y->getRightChild());
		y->setRightChild(pos.current->getRightChild());
		y->getRightChild()->setParent(y);
	}
	transplant(pos.current,y);
	y->setLeftChild(pos.current->getLeftChild());
	y->getLeftChild()->setParent(y);
	
	}
	delete pos.current;
	numItems=numItems-1;
	return copy;
}
template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode)
{
  if(nodeToReplace->getParent()==sentinel)
    {
      root=replacementNode;
    }
  else if (nodeToReplace==((nodeToReplace->getParent())->getLeftChild()))
    {
      (nodeToReplace->getParent())->setLeftChild(replacementNode);
    }
  else
    {
      ((nodeToReplace->getParent())->setRightChild(replacementNode));
    }
  if(replacementNode!=sentinel)
   {
	replacementNode->setParent(nodeToReplace->getParent());
  }
}

