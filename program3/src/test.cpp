#include "process.h"
#include "cpu.h"
using namespace std;

int main()
{
	process p;
	p.pid = 0;
	p.cycles = 100;
	p.memory = 2;


	CPU test(1,1);
	test.insert_process(p);
	process p2;
	p2.pid = 1;
	p2.cycles = 200;
	p2.memory = 2;

	test.insert_process(p2);
	test.print_status();

	return 0;
}
