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

	public:

	Pokemon() {
		Species();

		Nickname = get_name();

		stats[HP]         = get_stat(HP);
		stats[ATTACK]     = get_stat(ATTACK);
		stats[DEFENSE]    = get_stat(DEFENSE);
		stats[SP_ATTACK]  = get_stat(SP_ATTACK);
		stats[SP_DEFENSE] = get_stat(SP_DEFENSE);
		stats[SPEED]      = get_stat(SPEED);

		battle_stats[HP]         = stats[HP];
		battle_stats[ATTACK]     = stats[ATTACK];
		battle_stats[DEFENSE]    = stats[DEFENSE];
		battle_stats[SP_ATTACK]  = stats[SP_ATTACK];
		battle_stats[SP_DEFENSE] = stats[SP_DEFENSE];
		battle_stats[SPEED]      = stats[SPEED];
		battle_stats[ACCURACY]   = 100;
		battle_stats[EVADE]      = 100;

		level = 1;
		happiness = 70;
		//int IV[6];
		//int EV[6];
	}

	Pokemon(std::string nick, int level_in) {
		Species();

		Nickname = nick;

		stats[HP]         = get_stat(HP);
		stats[ATTACK]     = get_stat(ATTACK);
		stats[DEFENSE]    = get_stat(DEFENSE);
		stats[SP_ATTACK]  = get_stat(SP_ATTACK);
		stats[SP_DEFENSE] = get_stat(SP_DEFENSE);
		stats[SPEED]      = get_stat(SPEED);

		battle_stats[HP]         = stats[HP];
		battle_stats[ATTACK]     = stats[ATTACK];
		battle_stats[DEFENSE]    = stats[DEFENSE];
		battle_stats[SP_ATTACK]  = stats[SP_ATTACK];
		battle_stats[SP_DEFENSE] = stats[SP_DEFENSE];
		battle_stats[SPEED]      = stats[SPEED];
		battle_stats[ACCURACY]   = 100;
		battle_stats[EVADE]      = 100;

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
		std::cout << "Battle Stat: " << get_battle_stat(1) << std::endl;
		std::cout << "Poke's Stat: " << get_current_stat(1) << std::endl;
		return current_moves[choice].get_bp() + get_battle_stat(1) - get_current_stat(1);
	}

	void get_hit(int damage) {
		std::cout << "Damage " << damage << std::endl;
		battle_stats[0] = battle_stats[0] - damage;
	}
};
