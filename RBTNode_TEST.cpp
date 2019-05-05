#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "RBTNode.hpp"

TEST_CASE("Testing RBTNode functions")
{
  SECTION("Testing RBTNode Constructor")
    {
		RBTNode<char,int> newRBT= RBTNode<char,int>('7',8,false);
		RBTNode<char,int>* left= new RBTNode<char,int>('7',8,false);
		RBTNode<char,int>* right= new RBTNode<char,int>('7',8,false);
		RBTNode<char,int>* parent= new RBTNode<char,int>('7',8,false);
		REQUIRE(newRBT.isRed()==false);
		newRBT.setIsRed(true);
		REQUIRE(newRBT.isRed()==true);
		REQUIRE(newRBT.getParent()==0);
		REQUIRE(newRBT.getLeftChild()==0);
		REQUIRE(newRBT.getRightChild()==0);
		newRBT.setValue(4);
		REQUIRE(newRBT.getValue()==4);
		newRBT.setParent(parent);
		newRBT.setLeftChild(left);
		newRBT.setRightChild(right);
		newRBT.setKey('8');
		REQUIRE(newRBT.getKey()=='8');
		
		
		
		
    }
}
