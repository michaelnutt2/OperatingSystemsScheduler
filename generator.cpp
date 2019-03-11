#include <iostream>
#include <random>
#include <limits>
using namespace std;

int main()
{
  random_device rd;
  mt19937_64 eng(rd());
  unsigned long long int cycles;
  unsigned long long int memory;

  uniform_int_distribution<long long int> distr1(10000000,50000000000000);
  uniform_int_distribution<long long int> distr2(256000,8000000000);

  for(int i = 0; i < 200; i++)
  {
    cycles = distr1(eng);

    memory = distr2(eng);

    cout << i << " " << cycles << " " << memory << endl;
  }
}
