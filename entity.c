#include <stdio.h>
#include <stdlib.h>
#include "entity.h"

entity* createEntity(int health, int armor, int speed, weapon* w, const char* name) {
  entity* e = (entity*) malloc(sizeof(entity));
  e->health = health;
  e->armor = armor;
  e->w = w;
  e->name = name;
  return e;
}

// Entity A will always have initiative
void battle(entity* a, entity* b) {
  if(a == NULL || b == NULL) return;
  int damage_done = a->w->strength - b->armor;
  if(damage_done > 0) b->health = b->health - damage_done;

  damage_done = b->w->strength - a->armor;
  if(damage_done > 0 && b->health > 0) a->health = a->health - damage_done;
}

void printStats(entity* e) {
  if(e != NULL)
    printf("Enemy Stats:\nName: %s\nHP: %d\nWeapon: %s\n",
        e->name, e->health, e->w->name);

  else
    puts("There is no enemy in sight!");
}

