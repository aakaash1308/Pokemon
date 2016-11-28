
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void startScreen()
{
	cout << setw(25) << setfill('-') << "WELCOME TO POKEMON" << endl;
}
void printMenu()
{
	cout << setw(25) << setfill('-') << "1) START          " << endl;
  cout << setw(25) << setfill('-') << "2) HOW TO PLAY    " << endl;
  cout << setw(25) << setfill('-') << "3) EXIT           " << endl;
}


string takeInput()
{
	printMenu();
  char answer[100];
  cout << "Enter Input -> ";
  cin >> answer;

  // Checking For Right Input
  while(!isdigit(answer[0]) || (isdigit(answer[0]) && (stoi(answer) <= 0 || stoi(answer) >= 4)))
  {
    cout << "Wrong input Enter Again -> ";
    cin >> answer;
  }

  return (answer);
}