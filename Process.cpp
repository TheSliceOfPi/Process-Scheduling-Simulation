#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}
//Takes: No parameters
//Effects:N/A
//Return: int, id that represents the process
int Process::getID() const
{
   return id;
}
//Takes: No parameters
//Effects:N/A
//Return: int that represents the amount of time the CPU had been u
int Process::getCPUTime() const
{
   return cpuTime;
}
//Takes: curCycleNum,The number of Cycles that has occured
//Effects:N/A
//Return: Amount of time the process has been waiting to be use
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

CPUBoundProcess::CPUBoundProcess(int id) : Process(id) //Constructor for CPUBoundProcess
{
   lastTime = 0;
}
//Takes:curCycleNum,The number of Cycles that has occured
//Effects:N/A
//Return: bool, whether the process is "blocked" or stuck waiting for I/O. Always False since this is for IOBoundProce
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}
//Takes:curCycleNum,The number of Cycles that has occured. sliceSize,the number of cycles that is allowed to be runned
//Effects:Update cputTime and waitTime.
//Return: int, the sliceSize since it uses it all
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200) //Constructor
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}
//Takes:curCycleNum,The number of Cycles that has occured.
//Effects:N/A
//Return:bool, whether the process is "blocked" or stuck waiting for I/O
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

//Takes:curCycleNum,The number of Cycles that has occured. sliceSize,the number of cycles that is allowed to be runned
//Effects:Update remainingBurst, waitTime,lastTime, blockedUntil
//Return:int, the amount of time used
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
