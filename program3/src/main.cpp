#include <iostream>
#include <stdio.h>
#include "process.h"
#include "cpu.h"
using namespace std;

int fifo(vector<process> queue);
int sjf(vector<process> queue);
int msjf(vector<process> queue);

int main(int argc, char **argv)
{
  if(argc < 2)
  {
    cout << "Usage: ./program3 [file]\n";
    return 0;
  }
  // Variables
  vector<process> queue;        // Processor queue
  process p;                    // Temp processor holder
  FILE *f;                      // Input file variable

  f = fopen(argv[1], "r");

  for(int i = 0; i < 200; i++)
  {
    fscanf(f, "%i %i %i", &p.pid, &p.cycles, &p.memory);
    queue.push_back(p);
  }
  fclose(f);

  cout << "FIFO: " << fifo(queue) << endl;
  cout << "SJF: " << sjf(queue) << endl;
  cout << "MSJF: " << msjf(queue) << endl;

  return 0;
}

int fifo(vector<process> queue)
{
  return 0;
}

int sjf(vector<process> queue)
{
  return 0;
}

int msjf(vector<process> queue)
{
  return 0;
}
