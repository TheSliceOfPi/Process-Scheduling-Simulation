#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Scheduler.hpp" 

TEST_CASE("Testing CompletelyFair functions")
{
  SECTION("Testing CompletelyFair")
    {
     CompletelyFair empty=CompletelyFair();
     CPUBoundProcess proc=CPUBoundProcess(75); //A Process
		CPUBoundProcess proc1=CPUBoundProcess(78);
		REQUIRE(proc.getID()==75);
		Process* procRef=&proc; //Pointer to Process
		REQUIRE((*procRef).getID()==75);
		REQUIRE(proc1.getID()==78);
		Process* procRef1=&proc1; //Pointer to Process
		REQUIRE((*procRef1).getID()==78);
		
		empty.addProcess(procRef1);// Adds pointer to BST
		empty.addProcess(procRef);// Adds pointer to BST
		REQUIRE(empty.popNext(3)==procRef1);
		REQUIRE(empty.popNext(3)==procRef);
		
		CompletelyFair emptyIO= CompletelyFair(); //Empty BTS
		IOBoundProcess procIO=IOBoundProcess(789); //A Process
		IOBoundProcess procIO1=IOBoundProcess(78);
		REQUIRE(procIO.getID()==789);
		Process* procRefIO=&procIO; //Pointer to Process
		REQUIRE((*procRefIO).getID()==789);
		REQUIRE(procIO1.getID()==78);
		Process* procRef1IO=&procIO1; //Pointer to Process
		REQUIRE((*procRef1IO).getID()==78);
		
		emptyIO.addProcess(procRef1IO);// Adds pointer to BTS
		emptyIO.addProcess(procRefIO);// Adds pointer to BTS
		REQUIRE(emptyIO.popNext(3)==procRef1IO);
		
		FastCompletelyFair emptyFCF=FastCompletelyFair();
		emptyFCF.addProcess(procRef1);// Adds pointer to BST
		emptyFCF.addProcess(procRef);// Adds pointer to BST
		REQUIRE(emptyFCF.popNext(3)==procRef1);
		REQUIRE(emptyFCF.popNext(3)==procRef);
		
      
    }
}
