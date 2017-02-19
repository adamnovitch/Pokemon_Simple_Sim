#include "pkm_spec.h"

class Pokemon : public Species
{
	private:
	std::string Nickname;
	Move current_moves[4];
	int stats[6];
	int battle_stats[8];
	int level;
	int happiness;
	//int IV[6];
	//int EV[6];

	struct learnset
	{
		int level;
		Move move;
	};

	learnset level_up_moves[10];

	public:

	Pokemon() {
		Species();

		level_up_moves[0].level = 1;
		level_up_moves[0].move = get_move(0);
		level_up_moves[1].level = 10;
		level_up_moves[1].move = get_move(1);
		level_up_moves[2].level = 20;
		level_up_moves[2].move = get_move(2);

		Nickname = get_name();
		set_current_move(0,level_up_moves[0].move);

		stats[0] = get_stat(0);  //HP
		stats[1] = get_stat(1);  //Attack
		stats[2] = get_stat(2);  //Defense
		stats[3] = get_stat(3);  //Sp. Attack
		stats[4] = get_stat(4);  //Sp. Defense
		stats[5] = get_stat(5);  //Speed

		battle_stats[0] = stats[0];
		battle_stats[1] = stats[1];
		battle_stats[2] = stats[2];
		battle_stats[3] = stats[3];
		battle_stats[4] = stats[4];
		battle_stats[5] = stats[5];
		battle_stats[6] = 100;
		battle_stats[7] = 100;

		level = 5;
		happiness = 70;
		//int IV[6];
		//int EV[6];
	}

	Pokemon(std::string nick, int level_in) {
		Species();

		level_up_moves[0].level = 1;
		level_up_moves[0].move = get_move(0);
		level_up_moves[1].level = 10;
		level_up_moves[1].move = get_move(1);
		level_up_moves[2].level = 20;
		level_up_moves[2].move = get_move(2);

		Nickname = nick;
		set_current_move(0,level_up_moves[0].move);

		stats[0] = get_stat(0);  //HP
		stats[1] = get_stat(1);  //Attack
		stats[2] = get_stat(2);  //Defense
		stats[3] = get_stat(3);  //Sp. Attack
		stats[4] = get_stat(4);  //Sp. Defense
		stats[5] = get_stat(5);  //Speed

		battle_stats[0] = stats[0];
		battle_stats[1] = stats[1];
		battle_stats[2] = stats[2];
		battle_stats[3] = stats[3];
		battle_stats[4] = stats[4];
		battle_stats[5] = stats[5];
		battle_stats[6] = 100;
		battle_stats[7] = 100;

		level = level_in;
		happiness = 70;
		//int IV[6];
		//int EV[6];
	}

	//set move
	void set_current_move(int move_num, Move move_val) {
		if (move_num < 4) {
			current_moves[move_num] = move_val;
		}
		else {
			std::cout << "Warning! Out of Range!" << std::endl;
		}
	}

	Move get_current_move(int move_slot) {
		move_slot = move_slot % 4;
		return current_moves[move_slot];
	}

	std::string get_nick() {
		return Nickname;
	}

	void battle() {
		battle_stats[0] = stats[0] + level;
		battle_stats[1] = stats[1] + level;
		battle_stats[2] = stats[2] + level;
		battle_stats[3] = stats[3] + level;
		battle_stats[4] = stats[4] + level;
		battle_stats[5] = stats[5] + level;
	}

	int get_current_stat(int stat_num) {
		return stats[stat_num];
	}

	int get_battle_stat(int stat_num) {
		return battle_stats[stat_num];
	}

	int use_move(int choice) {
		if (current_moves[choice].get_buff() == 0) {
			std::cout << "Battle Stat: " << get_battle_stat(1) << std::endl;
			std::cout << "Poke's Stat: " << get_current_stat(1) << std::endl;
			return current_moves[choice].get_bp() + get_battle_stat(1) - get_current_stat(1);
		}
		else {
			battle_stats[current_moves[choice].get_to_stat()] += current_moves[choice].get_buff();
			std::cout << current_moves[choice].get_to_stat() << " " << battle_stats[current_moves[choice].get_to_stat()] << std::endl;
			return 0;
		}
	}

	void get_hit(int damage) {
		std::cout << "Damage " << damage << std::endl;
		battle_stats[0] = battle_stats[0] - damage;
	}
};
