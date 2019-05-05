#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

template <class item_t>
class LinkedListNode
{
  private:
   LinkedListNode<item_t>* next;
   item_t item;

  public:
   LinkedListNode(LinkedListNode<item_t>* next, const item_t& item);

   const item_t& getItem() const;
   void setItem(const item_t& newItem);

   LinkedListNode<item_t>* getNext() const;
   void setNext(LinkedListNode<item_t>* newNext);
};

#include "LinkedListNode.tpp"

#endif
