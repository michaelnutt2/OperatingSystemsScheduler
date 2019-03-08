#include <iostream>
#include <stdio.h>
#include "process.h"
using namespace std;

int main(int argc, char **argv)
{
  process p;
  if(argc < 2)
  {
    cout << "Usage: ./a.out [filename]\n";
    return 0;
  }

  FILE *f;
  f = fopen(argv[1],"r");

  for(int i = 0; i < 200; i++)
  {
    fscanf(f, "%i %i %i", &p.pid, &p.cycles, &p.memory);
    cout << p.pid << " " << p.cycles << " " << p.memory << endl;
  }

  return 0;
}
