#include <iostream>
#include "Scheduler.hpp"
using namespace std;

RoundRobin::RoundRobin()
{
	ArrayList<Process*>* empty=new ArrayList<Process*>(); //Create the Array List
	procQueue=empty;
}
RoundRobin::~RoundRobin()
{
	delete procQueue;
}
void RoundRobin::addProcess(Process* proc)
{
	
	(*procQueue).pushBack(proc);
}

Process* RoundRobin::popNext(int curCycle)
{
	Process* front=(*procQueue).getFront();
	for (int i=0; i<(*procQueue).getSize();i++)
	{
			if ((*front).isBlocked(curCycle)==false)
			{
				(*procQueue).popFront();
				return front;
			}
			(*procQueue).popFront();
			(*procQueue).pushBack(front);
			front=(*procQueue).getFront();	
	}
	return 0;
}
FastRoundRobin::FastRoundRobin():RoundRobin()
{
	delete procQueue;
	LinkedList<Process*>* newList= new LinkedList<Process*>();
	procQueue=newList;
	
}

CompletelyFair::CompletelyFair()
{
	BSTMultimap<int,Process*>* empty=new BSTMultimap<int,Process*>();
	procTree=empty;	
}
CompletelyFair::~CompletelyFair()
{
	delete procTree;
}
void CompletelyFair::addProcess(Process* proc)
{
	procTree->insert(proc->getCPUTime(),proc);
}

Process* CompletelyFair::popNext(int curCycle)
{
	BSTForwardIterator< int,Process*> iter=procTree->getMin();
	while(iter.isPastEnd()==false)
	{
		if(iter.getValue()->isBlocked(curCycle)==false)
		{
			Process* copy=iter.getValue();
			iter=procTree->remove(iter);
			return copy;
		}
	iter.next();
	}
	return 0;
}
FastCompletelyFair::FastCompletelyFair():CompletelyFair()
{
	delete procTree;
	RBTMultimap<int,Process*>* empty=new RBTMultimap<int,Process*>();
	procTree=empty;	
	
}
