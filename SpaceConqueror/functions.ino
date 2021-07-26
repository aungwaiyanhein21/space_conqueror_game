#include "globals.h"
#include "structs.h"

//Game Mode Functions
/* TITLE SCREEN */
void titleScreen(){
  tinyfont.setCursor(0,25);
  tinyfont.print("READY TO CONQUER SPACE?");
  
  tinyfont.setCursor(0,35);
  tinyfont.print("PRESS A TO BEGIN");

  if(arduboy.pressed(A_BUTTON)&& oncePressed == 0){
    oncePressed = 1;
    gameState = GAME_MODE;
  }
}

/* GAME SCREEN */
void gameScreen(){
  drawPlayer();
  playerMovement();
  dustParticle();
  enemyShip();
  bullet();
  
}

/* WIN SCREEN */
void winScreen(){
  arduboy.setCursor(0,25);
  arduboy.print("You Win!!");
  if(arduboy.pressed(A_BUTTON)&& oncePressed == 0){
    oncePressed = 1;
    gameState = GAME_OVER_MODE;
  }
}

/* GAME OVER */
void gameOverScreen(){
  arduboy.setCursor(0,25);
  arduboy.print("Game Over!!");
  if(arduboy.pressed(A_BUTTON)&& oncePressed == 0){
    oncePressed = 1;
    gameState = TITLE_MODE;
  }
}

//Game Mode functions





/*dust Particle */
void dustParticle(){
  int index;
  for(int i = 0; i<MAX_DUST;i++){
    updateDust(&dust[i]);
    drawDust(dust[i]);
  }
  index = rand()%MAX_DUST;
  if(!dust[index].active){
    randomDust(&dust[index]);
  }
}

void updateDust(Particle *dust){
  if(!(dust->active))return;
  dust->x -=1.5;
  if(dust->x <= 0){
    dust->active = false;
  }
}

void drawDust(Particle dust){
  if(!dust.active)return;
  arduboy.drawCircle(dust.x,dust.y,dust.particleSize,WHITE);
}

void randomDust(Particle *dust){
  dust->x = SCREEN_WIDTH-1;
  dust->y = rand()%SCREEN_HEIGHT;
  dust->particleSize= 0.0001+(rand()%2);
  dust->active = true;
}




