#include <Arduboy2.h>

Arduboy2 arduboy;
BeepPin1 beep;

constexpr uint8_t frameRate = 40;

constexpr uint16_t toneLeft = beep.freq(200);
constexpr uint16_t toneRight = beep.freq(261);
constexpr uint16_t toneUp = beep.freq(523);
constexpr uint16_t toneDown = beep.freq(175);
constexpr uint16_t toneA = beep.freq(495);
constexpr uint16_t toneB = beep.freq(550);

constexpr uint8_t toneTime = 250 / (1000 / frameRate); // 10 being frame rate

void setup() {
  arduboy.begin();
  beep.begin();
  arduboy.setFrameRate(frameRate);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame()))
    return;
  
  beep.timer();
  
  arduboy.clear();

  beep.noTone();

  arduboy.pollButtons();

  arduboy.setCursor(4, 9);

  if(arduboy.pressed(LEFT_BUTTON))
    playTone(toneLeft, toneTime);
  if(arduboy.pressed(RIGHT_BUTTON))
    arduboy.print(F("You pressed the right button"));
  if(arduboy.pressed(UP_BUTTON))
    arduboy.print(F("You pressed the up button"));
  if(arduboy.pressed(DOWN_BUTTON))
    arduboy.print(F("You pressed the down button"));
  if(arduboy.pressed(A_BUTTON))
    arduboy.print(F("You pressed the a button"));
  if(arduboy.pressed(B_BUTTON))
    arduboy.print(F("You pressed the b button"));

  arduboy.display();
}

void playTone(uint16_t count, uint8_t frames)
{
  beep.tone(count, frames);
}
