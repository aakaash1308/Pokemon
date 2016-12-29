#include <cstdlib>
#include <string.h>
#include <ncurses.h>
#include "vector"
#include "battle.h"
using namespace std;

void gameplay(); // Forward declaration


//
// Listing all the pokemon
//
void getPokemonOptions() 
{
  int len = (sizeof(listOfPokemons)/sizeof(*listOfPokemons)); // Getting the size of the list

  string  pokemonNames[2000]; // Limit of Pokemons possible

  for(int i = 0; i < len; i++) // Getting the strings
  {
    pokemonNames[i] = listOfPokemons[i].name;
  }

   printOptions("1", pokemonNames, len); // Printing
   player1Pokemon = listOfPokemons[takeInput(0, 1, len) - 1];
   cout << "********************************************************" << endl;

   printOptions("2", pokemonNames, len); // Printing
   player2Pokemon = listOfPokemons[takeInput(0, 1, len) - 1];
   cout << "********************************************************" << endl;

}

//
// When start is pressed
// 
void start()
{
  getPokemonOptions();
  printChoices(player1Pokemon.name, player2Pokemon.name); // Printing choices of players
  startGame(player1Pokemon, player2Pokemon);

}

//
// For calling functions based on user's input
//
void gameplay()
{
  int answer = takeInput(1, 1, 3); // Taking Input efficiently
  
  switch(answer)
  {
    case 1 : start(); break;
    case 2 : options(); gameplay(); break;
    case 3 : exit(); break;
  }

}

//
// Main function
//
int main(int argc, char* argv[]) 
{

  if(argc == 2) // For debugging
  {
    start();
    return 0;
  }
  startScreen(); // Choosing option
  gameplay();


  return 0;
}