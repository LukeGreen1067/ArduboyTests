#include <Arduboy2.h>
#include <math.h>

Arduboy2 arduboy;

#define MAPWIDTH 16
#define MAPHEIGHT 8
#define BOXSIZE 8
#define PI 3.1415926535


struct{
  float xpos, ypos, playerAngle, deltaX, deltaY;
} player;



const unsigned char gameMap[MAPWIDTH*MAPHEIGHT] =
{
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,
    1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

void drawPlayer(){
  arduboy.drawRect(player.xpos, player.ypos, 4, 4);
  arduboy.drawLine(player.xpos+2, player.ypos+2, player.xpos+player.deltaX*2, player.ypos+player.deltaY*2);
}

void checkButtons(){
  if(arduboy.pressed(LEFT_BUTTON))  {player.playerAngle-=0.1; if(player.playerAngle < 0){player.playerAngle+=2*PI;} player.deltaX=cos(player.playerAngle)* 5; player.deltaY = sin(player.playerAngle)*5;}
  if(arduboy.pressed(RIGHT_BUTTON)) {player.playerAngle+=0.1; if(player.playerAngle > 2*PI){player.playerAngle-=2*PI;} player.deltaX=cos(player.playerAngle)* 5; player.deltaY = sin(player.playerAngle)*5;}
  if(arduboy.pressed(UP_BUTTON))    {player.xpos+=player.deltaX; player.ypos+=player.deltaY;}
  if(arduboy.pressed(DOWN_BUTTON))  {player.xpos-=player.deltaX; player.ypos-=player.deltaY;}
}

void drawMap2D(){
  for(int y = 0; y<MAPHEIGHT; y++){
    for(int x = 0; x<MAPWIDTH; x++){
      if(gameMap[(y*MAPWIDTH) + x] == 1){arduboy.drawRect(x*BOXSIZE, y*BOXSIZE, BOXSIZE, BOXSIZE);}
    }
  }
}

void draw3Drays(){
  int r,mx,my,mp,dof;
  float rx,ry,ra,xo,yo;


  ra = player.playerAngle;
  for(r=0;r<1;r++){
    dof = 0;
    float aTan=-1/tan(ra);
    if(ra>PI){ry=(((int)player.ypos>>6)<<6)-0.0001;  rx =(player.ypos - ry) * aTan+player.xpos; yo=-64; xo=-yo*aTan;}
    if(ra<PI){ry=(((int)player.ypos>>6)<<6)+64;      rx =(player.ypos - ry) * aTan+player.xpos; yo= 64; xo=-yo*aTan;}
    if(ra==0 || ra==PI) {rx = player.xpos; ry = player.ypos; dof = 8;}
    while (dof < 8) {
      mx = (int) (rx) >> 6; my = (int)(ry)>>6; mp=my*MAPHEIGHT+mx;
      if(mp<MAPHEIGHT*MAPWIDTH && gameMap[mp] == 1){dof = 8;}
      else{ rx+=xo; ry+=yo; dof+=1;}
    }
  }
  arduboy.drawLine(player.xpos+2, player.ypos+2, rx, ry);
}

void setup() {
  // put your setup code here, to run once:
  player.xpos = 64; player.ypos = 32; player.deltaX = cos(player.playerAngle)*5; player.deltaY = sin(player.playerAngle)*5;
  arduboy.begin();
  arduboy.setFrameRate(10);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(!arduboy.nextFrame()){
    return;
  }

  arduboy.clear();
  arduboy.print(arduboy.cpuLoad());
  arduboy.pollButtons();
  checkButtons();
  drawMap2D();
  draw3Drays();
  drawPlayer();
  arduboy.display();
}
