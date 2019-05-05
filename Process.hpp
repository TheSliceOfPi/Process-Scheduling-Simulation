#ifndef PROCESS
#define PROCESS

//An abstract class representing a process
class Process
{
  protected:
   const int id;
   int cpuTime;
   int waitTime;

   //The time the process last started waiting for the CPU
   int lastTime;

  public:
   Process(int id);

   //An empty virtual destructor for the sake of inheritance
   virtual ~Process() { }
   
   //Returns the process' ID number
   virtual int getID() const;
   //Returns the total CPU time the process has used
   virtual int getCPUTime() const;
   //Returns the total amount of time the process was
   //ready to run (not blocked), but not running.
   //curCycleNum is the number of simulated cycles so far.
   virtual int getWaitTime(int curCycleNum) const;
   
   //Returns true if the process is blocked
   //curCycleNum is the number of simulated cycles so far.
   virtual bool isBlocked(int curCycleNum) const = 0;

   //Simulates giving the process sliceSize time on the CPU.
   //curCycleNum is the number of simulated cycles so far (used to
   //calculate wait time etc.) 
   //Returns the number of CPU cycles the process actually consumes.
   virtual int useCPU(int curCycleNum, int sliceSize) = 0;
};

//A concrete class representing a CPU-bound process
//(a process that uses all CPU time given to it)
class CPUBoundProcess : public Process
{
  public:
   CPUBoundProcess(int id);
   
   //Returns false...the process is never blocked
   virtual bool isBlocked(int curCycleNum) const;

   //Returns sliceSize...the process uses all the CPU time
   virtual int useCPU(int curCycleNum, int sliceSize);
};

//A concrete class representing an I/O-bound process
//(a process that frequently blocks to wait for I/O)
class IOBoundProcess : public Process
{
  protected:
   //The min/max CPU burst times
   const int minBurst;
   const int maxBurst;

   //The min/max I/O request times
   const int minIO;
   const int maxIO;

   //The time when the process will unblock
   int blockedUntil;
   //The amount of time remaining in the current CPU burst
   int remainingBurst;

  public:
   IOBoundProcess(int id);
   //The process may be blocked!
   virtual bool isBlocked(int curCycleNum) const;
   //The process may use less time than sliceSize
   //(if it blocks in the middle of the slice)
   virtual int useCPU(int curCycleNum, int sliceSize);
};

#endif
