#include <string>
#include "typechart.h"

class Move
{
private:
	std::string Name;
	int type;
	int BP;
	int AC;
	int PP;
	int buff;
	int to_stat;

public:
	//constructor
	Move() {
		Name = "Splash";
		type = NORMAL;
		BP = 0;
		AC = 100;
		PP = 40;
		buff = 0;
		to_stat = 0;
	}
	Move(std::string name_in, int type_in, int bp_in, int ac_in, int pp_in, int buff_in, int to_stat_in) {
		Name = name_in;
		type = type_in;
		BP = bp_in;
		AC = ac_in;
		PP = pp_in;
		buff = buff_in;
		to_stat = to_stat_in;
	}

	//get name
	std::string get_name() {
		return Name;
	}

	//get type
	int get_type() {
		return type;
	}

	//get bp
	int get_bp() {
		return BP;
	}

	//get ac
	int get_ac() {
		return AC;
	}

	//get pp
	int get_pp() {
		return PP;
	}

	//get buff
	int get_buff() {
		return buff;
	}

	int get_to_stat() {
		return to_stat;
	}
};
