#include "vector"
#include <cstdlib>
#include <string.h>
#include "globals.h"
#include "printing.h"

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

PowerMove* getMoves(Pokemon pokemon)
{
	if(pokemon.type == "fire")
		return listOfFirePowerMoves;
	else if(pokemon.type == "water")
		return listOfWaterPowerMoves;
	else
		return listOfGrassPowerMoves;
}

PowerMove moveSelection(string name, Pokemon attacker)
{
	PowerMove* listOfMoves;
	listOfMoves = getMoves(attacker);
	int len = (sizeof(listOfFirePowerMoves)/sizeof(*listOfFirePowerMoves));

	string movesList[2000];

	for(int i = 0; i < len; i++)
	{
		movesList[i] = listOfMoves[i].name;
	}

	printMoves(name, movesList);
	int move = takeInput(0,1,len) - 1;

	return listOfMoves[move];
	
}

int hit(Pokemon attacker, PowerMove move, Pokemon defender)
{
	int damage = getDamage(attacker, move, defender);
	int hp = defender.hp - damage;

	if(hp < 0)
		hp = 0;

	printDamage(damage, hp, attacker.name ,defender.name);
	return hp;
}
void startGame(Pokemon player1, Pokemon player2)
{	
	PowerMove player1Move = moveSelection("Player 1", player1);
	PowerMove player2Move = moveSelection("Player 2", player2);

	int chance = rand() % 1 + 1;

	if(chance)
	{
		player2.hp = hit(player1, player1Move, player2);
		player1.hp = hit(player2, player2Move, player1);
	}

	else
	{
		player1.hp = hit(player2, player1Move, player1);
		player2.hp = hit(player1, player2Move, player2);
	}

	while(player1.hp && player2.hp)
	{
		PowerMove player1Move = moveSelection("Player 1", player1);
		PowerMove player2Move = moveSelection("Player 2", player2);

		int chance = rand() % 1 + 1;

		if(chance)
		{
			player2.hp = hit(player1, player1Move, player2);
			player1.hp = hit(player2, player2Move, player1);
		}

		else
		{
			player1.hp = hit(player2, player1Move, player1);
			player2.hp = hit(player1, player2Move, player2);
		}
	}

	if(player1.hp)
		slowPrint("Player1 wins");
	else
		slowPrint("Player2 wins");

}

