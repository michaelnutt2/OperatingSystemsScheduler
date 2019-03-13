#include <iostream>
#include <fstream>
#include <algorithm>
#include "process.h"
#include "cpu.h"

using namespace std;

//Function Declerations
bool compareP(const process &a,const process &b);

int main(int argc, char **argv){


    //checking if the nums of args is correct for call
    if (argc != 2){
      cout << "Not enough args past... correct is ./program <file>" << endl;
      return 1;
    }

    //variables
    ifstream file;
    int pID;
    long long int burst;
    long long int mem;
    vector<CPU> cpu;
    vector<process> p;
    vector<process> ps;
    int total = 0;

    //Setting Up CPU vector for FIFO with varying Ram
    CPU cpuA(4000000000,2000000000);
    CPU cpuB(4000000000,2000000000);
    CPU cpuC(4000000000,4000000000);
    CPU cpuD(4000000000,4000000000);
    CPU cpuE(4000000000,8000000000);
    cpu.push_back(cpuA);
    cpu.push_back(cpuB);
    cpu.push_back(cpuC);
    cpu.push_back(cpuD);
    cpu.push_back(cpuE);


    //open up file if possiable
    file.open(argv[1]);
    if(!file.is_open()){
      cout << "Unable to open file...exiting" << endl;
      return 2;
    }

    //placing file into process struct, then into the cpu queue
    while( file >> pID >> burst >> mem){
        process temp;
        temp.pid = pID;
        temp.cycles = burst;
        temp.memory = mem;
        p.push_back(temp);
    }

    //setting up a sorted vector of the process by Cycle time
    ps = p;
    sort(ps.begin(),ps.end(),compareP);

/******************************************************************************/
    //fifo
    //varible to keep track of what CPU processor to place processor
    int fifoCount = 0;

    //cycle through all the process
    for( int i = 0; i < p.size(); i++){
      //Algorithm to place process into CPU based on FIFO and Ram limit
      if(p[i].memory <= cpu[fifoCount].memory){
        switch(fifoCount){
          case 0:
            cpu[0].insert_process(p[i]);
            fifoCount =1;
            break;
          case 1:
            cpu[1].insert_process(p[i]);
            fifoCount = 2;
            break;
          case 2:
            cpu[2].insert_process(p[i]);
            fifoCount =3;
            break;
          case 3:
            cpu[3].insert_process(p[i]);
            fifoCount =4;
            break;
          case 4:
            cpu[4].insert_process(p[i]);
            fifoCount =0;
            break;
        }

      }
      else{
        if(fifoCount <=3)
            fifoCount++;
        else
            fifoCount = 0;
            i--;
      }

    }

      //Print out time for each CPU and the Total time
      for(unsigned int i=0; i < cpu.size(); i++){
      //  cout << "For CPU " << i+1 << " RUNTIME WAS " << cpu[i].get_time() << endl;
        total = total + cpu[i].get_time();
      }
      cout << total << ",";
      total = 0;
/*****************************************************************************/

      //clearing out the cpu class and setting back the CPU parameters
      cpu.clear();
      cpu.push_back(cpuA);
      cpu.push_back(cpuB);
      cpu.push_back(cpuC);
      cpu.push_back(cpuD);
      cpu.push_back(cpuE);

/******************************************************************************/
    //sjf
    //Variable to keep track of what CPU is to be used
    int sjfCount = 0;

    //Go through sorted list of procecess from smallist cycles to largest
    for( int i = 0; i < ps.size(); i++){
      //Algorithm to place process into CPU based on SJF and Ram limit
      if(ps[i].memory <= cpu[sjfCount].memory){
        switch(sjfCount){
          case 0:
            cpu[0].insert_process(ps[i]);
            sjfCount =1;
            break;
          case 1:
            cpu[1].insert_process(ps[i]);
            sjfCount = 2;
            break;
          case 2:
            cpu[2].insert_process(ps[i]);
            sjfCount =3;
            break;
          case 3:
            cpu[3].insert_process(ps[i]);
            sjfCount =4;
            break;
          case 4:
            cpu[4].insert_process(ps[i]);
            sjfCount =0;
            break;
        }

      }
      else{
        if(sjfCount <=3)
            sjfCount++;
        else
            sjfCount = 0;
            i--;
      }

    }

      //Print out time for each CPU and the Total time
      for(unsigned int i=0; i < cpu.size(); i++){
        //cout << "For CPU " << i+1 << " RUNTIME WAS " << cpu[i].get_time() << endl;
        total = total + cpu[i].get_time();
      }
      cout << total << ",";
      total = 0;
/******************************************************************************/

      //clearing out the cpu class and setting back the CPU parameters
      cpu.clear();
      cpu.push_back(cpuA);
      cpu.push_back(cpuB);
      cpu.push_back(cpuC);
      cpu.push_back(cpuD);
      cpu.push_back(cpuE);

/*****************************************************************************/
/*Algorithm grabs the back largest process every 4th call to the CPU
  uses sorted Processes, and still follows RAM conditions
*/
    //msjf
    //Variable to diecide what CPU to use
    int msjfCount = 0;

    //Variable to iterate from the end of process list to where it meets the
    //front iterateor
    int end =  ps.size()-1;

    //Go through all the sorted process list
    for( int i = 0; i < ps.size(); i++){

      //Go through normal sjf every 3/4 processes
      if(i % 4 !=0){
        if(ps[i].memory <= cpu[msjfCount].memory){
          switch(msjfCount){
            case 0:
              cpu[0].insert_process(ps[i]);
              msjfCount =1;
              break;
            case 1:
              cpu[1].insert_process(ps[i]);
              msjfCount = 2;
              break;
            case 2:
              cpu[2].insert_process(ps[i]);
              msjfCount =3;
              break;
            case 3:
              cpu[3].insert_process(ps[i]);
              msjfCount =4;
              break;
            case 4:
              cpu[4].insert_process(ps[i]);
              msjfCount =0;
              break;
          }

        }
        else{
          if(msjfCount <=3)
              msjfCount++;
          else
              msjfCount = 0;
              i--;
        }
      }
      else{
        //statement to end algorithm once iterators meet, goes to end of algo
        if(i >= end){
          goto DONE;
        }
          //Goes from back of sorted list and places it onto a process
          if(ps[end].memory <= cpu[msjfCount].memory){
            switch(msjfCount){
              case 0:
                cpu[0].insert_process(ps[end]);
                msjfCount =1;
                end--;
                break;
              case 1:
                cpu[1].insert_process(ps[end]);
                msjfCount = 2;
                end--;
                break;
              case 2:
                cpu[2].insert_process(ps[end]);
                msjfCount =3;
                end--;
                break;
              case 3:
                cpu[3].insert_process(ps[end]);
                msjfCount =4;
                end--;
                break;
              case 4:
                cpu[4].insert_process(ps[end]);
                msjfCount =0;
                end--;
                break;
            }

          }
          else{
            if(msjfCount <=3)
                msjfCount++;
            else
                msjfCount = 0;
                i--;
          }

      }

    }

    //goto statement when back iterator reaches front
    DONE: ;

    //Print out time for each CPU and the Total time
      for(unsigned int i=0; i < cpu.size(); i++){
    //    cout << "For CPU " << i+1 << " RUNTIME WAS " << cpu[i].get_time() << endl;
        total = total + cpu[i].get_time();
      }
  cout << total <<endl;


    // cout <<"/////////////////////////////////////////////////////////////" << endl;
}





//function to be used by sort, to compare cycle time between process
bool compareP(const process &a,const process &b){
  return a.cycles < b.cycles;
}
