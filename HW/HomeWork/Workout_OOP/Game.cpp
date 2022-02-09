/*
                | Copyright 2022 | MaximFLUNN | Maxim Filatov Group: 3821B1PR2 |
                |      GitHub profile link: https://github.com/MaximFLUNN      |
-------------------------------------------------------------------------------------------------------
                                       | Source funcs file |
| [ENG] Task "OOP" : workout |
| [RU] Task "ООП": Тренировка |
*/
#include "Game.h"

void print_character_info_Human(struct Human c, struct Gun w) {
  std::cout << "Name: " << c.name << std::endl <<
    "Gender: " << c.gender << std::endl <<
    "Power: " << c.power << std::endl <<
    "Health: " << c.health << std::endl <<
    "Technics:  " << c.technics << std::endl <<
    "Weapon: " << w.name << std::endl <<
    "Weapon's damage: " << w.damage << std::endl <<
    "Weapon's bullets: " << w.bullets << std::endl;
}

void print_character_info_Archer(struct Archer c, struct Bow w) {
    std::cout << "Name: " << c.name << std::endl <<
        "Gender: " << c.gender << std::endl <<
        "Power: " << c.power << std::endl <<
        "Health: " << c.health << std::endl <<
        "Dexterity:  " << c.dexterity << std::endl <<
        "Weapon: " << w.name << std::endl <<
        "Weapon's damage: " << w.damage << std::endl <<
        "Weapon's extra damage: " << w.extraDamage << std::endl <<
        "Weapon's time: " << w.time << std::endl <<
        "Weapon's arrows: " << w.arrows << std::endl;
}

void print_character_info_Warrior(struct Warrior c, struct Axe w) {
    std::cout << "Name: " << c.name << std::endl <<
        "Gender: " << c.gender << std::endl <<
        "Power: " << c.power << std::endl <<
        "Health: " << c.health << std::endl <<
        "Armor:  " << c.armor << std::endl <<
        "Weapon: " << w.name << std::endl <<
        "Weapon's damage: " << w.damage << std::endl <<
        "Weapon's strenght: " << w.strenght << std::endl;
}

struct Human create_Human() {
    int gender_choose;
    struct Human player;
    std::cout << "Enter your hero's name: ";
    std::cin >> player.name;
    std::cout << std::endl << "Choose gender (1 - female | 2 - male): ";
    std::cin >> gender_choose;
    if (gender_choose == 1) player.gender = "Femle";
    else if (gender_choose == 2) player.gender = "Male";
    player.power = 10.0;
    player.health = 100.0;
    player.technics = 1.0;
    return player;
}
 
struct Archer create_Archer() {
    int gender_choose;
    struct Archer player;
    std::cout << "Enter your hero's name: ";
    std::cin >> player.name;
    std::cout << std::endl << "Choose gender (1 - female | 2 - male): ";
    std::cin >> gender_choose;
    if (gender_choose == 1) player.gender = "Femle";
    else if (gender_choose == 2) player.gender = "Male";
    player.power = 8.0;
    player.health = 100.0;
    player.dexterity = 1.0;
    return player;
}

struct Warrior create_Warrior() {
    int gender_choose;
    struct Warrior player;
    std::cout << "Enter your hero's name: ";
    std::cin >> player.name;
    std::cout << std::endl << "Choose gender (1 - female | 2 - male): ";
    std::cin >> gender_choose;
    if (gender_choose == 1) player.gender = "Femle";
    else if (gender_choose == 2) player.gender = "Male";
    player.power = 8.0;
    player.health = 100.0;
    player.armor = 40.0;
    return player;
}

struct Gun create_Gun() {
    struct Gun weapon;
    std::cout << "Enter your guns name: ";
    std::cin >> weapon.name;
    weapon.damage = 20.0;
    weapon.bullets = 5;
    return weapon;
}

struct Bow create_Bow() {
    struct Bow weapon;
    std::cout << "Enter your bows name: ";
    std::cin >> weapon.name;
    weapon.damage = 30.0;
    weapon.arrows = 5;
    weapon.extraDamage = 50.0;
    weapon.time = 1;
    return weapon;
}

struct Axe create_Axe() {
    struct Axe weapon;
    std::cout << "Enter your axes name: ";
    std::cin >> weapon.name;
    weapon.damage = 30.0;
    weapon.strenght = 5;
    return weapon;
}