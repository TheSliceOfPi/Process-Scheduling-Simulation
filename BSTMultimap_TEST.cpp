#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "BSTMultimap.hpp" 
#include "BSTForwardIterator.hpp"
TEST_CASE("Testing BSTMultimap functions")
{
  SECTION("Testing BSTMultimap")
    {
      BSTMultimap<int,char> newTree= BSTMultimap<int,char>();
      int size=newTree.getSize();
      REQUIRE(size==0);
      newTree.clear();
      bool emptied=newTree.isEmpty();
      REQUIRE(emptied==true);
	BSTForwardIterator< int, char> iter=newTree.getMin();
	BSTForwardIterator< int, char> iterMax=newTree.getMax();
      
      newTree.insert(7,'8');
      size=newTree.getSize();
      REQUIRE(size==1);
      emptied=newTree.isEmpty();
      REQUIRE(emptied==false);
      
      newTree.insert(9,'7');
      size=newTree.getSize();
      REQUIRE(size==2);
      emptied=newTree.isEmpty();
      REQUIRE(emptied==false);
      
      newTree.insert(2,'3');
      size=newTree.getSize();
      REQUIRE(size==3);
      emptied=newTree.isEmpty();
      REQUIRE(emptied==false);
      
      newTree.insert(8,'6');
      size=newTree.getSize();
      REQUIRE(size==4);
      emptied=newTree.isEmpty();
      REQUIRE(emptied==false);
      newTree.insert(1,'q');
      newTree.insert(5,'a');
      newTree.insert(2,'p');
      REQUIRE(newTree.contains(7)==true);
      REQUIRE(newTree.contains(10)==false);
      REQUIRE(newTree.contains(8)==true);
      //cout<<newTree.toString()<<endl;
      
      iter=newTree.getMin();
      REQUIRE(iter.isPastEnd()==false);
      REQUIRE(iter.getKey()==1);
		iter.next();
      REQUIRE(iter.getKey()==2);
      iter.next();
      REQUIRE(iter.getKey()==2);
      iter.next();//5
      iter.next();//7
      iter.next();//8
      REQUIRE(iter.getKey()==8);
      iter.next();
      iter.next();
      
      iterMax=newTree.getMax();
      REQUIRE(iterMax.getKey()==9);
      
      BSTForwardIterator< int, char> iterSpec=newTree.findFirst(8);
      REQUIRE(iterSpec.getKey()==8);
      iterSpec.next();
      REQUIRE(iterSpec.getKey()==9);
      BSTForwardIterator< int, char> iterSpec2=newTree.findFirst(13);
      REQUIRE(iterSpec2.isPastEnd()==true);
      BSTForwardIterator< int, char> iterSpec3=newTree.findLast(2);
      REQUIRE(iterSpec3.getValue()=='p');
      BSTForwardIterator< int, char> iterSpec4=newTree.findFirst(2);
      REQUIRE(iterSpec4.getValue()=='3');
      //cout<<newTree.toString()<<endl;
      BSTForwardIterator< int, char> iterSpec5=newTree.remove(newTree.getMin());
      REQUIRE(iterSpec5.getKey()==2);
      //cout<<newTree.toString()<<endl;
      BSTForwardIterator< int, char> iterSpec6=newTree.remove(newTree.getMin());
      REQUIRE(iterSpec6.getKey()==2);
      //cout<<newTree.toString()<<endl;
       newTree.insert(9,'q');
      newTree.insert(5,'a');
      iterSpec6=newTree.remove(newTree.findFirst(9));
      //cout<<newTree.toString()<<endl;
      newTree.insert(13,'a');
      newTree.insert(3,'q');
      //cout<<newTree.toString()<<endl;
      iterSpec4=newTree.findFirst(5);
      REQUIRE(iterSpec3.getValue()=='p');
      iterSpec6=newTree.remove(newTree.findFirst(5));
      //cout<<newTree.toString()<<endl;
      newTree.clear();
      newTree.insert(13,'a');
      newTree.insert(10,'q');
      newTree.insert(15,'a');
      newTree.insert(2,'q');
      newTree.insert(13,'a');
      newTree.insert(7,'q');
      //cout<<newTree.toString()<<endl;
      iterSpec6=newTree.remove(newTree.findFirst(15));
       //cout<<newTree.toString()<<endl;
       newTree.insert(1,'a');
      newTree.insert(6,'q');
      newTree.insert(9,'q');
      newTree.insert(6,'q');
      newTree.insert(8,'q');
      newTree.insert(11,'q');
      //cout<<newTree.toString()<<endl;
     iterSpec6=newTree.remove(newTree.findFirst(7));
     //cout<<newTree.toString()<<endl;
     newTree.clear();
     newTree.insert(6,'q');
     iterSpec6=newTree.remove(newTree.findFirst(6));
     
      
      
    }
   
}
