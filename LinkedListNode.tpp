template <class item_t>
LinkedListNode<item_t>::LinkedListNode(LinkedListNode<item_t>* n, const item_t& i)
{
   next = n;
   item = i;
}

template <class item_t>
const item_t& LinkedListNode<item_t>::getItem() const
{
   return item;
}

template <class item_t>
void LinkedListNode<item_t>::setItem(const item_t& newItem)
{
   item = newItem;
}

template <class item_t>
LinkedListNode<item_t>* LinkedListNode<item_t>::getNext() const
{
   return next;
}

template <class item_t>
void LinkedListNode<item_t>::setNext(LinkedListNode<item_t>* newNext)
{
   next = newNext;
}

