#include <Arduboy2.h>

Arduboy2 a;

#define MAIN_OFFSET	5

#define FRAMERATE 2

#define FRAME_ONE 0
#define FRAME_TWO 1


//https://community.arduboy.com/t/make-your-own-arduboy-game-part-6-graphics/7929 this is the documentation/ tutorial for the sprite definitions however I will be using drawbitmap which is fine

const uint8_t PROGMEM miningGuyV2Right[][8] = {
{0x40, 0xbc, 0x66, 0xa6, 0xae, 0x6a, 0xb7, 0x42}, 
{0x40, 0xbc, 0xe6, 0xa6, 0xae, 0xea, 0xb7, 0x42}
}; //Right Frame 1 & 2

const uint8_t PROGMEM miningGuyV2Left[][8] = {
{0x42, 0xb7, 0x6a, 0xae, 0xa6, 0x66, 0xbc, 0x40},
{0x42, 0xb7, 0xea, 0xae, 0xa6, 0xe6, 0xbc, 0x40}
}; //Left Frame 1 & 2



void setup() {
  a.begin();
  a.setFrameRate(FRAMERATE);
}

void loop() {
  if(!a.nextFrame()) {
		return;
	}

  a.clear();

  //a.drawBitmap(8 - MAIN_OFFSET, 11, circuitdude, 48, 56, WHITE);

  //a.drawBitmap(55, 19, dude, 44, 16, WHITE);

  //a.drawBitmap(32, 36, ending_laughing_body, 58, 16, WHITE);

  a.drawBitmap(32, 36, miningGuyV2Right[FRAME_ONE], 8, 8, WHITE);

  if(a.pressed(RIGHT_BUTTON)){
    a.drawBitmap(32, 36, miningGuyV2Right[FRAME_ONE], 8, 8, WHITE);
    a.drawBitmap(32, 36, miningGuyV2Right[FRAME_TWO], 8, 8, WHITE);
  }
  if(a.pressed(LEFT_BUTTON)){
    a.drawBitmap(32, 36, miningGuyV2Left[FRAME_ONE], 8, 8, WHITE);
    a.drawBitmap(32, 36, miningGuyV2Left[FRAME_TWO], 8, 8, WHITE);
  }

  a.display();
}
