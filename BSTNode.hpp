#ifndef BSTNODE
#define BSTNODE

template <class key_t, class val_t>

class BSTNode
{
protected:
  key_t key;
  val_t value;
  BSTNode<key_t,val_t>* parent;
  BSTNode<key_t,val_t>* leftChild;
  BSTNode<key_t,val_t>* rightChild;
  
public:
  BSTNode(const key_t& initialKey,const val_t& initialValue);
  virtual ~BSTNode();
  virtual const val_t& getValue() const;
  virtual void setValue(const val_t& newValue);
  
  virtual const key_t& getKey() const;
  virtual void setKey(const key_t& newKey);
  
  virtual BSTNode* getLeftChild() const;
  virtual void setLeftChild(BSTNode* newChild);
  
  virtual BSTNode* getRightChild() const;
  virtual void setRightChild(BSTNode* newChild);
  
  virtual BSTNode* getParent() const;
  virtual void setParent(BSTNode* newParent);
   
};

#include "BSTNode.tpp"

#endif
