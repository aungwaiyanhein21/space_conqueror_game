#ifndef GLOBALS_H
#define GLOBALS_H

//screen width and screen height 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//Game Mode 
#define TITLE_MODE 0
#define GAME_MODE 1
#define WIN_MODE 2
#define GAME_OVER_MODE 3

/* Player */
#define PLAYER_SIZE 16

/* Enemy */
#define ENEMY_SIZE 16

/* Dust Particle */
#define MAX_DUST 50

/* enemy */
#define MAX_ENEMIES 2

/* bullet */
#define BULLET_WIDTH 6
#define BULLET_HEIGHT 3

//Variables 
/* Game state variables */
unsigned char gameState = TITLE_MODE;
int oncePressed = 0;

/* player x and y position */
int playerX = 20;
int playerY = 32;

/*enemy */
int currentEnemyCount = 0;

/* bullet */
int state = 0;


//Function prototypes
/* Game State functions */
void titleScreen();
void gameScreen();
void winScreen();
void gameOverScreen();


/* dust particles */
/*
void dustParticle();
void updateDust(Particle *dust);
void drawDust(Particle dust);
void randomDust(Particle *dust);
*/


/* player */
void drawPlayer();
void playerMovement();

/*enemy */
//void drawEnemyShip(EnemyShip enemy);





#endif


