#include <string>
using namespace std;



struct PowerMove // struct for each move that does damage
{
	string name; // Name of the move
	int power; // The amount it hits
	float critical; // The critical hit ratio
	float accuracy; // The accuracy of the move
	string type; // Type of the move
	string weakness; // weakness of move
};

typedef struct PowerMove PowerMove; // Allowing move to be used as struct

struct Pokemon // struct for each pokemon
{
	string name; // Name of the pokemon
	int hp; // The health of the pokemon
	//PowerMove powerMoves[50]; // The list of damage moves with a maximum of 50
	string type; // Type of pokemon
	string weakness; // Type of move
};

typedef struct Pokemon Pokemon; // Allowing move to be used as struct

Pokemon player1Pokemon; // Variable that holds player1's pokemon
Pokemon player2Pokemon; // Variable that holds player2's pokemon
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
	{"flamethrower", 100, 0.1, 0.5, "fire", "water"},
	{"ember", 20, 0.4, 1, "fire", "water"},
	{"flamewheel", 80, 0.3, 0.7, "fire", "water"},
	{"fireblast", 120, 0.05, 0.4, "fire", "water"}

};

//
//water
//
PowerMove listOfWaterPowerMoves[4] = 
{
	{"hydropump", 100, 0.1, 0.5, "water", "grass"},
	{"watergun", 20, 0.4, 1, "water", "grass"},
	{"bubblebeam", 80, 0.3, 0.7, "water", "grass"},
	{"hydrocanon", 120, 0.05, 0.4, "water", "grass"}

};

//
//grass
//
PowerMove listOfGrassPowerMoves[4] = 
{
	{"leafblast", 100, 0.1, 0.5, "grass", "fire"},
	{"razorleaf", 20, 0.4, 1, "grass", "fire"},
	{"whinewhip", 80, 0.3, 0.7, "grass", "fire"},
	{"frenzyplant", 120, 0.05, 0.4, "grass", "fire"}

};

//
//list of pokemons
//
Pokemon listOfPokemons[4] =
{
	{"charizard", 600, "fire", "water"},
	{"blastoise", 600, "water", "grass"},
	{"venasaur", 600, "grass", "fire"},
	{"pikachu", 400, "electric", "rock"}
};