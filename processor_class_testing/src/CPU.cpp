#include <iostream>
#include "cpu.h"
#include "process.h"
using namespace std;

CPU::CPU(int cs, int m)
{
  clock_speed = cs;
  memory = m;
  running_time = 0;
}

void CPU::insert_process(process p)
{
  queue.push_back(p);
  update_time();
}

void CPU::print_status()
{
  for(int i = 0; i < queue.size(); i++)
  {
    cout << "PID: " << queue[i].pid << endl;
    cout << "Cycles: " << queue[i].cycles << endl;
    cout << "Memory: " << queue[i].memory << endl;
  }
  cout << "Current Time: " << running_time << endl << endl;
}

void CPU::update_time()
{
  running_time += queue.back().cycles / clock_speed;
}
