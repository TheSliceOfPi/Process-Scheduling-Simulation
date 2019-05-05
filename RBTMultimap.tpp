template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
  using namespace std;
  ofstream fout(filename.c_str());

  long long counter = 1;
  map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
  nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
  counter++;

  fout << "digraph RBTMultimap {" << endl;

  fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

  if(this->root != this->sentinel)
    {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
	{
	  nodeToCounter[rt] = counter;
	  counter++;
	}
      if(!nodeToCounter[rt->getParent()])
	{
	  nodeToCounter[rt->getParent()] = counter;
	  counter++;
	}
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
	{
	  fout << ", color=grey];" << endl;
	}
      else
	{
	  //The root's parent is something weird!! Make the arrow orange so it sticks out
	  fout << ", color=orange];" << endl;
	}

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
	{
	  RBTNode<key_t, val_t>* node = q.front();
	  q.pop();

	  printed[node] = true;
      
	  //Set up node's appearance
	  if(!nodeToCounter[node])
	    {
	      nodeToCounter[node] = counter;
	      counter++;
	    }
	  fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	  if(node->isRed())
	    {
	      fout << "red";
	    }
	  else
	    {
	      fout << "black, fontcolor=white";
	    }
	  fout << "];" << endl;

	  //Set up child links
	  //First the left node
	  if(!nodeToCounter[node->getLeftChild()])
	    {
	      nodeToCounter[node->getLeftChild()] = counter;
	      counter++;
	    }
	  fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	  if(node->getLeftChild() == this->sentinel)
	    {
	      fout << ", color=grey";
	    }
	  else if(printed[node->getLeftChild()])
	    {
	      fout << ", color=orange";
	    }
	  else
	    {
	      q.push(node->getLeftChild());
	    }

	  if(node->getLeftChild() != this->sentinel)
	    {
	      if(node->getLeftChild()->getParent() == node)
		{
		  //The child's parent pointer points right back,
		  //so draw the second arrow
		  fout << ", dir=both];" << endl;
		}
	      else
		{
		  //The child node's parent pointer is not correct!
		  //Draw it in orange so it sticks out
		  fout << "];" << endl;
		  if(!nodeToCounter[node->getLeftChild()->getParent()])
		    {
		      nodeToCounter[node->getLeftChild()->getParent()] = counter;
		      counter++;
		    }
		  fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
		}
	    }
	  else
	    {
	      fout << "];" << endl;
	    }

	  //Now the right node
	  if(!nodeToCounter[node->getRightChild()])
	    {
	      nodeToCounter[node->getRightChild()] = counter;
	      counter++;
	    }
	  fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	  if(node->getRightChild() == this->sentinel)
	    {
	      fout << ", color=grey";
	    }
	  else if(printed[node->getRightChild()])
	    {
	      fout << ", color=orange";
	    }
	  else
	    {
	      q.push(node->getRightChild());
	    }

	  if(node->getRightChild() != this->sentinel)
	    {
	      if(node->getRightChild()->getParent() == node)
		{
		  //The child's parent pointer points right back,
		  //so draw the second arrow
		  fout << ", dir=both];" << endl;
		}
	      else
		{
		  //The child node's parent pointer is not correct!
		  //Draw it in orange so it sticks out
		  fout << "];" << endl;
		  if(!nodeToCounter[node->getRightChild()->getParent()])
		    {
		      nodeToCounter[node->getRightChild()->getParent()] = counter;
		      counter++;
		    }
		  fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
		}
	    }
	  else
	    {
	      fout << "];" << endl;
	    }
	}
    }
  fout << "}" << endl;
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertNode(BSTNode<key_t,val_t>* newNode)
{
  BSTNode<key_t,val_t>* x=this->root;
  BSTNode<key_t,val_t>* y=this->sentinel;
  while(x !=this->sentinel)
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
  if(y==this->sentinel)
    {
      this->root=newNode;
    }
  else if((*newNode).getKey()<(*y).getKey())
    {
      (*y).setLeftChild(newNode);
    }
  else
    {
      (*y).setRightChild(newNode);
    }
	
  (*newNode).setRightChild(this->sentinel);
  (*newNode).setLeftChild(this->sentinel);
  this->numItems=this->numItems+1;
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value)
{
  RBTNode<key_t,val_t>* newNode= new RBTNode<key_t,val_t>(key,value,true);
  insertNode(newNode);
  insertFixup(newNode);
  this->numItems=this->numItems+1;
}
template <class key_t, class val_t>
RBTMultimap<key_t, val_t>:: RBTMultimap():BSTMultimap<key_t,val_t>()
{
  this->sentinel=new RBTNode<key_t,val_t>(key_t(),val_t(),false);
  this->root=this->sentinel;
 this->numItems=0;
}
template <class key_t, class val_t>
RBTMultimap<key_t, val_t>:: ~RBTMultimap()
{
  this->clear();
  delete (this->sentinel); 
	
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node)
{
  BSTNode<key_t,val_t>* y=node->getRightChild();
  BSTNode<key_t,val_t>* x=node;
  x->setRightChild(y->getLeftChild());
  if(y->getLeftChild()!=(this->sentinel))
    {
      (y->getLeftChild())->setParent(x);
    }
  y->setParent(x->getParent());
  if(x->getParent()==(this->sentinel))
    {
      this->root=y;
    }
  else if(x==(x->getParent())->getLeftChild())
    {
      (x->getParent())->setLeftChild(y);
    }
  else
    {
      (x->getParent())->setRightChild(y);
    }
  y->setLeftChild(x);
  x->setParent(y);
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node)
{
  BSTNode<key_t,val_t>* y=node->getLeftChild();
  BSTNode<key_t,val_t>* x=node;
  x->setLeftChild(y->getRightChild());
  if(y->getRightChild()!=(this->sentinel))
    {
      (y->getRightChild())->setParent(x);
    }
  y->setParent(x->getParent());
  if(x->getParent()==(this->sentinel))
    {
      this->root=y;
    }
  else if(x==(x->getParent())->getRightChild())
    {
      (x->getParent())->setRightChild(y);
    }
  else
    {
      (y->getParent())->setLeftChild(y);
    }
  y->setRightChild(x);
  x->setParent(y);
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode)
{
  dynamic_cast<RBTNode<key_t,val_t>*>(this->sentinel);
  while(dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()))->isRed()==true)
    {
      if(dynamic_cast<RBTNode<key_t,val_t>*>(insertedNode->getParent())==dynamic_cast<RBTNode<key_t,val_t>*>(((insertedNode->getParent())->getParent())-> getLeftChild()))
	{
	  RBTNode<key_t,val_t>* uncle=(((insertedNode->getParent())->getParent())->getRightChild());
	  if(uncle->isRed()==true) //Check for root and sentinel
	    {
	      dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()))->setIsRed(false);
	      uncle->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>(((insertedNode->getParent())->getParent()))->setIsRed(true);
	      insertedNode=dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent())->getParent());
	    }
	  else 
	    {
	      if (insertedNode==dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent())->getRightChild()))
		{
		  insertedNode=dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()));
		  rotateLeft(insertedNode);
		}
	      dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()))->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>(((insertedNode->getParent())->getParent()))->setIsRed(true);
	      rotateRight((insertedNode->getParent())->getParent());
	    }
	}
      else
	{
	  RBTNode<key_t,val_t>* uncle=(((insertedNode->getParent())->getParent())->getLeftChild());
	  if(uncle->isRed()==true) //Check for root and sentinel
	    {
	      dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()))->setIsRed(false);
	      uncle->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>(((insertedNode->getParent())->getParent()))->setIsRed(true);
	      insertedNode=dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent())->getParent());
	    }
	  else 
	    {
	      if (insertedNode==dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent())->getLeftChild()))
		{
		  insertedNode=dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()));
		  rotateRight(insertedNode);
		}
	      dynamic_cast<RBTNode<key_t,val_t>*>((insertedNode->getParent()))->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>(((insertedNode->getParent())->getParent()))->setIsRed(true);
	      rotateLeft((insertedNode->getParent())->getParent());
	    }
			
	}
    }
  dynamic_cast<RBTNode<key_t,val_t>*>(this->root)->setIsRed(false);
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode)
{
  if(nodeToReplace->getParent()==this->sentinel)
    {
      this->root=replacementNode;
    }
  else if (nodeToReplace==((nodeToReplace->getParent())->getLeftChild()))
    {
      (nodeToReplace->getParent())->setLeftChild(replacementNode);
    }
  else
    {
      ((nodeToReplace->getParent())->setRightChild(replacementNode));
    }
  replacementNode->setParent(nodeToReplace->getParent());
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
  //Make sure to get the next iterator returned
  BSTForwardIterator<key_t,val_t> copy= pos;
  copy.next();
	
  BSTNode<key_t,val_t>* deletedNode=pos.current;
  bool originalColor=dynamic_cast<RBTNode<key_t,val_t>*>(deletedNode)->isRed();
  BSTNode<key_t,val_t>* replacementNode;
	
  if(pos.current->getLeftChild()==this->sentinel)
    {
      replacementNode=pos.current->getRightChild();
      transplant(pos.current,pos.current->getRightChild());
    }
  else if(pos.current->getRightChild()==this->sentinel)
    {
      replacementNode=pos.current->getLeftChild();
      transplant(pos.current,pos.current->getLeftChild());
    }
  else
    {
      deletedNode=copy.current;
      originalColor=dynamic_cast<RBTNode<key_t,val_t>*>(deletedNode)->isRed();
    replacementNode=deletedNode->getRightChild();
		
      if(deletedNode->getParent()==pos.current)
	{
	  replacementNode->setParent(deletedNode);
	}
      else
	{
	  transplant(deletedNode,deletedNode->getRightChild());
	  deletedNode->setRightChild(pos.current->getRightChild());
	  (deletedNode->getRightChild())->setParent(deletedNode);
	}
      transplant(pos.current,deletedNode);
      deletedNode->setLeftChild(pos.current->getLeftChild());
      (deletedNode->getLeftChild())->setParent(deletedNode);
      dynamic_cast<RBTNode<key_t,val_t>*>(deletedNode)->setIsRed(dynamic_cast<RBTNode<key_t,val_t>*>(pos.current)->isRed());
    }
	
  if(originalColor==false)
    {
	RBTNode<key_t,val_t>* newReplacementNode=dynamic_cast<RBTNode<key_t,val_t>*>(replacementNode);
     deleteFixup(newReplacementNode);
    }
    delete pos.current;
    this->numItems=this->numItems-1;
	return copy;
}
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode)
{
	
  while(replacementNode!=dynamic_cast<RBTNode<key_t,val_t>*>(this->root) && replacementNode->isRed()==false)
    {
      if(replacementNode==dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent())->getLeftChild()))
	{
	  RBTNode<key_t,val_t>* w=(replacementNode->getParent())->getRightChild();
	  if(w->isRed()==true)
	    {
	      w->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent()))->setIsRed(true);
	      rotateLeft(replacementNode->getParent());
	      w=dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent())->getRightChild());
	      
	    }
	  if((dynamic_cast<RBTNode<key_t,val_t>*>(w->getLeftChild())->isRed()==false) && (dynamic_cast<RBTNode<key_t,val_t>*>(w->getRightChild())->isRed()==false))
	    {
	      w->setIsRed(true);
	      replacementNode=dynamic_cast<RBTNode<key_t,val_t>*>(replacementNode->getParent());
	    }
	  else 
	    {
		if(dynamic_cast<RBTNode<key_t,val_t>*>((w->getRightChild()))->isRed()==false)
		{
		  dynamic_cast<RBTNode<key_t,val_t>*>((w->getLeftChild()))->setIsRed(false);
		  w->setIsRed(true);
		  rotateRight(w);
		  w=dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent())->getRightChild());
		}
	      w->setIsRed(dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent()))->isRed());
	      dynamic_cast<RBTNode<key_t,val_t>*>((replacementNode->getParent()))->setIsRed(false);
	      dynamic_cast<RBTNode<key_t,val_t>*>((w->getRightChild()))->setIsRed(false);
	      rotateLeft(replacementNode->getParent());
	      replacementNode=dynamic_cast<RBTNode<key_t,val_t>*>(this->root);
	    }
		
	}
      else
	{
	  RBTNode<key_t,val_t>* w=(replacementNode->getParent())->getLeftChild();
	  if(w->isRed()==true)
	    {
	      w->setIsRed(false);
	      (replacementNode->getParent())->setIsRed(true);
	      rotateRight(replacementNode->getParent());
	      w=(replacementNode->getParent())->getLeftChild();
	    }
		
	  if((w->getRightChild())->isRed()==false && (w->getLeftChild())->isRed()==false)
	    {
	      w->setIsRed(true);
	      replacementNode=replacementNode->getParent();
	    }
	  else 
	    {
	      if((w->getLeftChild())->isRed()==false)
		{
		  (w->getRightChild())->setIsRed(false);
		  w->setIsRed(true);
		  rotateLeft(w);
		  w=(replacementNode->getParent())->getLeftChild();
		}
	      w->setIsRed((replacementNode->getParent())->isRed());
	      (replacementNode->getParent())->setIsRed(false);
	      (w->getLeftChild())->setIsRed(false);
	      rotateRight(replacementNode->getParent());
	      replacementNode=dynamic_cast<RBTNode<key_t,val_t>*>(this->root);
	    }
	}
    }
  replacementNode->setIsRed(false);
}

