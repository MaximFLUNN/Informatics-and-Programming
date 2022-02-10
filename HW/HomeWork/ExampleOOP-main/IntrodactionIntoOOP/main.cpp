#include "Game.h"

int main() {
  Warrior user_0001;
  Axe user_0002_weapon("Knife", 5.0, 30);
  Warrior user_0002("Garrosh Hellscream", "male", 40.0, 100.0, 30.0 , user_0002_weapon);
  Warrior user_0003(user_0002);
  // Вызов функции для объекта класса 
  std::cout << "============================================" << std::endl;
  user_0001.print_character_info();
  std::cout << "============================================" << std::endl;
  user_0002.print_character_info();
  std::cout << "============================================" << std::endl;
  user_0003.print_character_info();
  std::cout << "============================================" << std::endl;

  system("pause");
  return 0;
}