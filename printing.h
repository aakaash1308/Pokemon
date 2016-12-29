
#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

//
// Typewriter effect for Printing
//
void slowPrint(string s) 
{
  int i = 0;

  while(s[i]!=0) // going through the string
  {
    cout << s[i++];
    cout.flush();
    usleep(60000); // delaying output
  } // endWhile

  cout << endl;
} // endFunction


//
// Start of Progrma
//
void startScreen()
{
	cout << endl;
	slowPrint("WELCOME TO THE WORLD OF POKEMON............");
	cout << endl;
}

//
// Main Menu
//
void printMenu()
{
	slowPrint("PRESS ANY OF THE FOLLOWING  ");
	slowPrint("1) START");
  slowPrint("2) HOW TO PLAY");
  slowPrint("3) EXIT");
  cout << "********************************************************" << endl;
}

//
// Used to print all the pokemons for players to choose from
//
void printOptions(string player, string pokemons[], int len)
{ 
	// Used to print aesthetically 
	string toPrint = "Player ";
	string temp = player;
	toPrint += temp;
	temp = " choose your pokemon";
	toPrint += temp;
	cout << "  ";
	// Printing ends

	slowPrint(toPrint);

	for (int i = 0; i < len; i++) // going through the pokemon
	{
		cout << "\t" << i + 1 << ") ";
		slowPrint(pokemons[i]);
	}
}

//
// Showing player's choices
//
void printChoices(string player1, string player2)
{
	string toPrint = "Player 1 chose ";
	string temp = player1;
	toPrint += temp;
	slowPrint(toPrint);

	toPrint = "Player 2 chose ";
	temp = player2;
	toPrint += temp;
	slowPrint(toPrint);

	cout << "********************************************************" << endl;
}

//
// Printing player's hits
//
void printHit(string name, string move)
{
	string toPrint = " used ";
	toPrint = name + toPrint + move;
	slowPrint(toPrint);
}

//
// Printing player's moves
//
void printMoves(string name, string* moves)
{
	string toPrint = " choose your moves";
	toPrint = name + toPrint;
	slowPrint(toPrint);

	for (int i = 0; i < 4; i++) // going through the moves
	{
		cout << "\t" << i + 1 << ") ";
		slowPrint(moves[i]);
	}

cout << "********************************************************" << endl;
}

//
// Printing Players Damage
//
void printDamage(int damage, int hp, string attacker, string defender)
{
	string toPrint;
	string temp;

	if(damage != 0)
	{
		toPrint = " did ";
		temp = " damage";
		toPrint = attacker + toPrint + to_string(damage) + temp; 
	}
	else
	{
		toPrint = " missed";
		toPrint = attacker + toPrint;
	}

	slowPrint(toPrint);

	if(hp != 0)
	{
		toPrint = " has ";
		temp = " hp remaining";
		toPrint = defender + toPrint + to_string(hp) + temp;
	}
	else
	{
		toPrint = " has fainted";
		toPrint = defender + toPrint;
	}

	slowPrint(toPrint);

	cout << "********************************************************" << endl;
}

//
// Smart and interactive way of taking input
//
int handlingKeyboard()
{
  int c;
  FILE *fp = fopen("x", "w");
  SCREEN *s = newterm(NULL, stdin, stdout);
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  c = getch();
  endwin();
  return (c - 48);
}

//
// About The Game
//
void options()
{
  slowPrint("This is a turn by turn based pokemon battling game, in which two users get the chance to");
  slowPrint("battle each other by choosing which moves to damage the oponent pokemon........");
}

//
// Not stating the obvious again and again
//
void exit()
{
  cout << "good bye" << endl;
  
}

//
// Checks whether a given input is within a given range
// If not takes input again
//
int takeInput(int checkMenu, int lower, int upper)
{
	if(checkMenu)
		printMenu();

  int answer;

  answer = handlingKeyboard();
  // Checking For Right Input
  while(answer < lower || answer > upper)
  {
  	if(checkMenu)
    {
    	slowPrint("Wrong input ");
    	printMenu();
    }

    else
    	slowPrint("Wrong input");

    answer = handlingKeyboard();
    //cout << answer << endl;
  }

  return (answer);
}