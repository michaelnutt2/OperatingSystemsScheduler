#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "process.h"
#include "cpu.h"
using namespace std;


// Function declerations

double fifo(vector<process> q);



int main(int argc, char **argv)
{
  // Var
  process proc;
  vector<process> queue;
  FILE *procFile;


  if(argc < 2)
  {
    cout << "Usage: ./program1 [file]\n";
    return 0;
  }


  procFile = fopen(argv[1], "r");


  for(int i = 0; i < 200; i++)
  {
    fscanf(procFile, "%i %lld %lld", &proc.pid, &proc.cycles, &proc.memory);
    queue.push_back(proc);
  }
  fclose(procFile);


 cout << fifo(queue) << endl;

 return 0;
}

double fifo(vector<process> q)
{
  CPU pA(4000000000, 1);
  CPU pB(4000000000, 1);
  CPU pC(4000000000, 1);
  CPU pD(4000000000, 1);
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
        pA.insert_process(q[i]);
        break;
      }
      case 1:
      {
        pB.insert_process(q[i]);
        break;
      }
      case 2:
      {
        pC.insert_process(q[i]);
        break;
      }
      case 3:
      {
        pD.insert_process(q[i]);
        break;
      }
      case 4:
      {
        pE.insert_process(q[i]);
        break;
      }
    }
  }

  current_time = pA.get_time();
  if(pB.get_time() > current_time)
  {
    current_time = pB.get_time();
  }
  if(pC.get_time() > current_time)
  {
    current_time = pC.get_time();
  }
  if(pD.get_time() > current_time)
  {
    current_time = pD.get_time();
  }
  if(pE.get_time() > current_time)
  {
    current_time = pE.get_time();
  }

  return current_time;
}
