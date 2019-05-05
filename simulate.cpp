#include "simulate.hpp"
#include <chrono>
#include <iostream>
using namespace std;
double* simulate(Scheduler* sched, int numCPUBound,int numIOBound, int numCycles)
{
	CPUBoundProcess* accCPU[numCPUBound];
	IOBoundProcess* accIO[numIOBound];
	for(int j=0;j<numCPUBound;j++)//ID starts at 0 and goes up to numCPUBound (exclusive)
	{
		CPUBoundProcess* temp= new CPUBoundProcess(j);
		(*sched).addProcess(temp);
		accCPU[j]=temp; 
		
	}
	for(int k=numCPUBound;k<(numIOBound+numCPUBound);k++) //ID for IO starts at numCPUBound
	{
		IOBoundProcess* temp= new IOBoundProcess(k);
		(*sched).addProcess(temp);
		accIO[k]=temp;
	}
		
	double numUsed=0; //numTime popNext is used
	double simCycles=0;
	double CPUTime=0;
	double CPUWait=0;
	double IOTime=0;
	double IOWait=0;
	
	auto t1=chrono::system_clock::now();
	for(int i=0;simCycles<=numCycles;i++)
	{
		Process* nextProc=(*sched).popNext(simCycles);  //Get the next process on procQueue
		numUsed=numUsed+1;
		if(nextProc==NULL)
		{
			simCycles=simCycles+10;
		}
		
		else
		{
		simCycles=simCycles+(*nextProc).useCPU(simCycles,10);
		(*sched).addProcess(nextProc); //Put process back to procQueue
		} 
	}
	auto t2=chrono::system_clock::now();
	auto dur=t2-t1;
	auto durNS=chrono::duration_cast<chrono::nanoseconds>(dur);
	double elapsed=durNS.count();
	
	for(int p=0;p<numCPUBound;p++)//ID starts at 0 and goes up to numCPUBound (exclusive)
	{
		CPUTime=CPUTime+accCPU[p]->getCPUTime();
		CPUWait=CPUWait+accCPU[p]->getWaitTime(simCycles);
		
	}
	for(int l=numCPUBound;l<(numIOBound+numCPUBound);l++) //ID for IO starts at numCPUBound
	{
		IOTime=IOTime+accIO[l]->getCPUTime();
		IOWait=IOWait+accIO[l]->getWaitTime(simCycles);
	}
	
	double* DArray= new double[5];
	DArray[0]=(float)elapsed/(float)numUsed;
	DArray[1]=(float)CPUTime/(float)numCPUBound;
	DArray[2]=(float)CPUWait/(float)numCPUBound;
	DArray[3]=(float)IOTime/(float)numIOBound;
	DArray[4]=(float)IOWait/(float)numIOBound;
	return DArray;
		

}
