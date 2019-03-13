#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "process.h"
#include "cpu.h"
using namespace std;

double fifo(vector<process> queue);
double sjf(vector<process> queue);
double msjf(vector<process> queue);
bool compareP(const process &a, const process &b);

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
  cout << "SJF:  " << sjf(queue) << " s" << endl;
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

  double current_time = pA.get_time();
  int processor = 0;


  for(int i = 0; i < 200; i++)
  {
    current_time = pA.get_time();
    processor = 0;

    if(pB.get_time() < current_time)
    {
      current_time = pB.get_time();
      processor = 1;
    }
    else if(pC.get_time() < current_time)
    {
      current_time = pC.get_time();
      processor = 2;
    }
    else if(pD.get_time() < current_time)
    {
      current_time = pD.get_time();
      processor = 3;
    }
    else if(pE.get_time() < current_time)
    {
      current_time = pE.get_time();
      processor = 4;
    }

    switch(processor)
    {
      case 0:
      {
        pA.insert_process(queue[i]);
        break;
      }
      case 1:
      {
        pB.insert_process(queue[i]);
        break;
      }
      case 2:
      {
        pC.insert_process(queue[i]);
        break;
      }
      case 3:
      {
        pD.insert_process(queue[i]);
        break;
      }
      case 4:
      {
        pE.insert_process(queue[i]);
        break;
      }
    }
  }

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
  vector<process> sorted = queue;
  sort(sorted.begin(), sorted.end(), compareP);

  return fifo(sorted);
}

double msjf(vector<process> queue)
{
  vector<process> sorted = queue;
  sort(sorted.begin(), sorted.end(), compareP);

  CPU pA(2000000000, 1);
  CPU pB(2000000000, 1);
  CPU pC(3000000000, 1);
  CPU pD(3000000000, 1);
  CPU pE(4000000000, 1);
  bool longestC = false;
  bool longestD = false;

  double current_time = 0;
  int processor;
  int i = 0;
  int j = 199;

  while(i < j)
  {
    current_time = pA.get_time();
    processor = 0;

    if(pB.get_time() < current_time)
    {
      current_time = pB.get_time();
      processor = 1;
    }
    else if(pC.get_time() < current_time)
    {
      current_time = pC.get_time();
      processor = 2;
    }
    else if(pD.get_time() < current_time)
    {
      current_time = pD.get_time();
      processor = 3;
    }
    else if(pE.get_time() < current_time)
    {
      current_time = pE.get_time();
      processor = 4;
    }

    switch(processor)
    {
      case 0:
      {
        pA.insert_process(queue[i]);
        i++;
        break;
      }
      case 1:
      {
        pB.insert_process(queue[i]);
        i++;
        break;
      }
      case 2:
      {
        if(longestC)
        {
          pC.insert_process(queue[j]);
          j--;
          longestC = false;
        }
        else
        {
          pC.insert_process(queue[i]);
          i++;
          longestC = true;
        }
        break;
      }
      case 3:
      {
        if(longestD)
        {
          pD.insert_process(queue[j]);
          j--;
          longestD = false;
        }
        else
        {
          pD.insert_process(queue[i]);
          i++;
          longestD = true;
        }
        break;
      }
      case 4:
      {
        pE.insert_process(queue[j]);
        j--;
        break;
      }
    }
  }
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

bool compareP(const process &a, const process &b)
{
  return a.cycles < b.cycles;
}
