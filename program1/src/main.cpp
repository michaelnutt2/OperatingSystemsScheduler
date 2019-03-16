#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "process.h"
#include "cpu.h"
using namespace std;


// Function declerations
double sjf(vector<process> q);

double msjf(vector<process> q);

double fifo(vector<process> q);

bool compareP(const process &a, const process &b);

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


 cout << fifo(queue) << "," << sjf(queue) << "," << msjf(queue) << endl;

 return 0;
}

double fifo(vector<process> q)
{
  CPU pA(4000000000, 10000000000);
  CPU pB(4000000000, 10000000000);
  CPU pC(4000000000, 10000000000);
  CPU pD(4000000000, 10000000000);
  CPU pE(4000000000, 10000000000);

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


double sjf(vector<process> q)
{
  vector<process> sorted = q;
  sort(sorted.begin(), sorted.end(), compareP);

  return fifo(sorted);
}

double msjf(vector<process> q)
{
  CPU pA(4000000000, 10000000000);
  CPU pB(4000000000, 10000000000);
  CPU pC(4000000000, 10000000000);
  CPU pD(4000000000, 10000000000);
  CPU pE(4000000000, 10000000000);


  bool pCLong = false;
  bool pDLong = false;

  double current_time = 0;
  int processor;
  int i = 0;
  int j = 199;


  vector<process> sorted = q;
  sort(sorted.begin(), sorted.end(), compareP);


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
        pA.insert_process(q[i]);
        i++;
        break;
      }
      case 1:
      {
        pB.insert_process(q[i]);
        i++;
        break;
      }
      case 2:
      {
        if(pCLong)
        {
          pC.insert_process(q[j]);
          j--;
          pCLong = false;
        }
        else
        {
          pC.insert_process(q[i]);
          i++;
          pCLong = true;
        }
        break;
      }
      case 3:
      {
        if(pDLong)
        {
          pD.insert_process(q[j]);
          j--;
          pDLong = false;
        }
        else
        {
          pD.insert_process(q[i]);
          i++;
          pDLong = true;
        }
        break;
      }
      case 4:
      {
        pE.insert_process(q[j]);
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
