#include <cstdlib>
#include <string.h>
#include <ncurses.h>
#include "vector"
#include "battle.h"
using namespace std;

void gameplay();



void getPokemonOptions()
{
  int len = (sizeof(listOfPokemons)/sizeof(*listOfPokemons));

  string  pokemonNames[2000];

  for(int i = 0; i < len; i++)
  {
    pokemonNames[i] = listOfPokemons[i].name;
  }

   printOptions("1", pokemonNames, len);
   player1Pokemon = listOfPokemons[takeInput(0, 1, len) - 1];
   cout << "********************************************************" << endl;

   printOptions("2", pokemonNames, len);
   player2Pokemon = listOfPokemons[takeInput(0, 1, len) - 1];
   cout << "********************************************************" << endl;

}

void start()
{
  getPokemonOptions();
  printChoices(player1Pokemon.name, player2Pokemon.name);
  startGame(player1Pokemon, player2Pokemon);

  return;
}

void gameplay()
{
  int answer = takeInput(1, 1, 3);
  
  switch(answer)
  {
    case 1 : start(); break;
    case 2 : options(); gameplay(); break;
    case 3 : exit(); break;
  }
}

int main(int argc, char* argv[]) //main function
{
  //gameplay();
  if(argc == 2)
  {
    start();
    return 0;
  }
  startScreen();
  gameplay();


  return 0;
}