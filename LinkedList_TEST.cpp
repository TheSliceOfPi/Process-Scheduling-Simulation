#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include "LinkedList.hpp"
using namespace std;
TEST_CASE("Testing LinkedList functions")
{
  SECTION("Testing LinkedList Constructor")
    {
		LinkedList<int> empty=LinkedList<int>();
		REQUIRE(empty.getSize()==0);
		REQUIRE(empty.isEmpty()==true);
		empty.pushBack(7);
		REQUIRE(empty.getSize()==1);
		empty.pushBack(8);
		REQUIRE(empty.getSize()==2);
		REQUIRE(empty.getBack()==8);
		empty.pushFront(76);
		REQUIRE(empty.getFront()==76);
		empty.popFront(); 
		REQUIRE(empty.getFront()==7);
		empty.pushFront(76);
		empty.pushFront(77);
		empty.pushFront(89);
		empty.pushBack(80);
		REQUIRE(empty.getItem(0)==89);
		empty.setItem(1,98);
		REQUIRE(empty.getItem(0)==89);
		REQUIRE(empty.getItem(1)==98);
		REQUIRE(empty.getItem(2)==76);
		REQUIRE(empty.getItem(5)==80);
		empty.insert(0,677);
		REQUIRE(empty.getItem(0)==677);
		REQUIRE(empty.getItem(1)==89);
		empty.insert(1,688);
		REQUIRE(empty.getItem(1)==688);
		REQUIRE(empty.getItem(2)==89);
		empty.insert(4,57);
		REQUIRE(empty.getItem(3)==98);
		REQUIRE(empty.getItem(4)==57);
		REQUIRE(empty.getItem(5)==76);
		empty.remove(4);
		REQUIRE(empty.getItem(3)==98);
		REQUIRE(empty.getItem(4)==76);
		REQUIRE(empty.getItem(5)==7);
		empty.remove(0);
		REQUIRE(empty.getItem(0)==688);
		REQUIRE(empty.getItem(3)==76);
		REQUIRE(empty.getItem(4)==7);
		empty.popBack(); 
		REQUIRE(empty.getBack()==8);
		empty.popBack();
		empty.setItem(0,57);
		empty.setItem(2,57);
		REQUIRE(empty.getBack()==7);
		empty.popBack();
		REQUIRE(empty.isEmpty()==false);
		empty.popBack();
		empty.popBack();
		empty.popBack();
		empty.popBack();
		REQUIRE(empty.getSize()==0);
		empty.popBack();
		REQUIRE(empty.isEmpty()==true);
		empty.pushFront(76);
		empty.pushFront(77);
		empty.pushFront(89);
		empty.popFront(); 
		empty.insert(0,57);
		empty.setItem(0,97);
		empty.insert(empty.getSize(),890);
		REQUIRE(empty.isEmpty()==false);
		empty.remove(empty.getSize()-1);
		
		
		
		
    }
}
