include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class Line
{
public:
  unsigned address;
  bool inRAM;
  int entryPos;
  Line():inRAM(false){}
};

class Entry
{
public:
  int tablePos;
  bool used;
  Entry(): tablePos(-1), used(false){}
};


const int TABLE_SIZE = 32;
const int RAM_PAGES = 4;
const unsigned int VIRTUAL_SIZE = 0xFFFFFFFF;
const int VMPAGE_SIZE = 0x1000;

int main(int argc, char** argv)
{
  int i, count, clockPos = 0, pageTablePos;
  unsigned  address;
  Line pageTable[TABLE_SIZE];
  Entry entries[RAM_PAGES];
  ifstream inf(argv[1]);
  ofstream outf("vm-out.txt");
  
  
  for(i = 0; i < TABLE_SIZE; i++)
    inf >> hex >> pageTable[i].address;
  
  while(inf >> hex >> address)
  {
    for(pageTablePos = 0; pageTablePos < TABLE_SIZE; pageTablePos++)
    {
      if(pageTable[pageTablePos].address <= address && pageTable[pageTablePos].address + VMPAGE_SIZE > address)
        break;
    }
    
    if(pageTable[pageTablePos].inRAM)
    {
      entries[pageTable[pageTablePos].entryPos].used = true;
    }  // if in RAM
    else  // not in RAM
    {
      while (entries[clockPos].used)
      {
        entries[clockPos].used = false;
        clockPos++;
        clockPos = clockPos % RAM_PAGES;
      } // while entry is used

      
      entries[clockPos].used = true;
      pageTable[entries[clockPos].tablePos].inRAM = false;
      entries[clockPos].tablePos = pageTablePos;
      pageTable[pageTablePos].inRAM = true;
      pageTable[pageTablePos].entryPos = clockPos;
      clockPos++;
      clockPos = clockPos % RAM_PAGES;
    }  // else not in RAM
      
        
    count = 0;
    
    for(i = 0; i < RAM_PAGES; i++)
      if(entries[i].tablePos >= 0)
      {
        if(count++ > 0)
          outf << ' ';
        outf << hex << pageTable[entries[i].tablePos].address;
      } // if in RAM
    
    outf << endl;
  }  // while more in file

  outf.close();
  return 0;
} // main()