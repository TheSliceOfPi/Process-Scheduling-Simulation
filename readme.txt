
Edith Flores
CPS222 Project 2

Files Submitted:
List.hpp
ArrayList.hpp
ArrayList.tpp
LinkedListNode.hpp
LinkedListNode.tpp
LinkedList.hpp
LinkedList.tpp
BSTNode.hpp
BSTNode.tpp
BSTMultimap.hpp
BSTMultimap.tpp
BSTForwardIterator.hpp
BSTForwardIterator.tpp
RBTNode.hpp
RBTNode.tpp
RBTMultimap.hpp
RBTMultimap.tpp
Process.hpp
Process.cpp
Scheduler.hpp
Scheduler.cpp
simulate.hpp
simulate.cpp
schedulesim.cpp
ArrayList_TEST.cpp
LinkedList_TEST.cpp
BSTNode_TEST.cpp
BSTMultimap_TEST.cpp
RBTNode_TEST.cpp
RBTMultimap_TEST.cpp
RoundRobin_TEST.cpp
CompletelyFair_TEST.cpp
catch.hpp
Makefile
timing.pdf
cputimes.pdf
readme.txt
Homework Cover Sheet Proj2.pdf


This project contains one main program with many components.
The command 'make all' will compile the entire project. Alternatively, you
may compile according to the directions below.

---schedulesim---
To compile: make schedulesim
To run: ./schedulesim <number of CPUBound Processes> <number of IOBound Processes> <number of Cycles>
Description:
schedulesim creates four different schedulers: RoundRobin, FastRoundRobin, CompletelyFair, and FastCompletelyFair. RoundRobin and FastRoundRobin following the roun robin shceduling strategy, while CompletelyFair and FastCompletelyFair following the completely fair scheduling strategy. schedulesim then calls simulate on each scheduler to determine the average runtime of the simulation ,average CPU time, and  Wait Time for CPU bounds and IO bound processes, in each Scheduler.

Known issues:
-None that I know of.
