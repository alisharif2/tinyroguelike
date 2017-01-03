#ifndef ENTITY_H
#define ENTITY_H

#include "weapon.h"

typedef struct entity {
  int health;
  int armor;
  int speed;
  weapon* w;
  const char* name;
} entity;

entity* createEntity(int, int, int, weapon*, const char*);
void battle(entity*, entity*);
void printStats(entity*);

#endif
