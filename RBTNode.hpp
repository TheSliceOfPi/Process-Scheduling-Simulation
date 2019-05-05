#ifndef RBT_NODE
#define RBT_NODE

#include "BSTNode.hpp"

template <class key_t, class val_t>
class RBTNode : public BSTNode<key_t, val_t>
{
  protected:
   bool red;

  public:
   //Children, parent initialized to zero
   RBTNode(const key_t& key, const val_t& value, bool color);

   RBTNode<key_t, val_t>* getParent() const;
   RBTNode<key_t, val_t>* getLeftChild() const;
   RBTNode<key_t, val_t>* getRightChild() const;

   virtual void setIsRed(bool newIsRed);
   virtual bool isRed() const;
};

#include "RBTNode.tpp"

#endif
