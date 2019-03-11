#include <vector>
#include "process.h"
using namespace std;

#ifndef CPU_H_
#define CPU_H_

class CPU
{
private:
  vector<process> queue;
  long long int clock_speed;

  double running_time;
  // Updates running time
  // called by insert_process
  void update_time();
public:
  long long int memory;
  // Constructor, takes clock speed and memory
  CPU(long long int, long long int);
  // Adds process to the queue, needs the process structure
  void insert_process(process);
  // Prints current data in the object -- for testing purposes
  void print_status();
  // Returns running_time
  double get_time();
};

#endif
