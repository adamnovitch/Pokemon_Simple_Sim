#include <iostream>
#include <vector>
#include "pkm_move.h"

class Species
{
	private:
	std::string Name;
	int base_stats[6];

	struct type
	{
		int primary;
		int secondary;
	};

	type species_type;

	struct movepool
	{
		int level;
		Move move;
	};
	std::vector<movepool> level_up_moves;

	public:
	//constructor
	Species() {
		Name = "Nosepass";
		species_type.primary   = ROCK;
		species_type.secondary = NONE;

		base_stats[HP]         =  30;
		base_stats[ATTACK]     =  45;
		base_stats[DEFENSE]    = 135;
		base_stats[SP_ATTACK]  =  45;
		base_stats[SP_DEFENSE] =  90;
		base_stats[SPEED]      =  30;
	}

	std::string get_name() {return Name;}
	type get_type() {return species_type;}
	int get_stat(int stat_num) {return base_stats[stat_num];}
};
