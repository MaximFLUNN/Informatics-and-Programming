/*
				| Copyright 2022 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
				|      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
									   | Header funcs file |
| [ENG] Task "OOP" : workout |
| [RU] Task "ООП": Тренировка |
*/
#pragma once
#include <iostream>
#include <string>

// Weapons

struct Gun {
  std::string name;
  double damage;
  int bullets;
};

struct Bow {
  std::string name;
  double damage;
  int arrows;
  double extraDamage;
  int time;
};

struct Axe {
  std::string name;
  double damage;
  int strenght;
};

// Characters

struct Human {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  int technics;
};

struct Archer {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  int dexterity;
};

struct Warrior {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  double armor;
};

void print_character_info_Human(struct Human c, struct Gun w);
void print_character_info_Archer(struct Archer c, struct Bow w);
void print_character_info_Warrior(struct Warrior c, struct Axe w);

struct Human create_Human();
struct Archer create_Archer();
struct Warrior create_Warrior();

struct Gun create_Gun();
struct Bow create_Bow();
struct Axe create_Axe();