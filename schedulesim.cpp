#include <iostream>
#include "simulate.hpp"

using namespace std;
int main(int argc, char** argv)
{
	int numCPUBoundProc=atoi(argv[1]);
	int numIOBoundProc=atoi(argv[2]); 
	int numCyclesSim=atoi(argv[3]);
	RoundRobin RRScheduler=RoundRobin();
	FastRoundRobin FRRScheduler=FastRoundRobin();
	CompletelyFair CFScheduler=CompletelyFair();
	FastCompletelyFair FCFScheduler=FastCompletelyFair();
	Scheduler* arr[4];
	arr[0]=&RRScheduler;
	arr[1]=&FRRScheduler;
	arr[2]=&CFScheduler;
	arr[3]=&FCFScheduler;
	string info[4]={"RoundRobin","FastRoundRobin","CompletelyFair","FastCompletelyFair"};
	for(int i=0;i<4;i++)
	{
	double* results=simulate(arr[i],numCPUBoundProc,numIOBoundProc,numCyclesSim);
	
	cout<<"----------Statistics------------"<<info[i]<<endl;
	cout<<"Duration: "<< results[0] <<" Ns "<<endl;
	cout<<"Avg CPU time (CPUBound): "<<results[1]<<endl;
	cout<<"Avg wait Time{CPUBound): "<<results[2]<<endl;
	cout<<"Avg CPU time (IOBound): "<<results[3]<<endl;
	cout<< "Avg wait Time{IOBound): "<<results[4]<<endl;
	delete results;
	}
}
