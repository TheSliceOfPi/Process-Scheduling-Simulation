#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "RBTMultimap.hpp" 
TEST_CASE("Testing RBTMultimap functions")
{
  SECTION("Testing RBTMultimap")
    {
      RBTMultimap<int,char> newTree= RBTMultimap<int,char>();
      newTree.insert(0,'7');
      newTree.insert(1,'7');
      newTree.insert(2,'7');
      newTree.insert(3,'8');
      newTree.insert(4,'8');
      newTree.insert(5,'8');
      newTree.insert(6,'8');
      newTree.insert(7,'8');
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.remove(newTree.getMin());
      newTree.clear();
      newTree.insert(3,'8');
      newTree.insert(4,'8');
      newTree.insert(5,'8');
      newTree.insert(6,'8');
      newTree.insert(7,'8');
      newTree.clear();
      newTree.insert(13,'a');
      newTree.insert(10,'q');
      newTree.insert(15,'a');
      newTree.insert(2,'q');
      newTree.insert(13,'a');
      newTree.insert(7,'q');
      newTree.remove(newTree.findFirst(15));
      newTree.insert(1,'a');
      newTree.insert(6,'q');
      newTree.insert(9,'q');
      newTree.insert(6,'q');
      newTree.insert(8,'q');
      newTree.insert(11,'q');
     newTree.remove(newTree.findFirst(7));
     //newTree.clear();
     newTree.insert(6,'q');
     newTree.remove(newTree.findFirst(6));
     newTree.remove(newTree.findFirst(8));
      newTree.insert(5,'7');
      newTree.insert(3,'7');
      newTree.insert(12,'7');
      newTree.remove(newTree.findFirst(5));
      newTree.remove(newTree.findFirst(1));
      newTree.remove(newTree.findFirst(13));
      newTree.remove(newTree.findFirst(2));
      REQUIRE(newTree.findFirst(12).getValue()=='7');
     
      newTree.printDOT("rbtree.dot"); 
    
    }
   
}
  
