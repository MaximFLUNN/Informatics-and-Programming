#pragma once
#include <iostream>
#include <string>

// Weapons

struct Gun {
  std::string name;
  double damage;
  int cartridges;
};

struct Bow {
  std::string name;
  double damage;
  int arrows;
  double extraDamage;
  int time;
};

class Axe {
private:
  std::string name;
  double damage;
  int strenght;

public:
  Axe() {
	  name = "Gorehowl";
	  damage = 30.0;
	  strenght = 100.0;
  };

  Axe(std::string _name, double _damage, int _strenght) {
	  name = _name;
	  damage = _damage;
	  strenght = _strenght;
  };

  Axe(const Axe &a) {
	  name = a.name;
	  damage = a.damage;
	  strenght = a.strenght;
  };

  // Геттеры

  std::string getName() {
	  return name;
  };

  double getDamage() {
	  return damage;
  };

  int getStrenght() {
	  return strenght;
  };

  // Сеттер
  void getName(std::string _name) {
	  name = _name;
  };
};

// Characters

class Characters {
protected:
	std::string name;
	std::string  gender;
	double power;
	double health;

public:
	Characters() {
		name = "Bob";
		gender = "male";
		power = 1.0;
		health = 100.0;
	};

	// Конструктор инициализации
	Characters(std::string _name, std::string _gender, double _power, double _health) {
		name = _name;
		gender = _gender;
		power = _power;
		health = _health;
	};

	// Конструктор копирования (по адресу)
	Characters(const Characters& c) {
		name = c.name;
		gender = c.gender;
		power = c.power;
		health = c.health;
	};
	void print_character_info() {
		std::cout << "Name: " << name << std::endl <<
			"Gender: " << gender << std::endl <<
			"Power: " << power << std::endl <<
			"Health: " << health << std::endl;
	}
};

struct Human {
  std::string name;
  std::string  gender;
  double power;
  double health;
  Gun weapon;
  int technics;
};

struct Archer {
  std::string name;
  std::string  gender;
  double power;
  double health;
  Bow weapon;
  int dexterity;
};

class Warrior : public Characters {
private:
  Axe weapon;
  double armor;

public:
  // Конструктор по умолчанию
  Warrior() : Characters::Characters() {
	  //Axe _weapon;
	  //weapon = _weapon;
	  armor = 30.0;
  };

  // Конструктор инициализации
  Warrior(std::string _name, std::string _gender, double _power, double _health, double _armor, Axe _weapon) 
	  :Characters::Characters(_name, _gender, _power, _health) {
	  armor = _armor;
	  weapon = _weapon;
  };

  // Конструктор копирования (по адресу)
  Warrior(const Warrior &w) :Characters::Characters(w.name, w.gender, w.power, w.health) {
	  armor = w.armor;
	  weapon = w.weapon;
  };
  void print_character_info() {
	  Characters::print_character_info();
	  std::cout << "Weapon: " << weapon.getName() << std::endl <<
		  "Weapon's damage: " << weapon.getDamage() << std::endl <<
		  "Weapon's strenght: " << weapon.getStrenght() << std::endl;
  }
};

