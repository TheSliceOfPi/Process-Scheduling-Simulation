#ifndef LIST_H
#define LIST_H

template <class item_t>
class List
{
  public:
   //An empty virtual destructor for the sake of inheritance
   virtual ~List() { }

   //Pushes item to the back of the list
   virtual void pushBack(const item_t& item) = 0;
   //Removes, but does not return, the last item
  virtual void popBack() = 0;
   //Returns a reference to the last item (does not remove it).
   virtual const item_t& getBack() const = 0;
   
   //Pushes item to the front of the list
   virtual void pushFront(const item_t& item) = 0;
   //Removes, but does not return, the first item
   virtual void popFront() = 0;
   //Returns a reference to the first item (does not remove it).
   virtual const item_t& getFront() const = 0;

   //Returns a reference to the item at the given index
   virtual const item_t& getItem(int index) const = 0;
   //Sets the item at the given index
   virtual void setItem(int index, const item_t& item) = 0;

   //Inserts the given item at the given index
   //(items at index or beyond shift up one position)
   virtual void insert(int index, const item_t& item) = 0;
   //Removes the item at the given index
   //(items beyond index shift down one position)
   virtual void remove(int index) = 0;

   //Returns the number of items in the list
   virtual int getSize() const = 0;
   //Returns true if the list is empty (false otherwise)
   virtual bool isEmpty() const = 0;
};

#endif
