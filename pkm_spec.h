#include <iostream>
#include <string.h>
#include "pkm_move.h"

class Species
{
	private:
	std::string Name;
	int type;
	int base_stats[6];
	Move movepool[10];

	public:
	//constructor - null
	Species() {
		Name = "Nosepass";
		type = ROCK;
		base_stats[0] = 30;  //HP
		base_stats[1] = 45;  //Attack
		base_stats[2] = 135; //Defense
		base_stats[3] = 45;  //Sp. Attack
		base_stats[4] = 90;  //Sp. Defense
		base_stats[5] = 30;  //Speed

		set_move(0,Move("Tackle",NORMAL,40,100,35,0,0));
		set_move(1,Move("Rock Throw",ROCK,50,90,15,0,0));
		set_move(2,Move("Zap Cannon",ELECTRIC,120,50,5,0,0));
		set_move(3,Move("Swords Dance",NORMAL,0,0,20,20,1));
	}
	//constructor - input pokemon
	Species(std::string name_in, int type_in) {
		Name = name_in;
		type = type_in;
	}

	//set base stat
	void set_stat(int stat_num, int stat_val) {
		if (stat_num < 6) {
			base_stats[stat_num] = stat_val;
		}
		else {
			std::cout << "Warning! Out of Range!" << std::endl;
		}
	}

	//set move
	void set_move(int move_num, Move move_val) {
		if (move_num < 10) {
			movepool[move_num] = move_val;
		}
		else {
			std::cout << "Warning! Out of Range!" << std::endl;
		}
	}

	//get name
	std::string get_name() {
		return Name;
	}

	//get move
	Move get_move(int move_num) {
		move_num = move_num % 4;
		return movepool[move_num];
	}

	//get type
	int get_type() {
		return type;
	}
	//get stats
	int get_stat(int stat_num) {
		return base_stats[stat_num];
	}
};
