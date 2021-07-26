#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct particle{
  bool active;
  byte particleSize,type;
  float x, y;
}Particle;

Particle dust[MAX_DUST];

typedef struct enemyShip{
   bool active;
   byte x,y;
   int enemyCheckRight, enemyCheckDown;
}EnemyShip;

EnemyShip enemy[MAX_ENEMIES];

typedef struct playerBullet{
  byte x,y;
}Bullet;

Bullet playerBullet;




#endif


