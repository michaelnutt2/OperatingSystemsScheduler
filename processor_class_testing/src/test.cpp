#include "process.h"
#include "cpu.h"
using namespace std;

int main()
{
	process p;
	p.pid = 0;
	p.cycles = 100;
	p.memory = 2;
	p.t_arrive = 0;
	p.t_complete = p.cycles - p.t_arrive;

	CPU test(1,1);
	test.insert_process(p);
	test.print_status();
}
