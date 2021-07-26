#include "globals.h"

/* Draw Player */
void drawPlayer(){
  arduboy.drawBitmap(playerX,playerY,PlayerSpaceShip,PLAYER_SIZE,PLAYER_SIZE,WHITE);
}

void playerMovement(){
  //Moving horizontally
  if (arduboy.pressed(RIGHT_BUTTON)&& playerX+PLAYER_SIZE < 64){
      playerX ++;
  }

  if (arduboy.pressed (LEFT_BUTTON)&& playerX > 0){
      playerX -- ;
  }

  //Moving vertically
  if (arduboy.pressed(UP_BUTTON)&& playerY > 0){
      playerY --;
  }
  if (arduboy.pressed(DOWN_BUTTON)&& playerY+PLAYER_SIZE < SCREEN_HEIGHT-1){
      playerY ++;
  }
}





