#include <iostream>
#include <stdio.h>
#include <string>
#include "pkm_obj.h"

using namespace std;

int main (int argc, char* argv[])
{

	Pokemon *Noze0 = new Pokemon("Noze_Zelle",50);
	Pokemon *Noze1 = new Pokemon("Nosepass",100);

	Noze0->set_current_move(1,Move("Swords Dance",NORMAL,0,0,20,20,1));

	cout << "Battle!!!" << endl;
	cout << Noze0->get_nick() << " vs " << Noze1->get_nick() << endl;

	Noze0->battle();
	Noze1->battle();

	cout << Noze0->get_nick() << "\tHP: " << Noze0->get_battle_stat(0) << endl;
	cout << Noze1->get_nick() << "\tHP: " << Noze1->get_battle_stat(0) << endl;

	while (true) {
		cout << endl << "What will you do?" << endl << "1) FIGHT\n2) RUN" << endl;
		int choice;
		cin >> choice;
		choice = choice % 2;

		switch (choice) {
		case 0:
			cout << "Got away safely!" << endl;
			return 0;
		case 1:
			cout << "What move will " << Noze0->get_nick() << " use?" << endl;
			for (int m = 0; m < 4; m++) {
				cout << m+1 << ") " << Noze0->get_current_move(m).get_name() << endl;
			}
		}

		cin >> choice;
		Noze1->get_hit(Noze0->use_move(choice - 1));

		cout << Noze0->get_nick() << "\tHP: " << Noze0->get_battle_stat(0) << endl;
		cout << Noze1->get_nick() << "\tHP: " << Noze1->get_battle_stat(0) << endl;

		if (Noze0->get_battle_stat(0) <= 0 || Noze1->get_battle_stat(0) <= 0) {
			break;
		}
	}
	return 0;
}
