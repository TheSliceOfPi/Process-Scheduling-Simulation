#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Scheduler.hpp"

TEST_CASE("Testing RoundRobin functions")
{
  SECTION("Testing RoundRobin Constructor")
    {
		RoundRobin empty= RoundRobin(); //Empty ArrayList<Process*>
		
		CPUBoundProcess proc=CPUBoundProcess(75); //A Process
		CPUBoundProcess proc1=CPUBoundProcess(78);
		REQUIRE(proc.getID()==75);
		Process* procRef=&proc; //Pointer to Process
		REQUIRE((*procRef).getID()==75);
		REQUIRE(proc1.getID()==78);
		Process* procRef1=&proc1; //Pointer to Process
		REQUIRE((*procRef1).getID()==78);
		
		empty.addProcess(procRef1);// Adds pointer to ArrayList
		empty.addProcess(procRef);// Adds pointer to ArrayList
		REQUIRE(empty.popNext(3)==procRef1);
		
		RoundRobin emptyIO= RoundRobin(); //Empty ArrayList<Process*>
		IOBoundProcess procIO=IOBoundProcess(789); //A Process
		IOBoundProcess procIO1=IOBoundProcess(78);
		REQUIRE(procIO.getID()==789);
		Process* procRefIO=&procIO; //Pointer to Process
		REQUIRE((*procRefIO).getID()==789);
		REQUIRE(procIO1.getID()==78);
		Process* procRef1IO=&procIO1; //Pointer to Process
		REQUIRE((*procRef1IO).getID()==78);
		
		emptyIO.addProcess(procRef1IO);// Adds pointer to ArrayList
		emptyIO.addProcess(procRefIO);// Adds pointer to ArrayList
		REQUIRE(emptyIO.popNext(3)==procRef1IO); 
		REQUIRE(emptyIO.popNext(-3)==0); 
		
		FastRoundRobin testing=FastRoundRobin();
		
		emptyIO.addProcess(procRef1IO);
		emptyIO.addProcess(procRefIO);
    }
}
