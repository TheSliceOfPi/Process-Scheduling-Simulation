#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "BSTNode.hpp" 

TEST_CASE("Testing BSTNodefunctions")
{
  SECTION("Testing BSTNode")
    {
      BSTNode<char,int> newBST= BSTNode<char,int>('7',8);
      int value=newBST.getValue();
      REQUIRE(value==8);
      newBST.setValue(78);
      value=newBST.getValue();
      REQUIRE(value==78);
      char key=newBST.getKey();
      REQUIRE(key=='7');
      newBST.setKey('y');
      key=newBST.getKey();
      REQUIRE(key=='y');
      BSTNode<char,int>* initRightBST=newBST.getRightChild();
      REQUIRE(initRightBST==0);
      BSTNode<char,int>* initLeftBST=newBST.getLeftChild();
      REQUIRE(initLeftBST==0);
      BSTNode<char,int> leftBST= BSTNode<char,int>('l',90);
      BSTNode<char,int> rightBST= BSTNode<char,int>('r',91);
      newBST.setLeftChild(&leftBST);
      newBST.setRightChild(&rightBST);
      initRightBST=newBST.getRightChild();
      int rightValue=(*initRightBST).getValue();
      char rightKey=(*initRightBST).getKey();
      REQUIRE(rightKey=='r');
      REQUIRE(rightValue==91);
      
      initLeftBST=newBST.getLeftChild();
      int leftValue=(*initLeftBST).getValue();
      char leftKey=(*initLeftBST).getKey();
      REQUIRE(leftKey=='l');
      REQUIRE(leftValue==90);
      
      BSTNode<char,int>* initParentBST=newBST.getParent();
      REQUIRE(initParentBST==0);
      BSTNode<char,int> ParentBST= BSTNode<char,int>('p',89);
      newBST.setParent(&ParentBST);
      initParentBST=newBST.getParent();
      int ParentValue=(*initParentBST).getValue();
      char ParentKey=(*initParentBST).getKey();
       REQUIRE(ParentKey=='p');
      REQUIRE(ParentValue==89);
      
      
    }
}
