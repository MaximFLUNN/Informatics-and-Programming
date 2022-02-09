/*
				| Copyright 2022 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
				|      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
									   | Source main file |
| [ENG] Task "OOP" : workout |
| [RU] Task "ООП": Тренировка |
*/
#include "Game.h"
int main() {
	int Choose;
	std::cout << "Choose a character class: " << "\n" << "1) Human" << "\n" << "2) Archer" << "\n" << "3) Warrior" << std::endl;
	std::cin >> Choose;
	if (Choose == 1) {
		struct Human User;
		struct Gun User_weapon;
		User = create_Human();
		User_weapon = create_Gun();
		print_character_info_Human(User, User_weapon);
	}
	else if (Choose == 2) {
		struct Archer User;
		struct Bow User_weapon;
		User = create_Archer();
		User_weapon = create_Bow();
		print_character_info_Archer(User, User_weapon);
	}
	else if (Choose == 3) {
		struct Warrior User;
		struct Axe User_weapon;
		User = create_Warrior();
		User_weapon = create_Axe();
		print_character_info_Warrior(User, User_weapon);
	}
	
	//std::cout << "Warrior name: " << user_0001_1->name << std::endl;
	system("pause");
	return 0;
}