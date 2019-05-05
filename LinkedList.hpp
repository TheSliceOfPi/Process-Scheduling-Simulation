#ifndef LINKED_LIST
#define LINKED_LIST
#include "List.hpp"
#include "LinkedListNode.hpp"
template <class item_t>
class LinkedList: public List<item_t>
{
  protected:
   LinkedListNode<item_t>* head;
   LinkedListNode<item_t>* tail;
   int size;

  public:
   LinkedList();
   ~LinkedList();
  //Pushes item to the back of the list
   virtual void pushBack(const item_t& item);
   //Removes, but does not return, the last item
   virtual void popBack();
   //Returns a reference to the last item (does not remove it).
   virtual const item_t& getBack() const;
   
   //Pushes item to the front of the list
   virtual void pushFront(const item_t& item);
   //Removes, but does not return, the first item
   virtual void popFront();
   //Returns a reference to the first item (does not remove it).
   virtual const item_t& getFront() const ;

   //Returns a reference to the item at the given index
   virtual const item_t& getItem(int index) const;
   //Sets the item at the given index
   virtual void setItem(int index, const item_t& item);

   //Inserts the given item at the given index
   //(items at index or beyond shift up one position)
   virtual void insert(int index, const item_t& item);
   //Removes the item at the given index
   //(items beyond index shift down one position)
   virtual void remove(int index);

   //Returns the number of items in the list
   virtual int getSize() const ;
   //Returns true if the list is empty (false otherwise)
   virtual bool isEmpty() const ;
};

#include "LinkedList.tpp"

#endif
