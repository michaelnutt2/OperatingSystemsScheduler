#include <vector>
#include "process.h"
using namespace std;

#ifndef CPU_H_
#define CPU_H_

class CPU
{
private:
  vector<process> queue;
  int clock_speed;
  int memory;
  int running_time;
  int turnaround_time;
  // Updates running time and turnaround time per process
  // called by insert_process
  void update_time();
public:
  // Constructor, takes clock speed and memory
  CPU(int, int);
  // Adds process to the queue, needs the process structure
  void insert_process(process);
  // Prints current data in the object -- for testing purposes
  void print_status();
  // Returns running_time
  int get_time();
};

#endif
