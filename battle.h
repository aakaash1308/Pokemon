#include "vector"
#include <cstdlib>
#include <string.h>
#include "globals.h"
#include "printing.h"

//
// used to calculate damage of a move on a pokemon
//
int getDamage(Pokemon attacker, PowerMove move, Pokemon defender)
{
	int chance = rand() % 100; // getting a random number between 0-50
	float accuracy = float(chance) / 100; // to equate with move's accuracy

	if(accuracy >= move.accuracy) // miss
		return 0;

	printHit(attacker.name, move.name);

	if(accuracy <= move.critical)
	{
		slowPrint("It is a critical hit");
		move.power = (move.power * 3 ) / 2;
	}

	if(move.type == defender.weakness) // supereffective
	{
		slowPrint("It is supereffective");
		move.power = (move.power * 3 ) / 2;
	}
	else if(move.weakness == defender.type) // not very effective
	{
		slowPrint("It is not very effective");
		move.power = (move.power * 2 ) / 3;
	}
	return move.power;
}

//
// Returning all the moves for a specific type of pokemon
//
PowerMove* getMoves(Pokemon pokemon)
{
	if(pokemon.type == "fire")
		return listOfFirePowerMoves;
	else if(pokemon.type == "water")
		return listOfWaterPowerMoves;
	else
		return listOfGrassPowerMoves;
}

//
// Getting the information of the moves of a pokemon and printing it in printable format
//
PowerMove moveSelection(string name, Pokemon attacker)
{
	PowerMove* listOfMoves; // Empty List of Moves
	listOfMoves = getMoves(attacker); // Getting the moves for the specific type of Pokemon
	int len = (sizeof(listOfFirePowerMoves)/sizeof(*listOfFirePowerMoves)); /// getting length of list

	string movesList[2000]; // Declaring ample amount of space

	for(int i = 0; i < len; i++) // Copying the names
	{
		movesList[i] = listOfMoves[i].name;
	}

	printMoves(name, movesList); // Printing them out
	int move = takeInput(0,1,len) - 1; // Getting the input

	return listOfMoves[move]; // Returning the list
	 
}

//
// Hitting the opponent checking if he/she faints
//
int hit(Pokemon attacker, PowerMove move, Pokemon defender)
{
	int damage = getDamage(attacker, move, defender);
	int hp = defender.hp - damage;

	if(hp < 0)
		hp = 0;

	printDamage(damage, hp, attacker.name ,defender.name);
	return hp;
}

//
// Base Of the game, choosing moves and deciding which player moves first 
//
void startGame(Pokemon player1, Pokemon player2)
{	
	PowerMove player1Move = moveSelection("Player 1", player1); // Getting player 1's move
	PowerMove player2Move = moveSelection("Player 2", player2); // Getting player 2's move

	int chance = rand() % 2; // Random number to choose who goes first

	if(chance) // If Player1 first
	{
		player2.hp = hit(player1, player1Move, player2);
		player1.hp = hit(player2, player2Move, player1);
	}

	else // If Player 2 first
	{
		player1.hp = hit(player2, player1Move, player1);
		player2.hp = hit(player1, player2Move, player2);
	}

	while(player1.hp && player2.hp) // Till either pokemon has fainted
	{
		PowerMove player1Move = moveSelection("Player 1", player1);
		PowerMove player2Move = moveSelection("Player 2", player2);

		int chance = rand() % 2;

		if(chance)
		{
			player2.hp = hit(player1, player1Move, player2);
			
			if(player2.hp) // If pokemon fainted skip it's attack
				player1.hp = hit(player2, player2Move, player1);
		}

		else
		{

			player1.hp = hit(player2, player2Move, player1);

			if(player1.hp) // If pokemon fainted skip its attack
				player2.hp = hit(player1, player1Move, player2);
		}
	}

	if(player1.hp) // Printing who wins
		slowPrint("Player1 wins");
	else 
		slowPrint("Player2 wins");

}

