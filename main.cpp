#include <cstdlib>
#include <string.h>
#include "vector"
#include "globals.h"
#include "printing.h"
using namespace std;

void gameplay();

void exit()
{
  cout << "good bye" << endl;
}

void options()
{
  cout << "some_instructions" << endl;
  gameplay();
}

void start()
{
  cout << "where it all begins " << endl;
  gameplay();
}

void gameplay()
{
  string answer = takeInput();
  
  switch(stoi(answer))
  {
    case 1 : start(); break;
    case 2 : options(); break;
    case 3 : exit(); break;
    return;
  }
}

int main(int argc, char* argv[]) //main function
{
  startScreen();
  gameplay();

  return 0;
}