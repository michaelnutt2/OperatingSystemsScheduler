#ifndef PROCESS_H_
#define PROCESS_H_

struct process
{
  int pid;
  int cycles;
  int memory;
  int t_arrive;
  int t_complete;
};

#endif
