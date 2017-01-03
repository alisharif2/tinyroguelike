#include <stdio.h>
#include <stdlib.h>
#include "weapon.h"
#include "entity.h"

#define PLAYER_HEALTH (100)
#define PLAYER_ARMOR (50)
#define PLAYER_SPEED (10)

int getAction() {
  int action;

  int menu_length = 4;
  const char* menu[menu_length];
  menu[0] = "Attack";
  menu[1] = "Examine";
  menu[2] = "Rest";
  menu[3] = "Explore";

  int i;
  for(i = 0;i < menu_length;++i) {
    printf("%d - %s\n", i, menu[i]);
  }

  putchar('>');
  scanf("%d", &action);

  return action;
}

int main(int argc, char** argv) {
  // Initialization routine
  entity* encounter = createEntity(-1, 0, 0, NULL, "Nothing");
  weapon* playerWeapon = generateWeapon(10, 10, "Novice Blade");
  entity* player = createEntity(PLAYER_HEALTH, 
      PLAYER_ARMOR, PLAYER_SPEED, playerWeapon, "Hero");
  int playerLvl = 1;

  // Game loop
  puts("Welcome to your doom. You awake in a camp.");
  while(player->health > 0) {
    puts("What do you wish to do?");
    switch(getAction()) {
      case 0:
        if(encounter->health > 0) {
          battle(player, encounter);
          if(encounter->health <= 0)
            printf("You have slain %s\n", encounter->name);
        }
        else puts("You attack nothing.");
        break;
      case 1:
        if(encounter->health > 0) printStats(encounter);
        else puts("You examine the dirt. It is not very interesting");
        break;
      case 2:
        if(encounter->health > 0) puts("You cannot rest now!");
        else if(player->health < PLAYER_HEALTH) player->health++;
        else puts("You are at max health");
        break;
      case 3:
        puts("While exploring you find a mysterious chest.");
        encounter = createEntity(10, 0, 0, 
            randomWeapon(playerLvl), "Goblin");

        printf("You have encountered a %s\n", encounter->name);
        break;
    }
  }
}
