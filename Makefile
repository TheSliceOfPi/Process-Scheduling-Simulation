OPTS= -Wall -std=c++11 -g

all:  schedulesim 

tests: ArrayList_TEST RoundRobin_TEST LinkedList_TEST BSTNode_TEST BSTMultimap_TEST CompletelyFair_TEST RBTNode_TEST RBTMultimap_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp catch.hpp List.hpp
	g++ ${OPTS} --coverage -o ArrayList_TEST ArrayList_TEST.cpp
	
RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.o catch.hpp ArrayList.tpp ArrayList.hpp Process.o
	g++ ${OPTS} --coverage -o RoundRobin_TEST RoundRobin_TEST.cpp Scheduler.o Process.o
	
Scheduler.o: Scheduler.cpp Scheduler.hpp Process.o
	g++ ${OPTS} -c Scheduler.cpp 
	
Process.o: Process.hpp Process.cpp 
	g++ ${OPTS} -c Process.cpp

simulate.o: simulate.hpp simulate.cpp Scheduler.o
	g++ ${OPTS} -c simulate.cpp 

schedulesim: schedulesim.cpp simulate.o Process.o Scheduler.o
	g++ ${OPTS} --coverage -o schedulesim schedulesim.cpp simulate.o Process.o Scheduler.o


LinkedList_TEST: LinkedList_TEST.cpp  LinkedList.hpp LinkedList.tpp List.hpp LinkedListNode.hpp catch.hpp 
	g++ ${OPTS} --coverage -o LinkedList_TEST LinkedList_TEST.cpp 
	
BSTNode_TEST: BSTNode_TEST.cpp  BSTNode.hpp BSTNode.tpp catch.hpp 
	g++ ${OPTS} --coverage -o BSTNode_TEST BSTNode_TEST.cpp 
	
BSTMultimap_TEST: BSTMultimap_TEST.cpp  BSTForwardIterator.hpp BSTForwardIterator.tpp BSTMultimap.hpp BSTMultimap.tpp catch.hpp 
	g++ ${OPTS} --coverage -o BSTMultimap_TEST BSTMultimap_TEST.cpp 

CompletelyFair_TEST: CompletelyFair_TEST.cpp  Scheduler.o BSTForwardIterator.tpp BSTForwardIterator.hpp BSTMultimap.hpp BSTMultimap.tpp catch.hpp Process.o
	g++ ${OPTS} --coverage -o CompletelyFair_TEST CompletelyFair_TEST.cpp Scheduler.o Process.o

RBTNode_TEST: RBTNode_TEST.cpp  RBTNode.hpp RBTNode.tpp catch.hpp 
	g++ ${OPTS} --coverage -o RBTNode_TEST RBTNode_TEST.cpp 
	
RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTMultimap.tpp catch.hpp 
	g++ ${OPTS} --coverage -o RBTMultimap_TEST RBTMultimap_TEST.cpp 
