#ifndef BSTMULTIMAP
#define BSTMULTIMAP
#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"
#include <queue>
template <class key_t, class val_t>

class BSTMultimap
{
protected:
	BSTNode<key_t,val_t>* root;
	BSTNode<key_t,val_t>* sentinel;
	int numItems;
	virtual void transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode);
	
  
public:
  BSTMultimap();
	virtual ~BSTMultimap();
  
  virtual void insert(const key_t& key, const val_t& val);
  virtual int getSize();
  virtual bool isEmpty();
  virtual string toString();
  
  virtual bool contains(const key_t& key) const;
  virtual void clear();
  virtual BSTForwardIterator<key_t,val_t> getMin() const;
  
  virtual BSTForwardIterator<key_t,val_t> getMax() const;
  virtual BSTForwardIterator<key_t,val_t> findFirst(const key_t& key) const;
  virtual BSTForwardIterator<key_t,val_t> findLast(const key_t& key) const;
  virtual BSTForwardIterator<key_t,val_t> remove(const BSTForwardIterator<key_t,val_t>& pos);
  
  
   
};

#include "BSTMultimap.tpp"

#endif
