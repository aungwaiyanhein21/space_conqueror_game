#include "globals.h"

void enemyShip(){

  randomEnemyShip(&enemy[0]);
  drawEnemyShip(enemy[0]);
  updateEnemyShip(&enemy[0]);
  
  /*
  for (int i = 0; i<MAX_ENEMIES;i++){
    updateEnemyShip(&enemy[i]);
    drawEnemyShip(enemy[i]);
  }
  currentEnemyCount ++;  
  randomEnemyShip(&enemy[currentEnemyCount-1]);
  for (int i= 0; i< currentEnemyCount; i++){
    updateEnemyShip(&enemy[i]);
  }
  */
  
  
}
/* Draw Enemy */
void drawEnemyShip(EnemyShip enemy){
  if (!enemy.active) return;
  arduboy.drawBitmap(enemy.x,enemy.y,EnemySpaceShip,ENEMY_SIZE,ENEMY_SIZE,WHITE);
}

void updateEnemyShip(EnemyShip *enemy){
  if(!(enemy->active)) return;
  enemyShipMovement(enemy);
}

void enemyShipMovement(EnemyShip *enemy){
 
  //Horizontal movement
 
  if (enemy->enemyCheckRight == 1){
    if (enemy->x < 65){
      enemy->x = enemy->x+enemy->x;
    }else{
      enemy->x ++;
    }
    
  }
  if (enemy->enemyCheckRight == -1){
    if (enemy->x+ENEMY_SIZE > SCREEN_WIDTH-1){
      enemy->x = (enemy->x-(enemy->x+ENEMY_SIZE-SCREEN_WIDTH))-1;
    }else{
      enemy->x --;
    }
  }
  
  
  /* setting enemyCheckRight depending on x position */
  
  if (enemy->x<65){
    enemy->enemyCheckRight = 1; 
  }
  if (enemy->x+ ENEMY_SIZE > SCREEN_WIDTH){
    enemy->enemyCheckRight = -1;
  }
  
  
  

  //Vertical Movement
  if (enemy->enemyCheckDown == 1){
    if(enemy->y < 0){
      enemy->y = (enemy->y - enemy->y)+1;
    }else{
      enemy->y ++;
    }
  }
  if (enemy->enemyCheckDown == -1){
    if (enemy->y+ENEMY_SIZE > SCREEN_HEIGHT-1){
      enemy->y = (enemy->y - (enemy->y +ENEMY_SIZE-SCREEN_HEIGHT))-1;
    }else{
      enemy->y --;
    }
    
  }
  /* setting enemyCheckDown depending on y position */
  if (enemy->y <=0){
    enemy->enemyCheckDown = 1;
  }
  if (enemy->y+ENEMY_SIZE >= SCREEN_HEIGHT){
    enemy->enemyCheckDown = -1;
  }

  
}

void randomEnemyShip(EnemyShip *enemy){
  enemy->enemyCheckRight = 1;
  enemy->enemyCheckDown = 1;
  enemy->x = SCREEN_WIDTH - ENEMY_SIZE;
  enemy->y = 32;
  enemy->active = true;
}



