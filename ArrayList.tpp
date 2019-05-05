
using namespace std;
template <class item_t>

ArrayList<item_t>:: ArrayList() //Empty Constructor w/ default capacity
{
size=0;
capacity=10;
items=new item_t[capacity];
}

template <class item_t>
ArrayList<item_t>:: ArrayList(int capacity) //Constructor w/ set capacity
{
size=0;
this->capacity=capacity;
items=new item_t[capacity];

}

template <class item_t>
ArrayList<item_t>:: ~ArrayList()//Destructor
{
delete[] items;
}


template <class item_t>
void ArrayList<item_t>::checkCapacity(int position)
{
	while(capacity<=position)
	{
	capacity=capacity*2;
	}
	item_t* temp= new item_t[capacity] ;
	for(int i=0;i<size;i++)
	{
		temp[i]=items[i];
	}
	delete items;
	items=temp;
	
}

template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item)
{
	checkCapacity(size);
	items[size]=item;
	size=size+1;
}

template <class item_t>
void ArrayList<item_t>::popBack()
{
	size=size-1;
}

template <class item_t>
const item_t& ArrayList<item_t>::getBack() const
{
	return items[size-1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item)
{
	checkCapacity(size);
	size=size+1;
	item_t set= item;
	for(int i=0; i<size; i++)
	{
		item_t current=items[i];
		items[i]=set;
		set=current;
	}
}

template <class item_t>
void ArrayList<item_t>::popFront()
{
	remove(0);
	
}

template <class item_t>
const item_t&  ArrayList<item_t>::getFront() const
{
	return items[0];	
}

template <class item_t>
const item_t&  ArrayList<item_t>::getItem(int index) const
{
	return items[index];
}


template <class item_t>
void ArrayList<item_t>::setItem(int index,const item_t& item)
{
	items[index]=item;
	
}

template <class item_t>
void ArrayList<item_t>::insert(int index,const item_t& item)
{
	checkCapacity(size);
	size=size+1;
	item_t set= item;
	for(int i=index; i<size; i++)
	{
		item_t current=items[i];
		items[i]=set;
		set=current;
	}
	
}

template <class item_t>
void ArrayList<item_t>::remove(int index)
{
	item_t current=items[size-1];
	for(int i=size-1; i>index; i--)
	{
		item_t prev=items[i-1];
		items[i-1]=current;
		current=prev;
	}
	size=size-1;
	
}

template <class item_t>
int ArrayList<item_t>::getSize() const
{
	return size;
	
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const
{
	if(size==0)
	{
		return true;
	}
	return false;
	
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const
{
	return capacity;
	
}









