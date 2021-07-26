#include "globals.h"
#include "structs.h"


void bullet(){
  if (arduboy.pressed(A_BUTTON)&& oncePressed == 0){
    oncePressed = 1;
    state = 1;
  }
  
  if(state == 1){
   updateBullet(&playerBullet);
  drawBullet(playerBullet);
  bulletPosition(&playerBullet);
  }
  
  if(arduboy.notPressed(A_BUTTON)){
      oncePressed = 0;
    }
  
}

void drawBullet(Bullet playerBullet){
  arduboy.drawBitmap(playerBullet.x,playerBullet.y,PlayerBullet,BULLET_WIDTH,BULLET_HEIGHT,WHITE);
}

void updateBullet(Bullet *playerBullet){
    (playerBullet->x)++;
    if (playerBullet->x > 126){
      state = 0;
    }
}

void bulletPosition(Bullet *playerBullet){
  playerBullet->x = playerX+PLAYER_SIZE+1;
  playerBullet->y = playerY+(PLAYER_SIZE/2);
}


