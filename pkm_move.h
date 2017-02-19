#include <string>
#include "typechart.h"
#include "statdef.h"

class Move
{
private:
	std::string Name;
	int type;
	int BP;
	int AC;
	int PP;
	int move_type; //Physical, Special, or Status

public:
	//constructor
	Move() {
		Name = "Splash";
		type = NORMAL;
		BP = 0;
		AC = 100;
		PP = 40;
		move_type = STATUS;
	}
	Move(std::string name_in, int type_in, int bp_in, int ac_in, int pp_in, int m_type_in) {
		Name = name_in;
		type = type_in;
		BP = bp_in;
		AC = ac_in;
		PP = pp_in;
		move_type = m_type_in;
	}

	std::string get_name() {return Name;}
	int get_type() {return type;}
	int get_bp() {return BP;}
	int get_ac() {return AC;}
	int get_pp() {return PP;}
	int get_m_type() {return move_type;}
};
