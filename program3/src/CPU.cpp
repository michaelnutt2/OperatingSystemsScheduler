#include <iostream>
#include "cpu.h"
#include "process.h"
using namespace std;

CPU::CPU(int cs, int m)
{
  clock_speed = cs;
  memory = m;
  running_time = 0.0;
}

void CPU::insert_process(process p)
{
  queue.push_back(p);
  update_time();
}

void CPU::print_status()
{
  cout << "Current Time: " << running_time << endl;
}

void CPU::update_time()
{
  running_time += queue.back().cycles / clock_speed;
}

double CPU::get_time()
{
  return running_time;
}
