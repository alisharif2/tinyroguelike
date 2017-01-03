#include <stdlib.h>
#include "weapon.h"

weapon* generateWeapon(int strength, int durability, const char* name) {
  weapon* w = (weapon*) malloc(sizeof(weapon));
  w->strength = strength;
  w->durability = durability;
  w->name = name;
  return w;
}

weapon* randomWeapon(int level) {
  static char* weapon_names[] = {"Axe", "Mace", "Warhammer", "Sword"};
  weapon* w = (weapon*) malloc(sizeof(weapon));
  w->strength = (rand() % level) / 2;
  w->durability = (rand() % level) / 4;
  w->name = weapon_names[rand() % 3];
  return w;
}
