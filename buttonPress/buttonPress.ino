#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {
  arduboy.begin();

  arduboy.setFrameRate(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame()))
    return;
  
  arduboy.clear();

  arduboy.setCursor(4, 9);

  if(arduboy.pressed(LEFT_BUTTON))
    arduboy.print(F("You pressed the left button"));
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
