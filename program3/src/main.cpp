#include <iostream>
#include <stdio.h>
#include "process.h"
#include "cpu.h"
using namespace std;

double fifo(vector<process> queue);
double sjf(vector<process> queue);
double msjf(vector<process> queue);
void merge(vector<process> *v, process l, process m, process r);
void mergeSort(vector<process> *v, process l, process r);

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
    fscanf(f, "%i %lld %lld", &p.pid, &p.cycles, &p.memory);
    queue.push_back(p);
  }
  fclose(f);

  cout << "FIFO: " << fifo(queue) << " s" << endl;
  cout << "SJF: " << sjf(queue) << " s" << endl;
  cout << "MSJF: " << msjf(queue) << " s" << endl << endl;

  return 0;
}

double fifo(vector<process> queue)
{
  CPU pA(2000000000, 1);
  CPU pB(2000000000, 1);
  CPU pC(3000000000, 1);
  CPU pD(3000000000, 1);
  CPU pE(4000000000, 1);

  double current_time = 0;

  for(int i = 0; i < 200; i++)
  {
    if(pA.get_time() <= current_time)
    {
      pA.insert_process(queue[i]);
      i++;
      if(pA.get_time() > current_time)
        current_time = pA.get_time();
    }

    if(pB.get_time() <= current_time)
    {
      pB.insert_process(queue[i]);
      i++;
      if(pB.get_time() > current_time)
        current_time = pB.get_time();
    }

    if(pC.get_time() <= current_time)
    {
      pC.insert_process(queue[i]);
      i++;
      if(pC.get_time() > current_time)
        current_time = pC.get_time();
    }

    if(pD.get_time() <= current_time)
    {
      pD.insert_process(queue[i]);
      i++;
      if(pD.get_time() > current_time)
        current_time = pD.get_time();
    }

    if(pE.get_time() <= current_time)
    {
      pE.insert_process(queue[i]);
      i++;
      if(pE.get_time() > current_time)
        current_time = pE.get_time();
    }
  }
  if(pA.get_time() > current_time)
    current_time = pA.get_time();
  if(pB.get_time() > current_time)
    current_time = pB.get_time();
  if(pC.get_time() > current_time)
    current_time = pC.get_time();
  if(pD.get_time() > current_time)
    current_time = pD.get_time();
  if(pE.get_time() > current_time)
    current_time = pE.get_time();

  return current_time;
}

double sjf(vector<process> queue)
{

  return 0;
}

double msjf(vector<process> queue)
{
  return 0;
}
