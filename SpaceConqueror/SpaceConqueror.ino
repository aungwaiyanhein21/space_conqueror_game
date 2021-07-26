//Aung Wai Yan Hein
//SpaceConqueror

#include <Arduboy2.h>
#include <Tinyfont.h>
#include "bits.h"
#include "globals.h"
#include "structs.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());


void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(30);
  for (int i=0; i<MAX_DUST; i++){
    dust[i].active = false;
  }
  for (int i=0;i< MAX_ENEMIES;i++){
        enemy[i].active = false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  if(!(arduboy.nextFrame())) return;

  switch (gameState){
    case TITLE_MODE:
      titleScreen();
      break;
    case GAME_MODE:
      gameScreen();
      break;
    case WIN_MODE:
      winScreen();
      break;
    case GAME_OVER_MODE:
      gameOverScreen();
      break;
  }
  if(arduboy.notPressed(A_BUTTON)){
      oncePressed = 0;
    }
  
  
 
  arduboy.display();

}



