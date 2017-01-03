#ifndef WEAPON_H
#define WEAPON_H


typedef struct weapon {
  int strength;
  int durability;
  const char* name;
} weapon;

weapon* generateWeapon(int, int, const char*);
weapon* randomWeapon(int level);

#endif
