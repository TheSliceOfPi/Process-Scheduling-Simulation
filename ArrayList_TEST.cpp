#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "ArrayList.hpp" 

TEST_CASE("Testing ArrayList functions")
{
  SECTION("Testing ArrayLists")
    {
      ArrayList<int> empty=ArrayList<int>();
      ArrayList<int> wCap=ArrayList<int>(7);
      wCap.pushBack(42);
      wCap.pushBack(56);
      wCap.pushBack(59);
      wCap.pushBack(4);
      wCap.pushBack(7);
      REQUIRE(wCap.getBack()==7);
      wCap.pushFront(54);
      wCap.pushFront(5);
      wCap.pushFront(78);
      wCap.popFront();
      REQUIRE(wCap.getFront()==5);
      REQUIRE(wCap.getItem(0)==5);
      REQUIRE(wCap.getItem(6)==7);
      wCap.setItem(5,10);
      REQUIRE(wCap.getItem(5)==10);
      wCap.insert(5,18);
      REQUIRE(wCap.getItem(5)==18);
      REQUIRE(wCap.getItem(6)==10);
      wCap.remove(5);
      REQUIRE(wCap.getItem(5)==10);
      REQUIRE(wCap.getCapacity()==14);
      REQUIRE(wCap.getSize()==7);
      REQUIRE(wCap.isEmpty()==false);
      REQUIRE(empty.isEmpty()==true);
      wCap.popBack();
      REQUIRE(wCap.getBack()==10);
      
      
    }
}
