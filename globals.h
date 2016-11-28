#include <string>
using namespace std;

struct PowerMove // struct for each move that does damage
{
	string name; // Name of the move
	int power; // The amount it hits
	float critical; // The critical hit ratio
	float accuracy; // The accuracy of the move
	string type; // Type of the move
};

typedef struct PowerMove PowerMove; // Allowing move to be used as struct

struct Pokemon // struct for each pokemon
{
	string name; // Name of the pokemon
	int hp; // The health of the pokemon
	//PowerMove powerMoves[50]; // The list of damage moves with a maximum of 50
	string type; // Type of pokemon
};

typedef struct Pokemon Pokemon; // Allowing move to be used as struct
//
//
//declaring move_sets
//
//

//
//fire
//
PowerMove listOfFirePowerMoves[4] = 
{
	{"flamethrower", 100, 0.1, 0.5, "fire"},
	{"ember", 20, 0.4, 1, "fire"},
	{"flamewheel", 80, 0.3, 0.7, "fire"},
	{"fireblast", 120, 0.05, 0.4, "fire"}

};

//
//water
//
PowerMove listOfWaterPowerMoves[4] = 
{
	{"hydropump", 100, 0.1, 0.5, "water"},
	{"watergun", 20, 0.4, 1, "water"},
	{"bubblebeam", 80, 0.3, 0.7, "water"},
	{"hydrocanon", 120, 0.05, 0.4, "water"}

};

//
//grass
//
PowerMove listOfGrassPowerMoves[4] = 
{
	{"leafblast", 100, 0.1, 0.5, "grass"},
	{"razorleaf", 20, 0.4, 1, "grass"},
	{"whinewhip", 80, 0.3, 0.7, "grass"},
	{"frenzyplant", 120, 0.05, 0.4, "grass"}

};

//
//list of pokemons
//
Pokemon listOfPokemons[3] =
{
	{"charizard", 600, "fire"},
	{"blastoise", 600, "water"},
	{"venasaur", 600, "grass"}
};