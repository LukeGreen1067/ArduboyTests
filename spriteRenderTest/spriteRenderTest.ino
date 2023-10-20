#include <Arduboy2.h>

Arduboy2 a;

#define MAIN_OFFSET	5

constexpr uint8_t frameRate = 10;

const unsigned char circuitdude[] PROGMEM = {
	0x00, 0x00, 0x80, 0xc0, 0x40, 0x60, 0xa0, 0xa0, 0xb0, 0xd0, 0xd8, 0xe8, 0xec, 0xe4, 0xf4, 0xf6, 0x1a, 0xe2, 0xfa, 0xfa, 0xfa, 0x36, 0x6, 0x3, 0x71, 0xfd, 0xfd, 0xfb, 0xf6, 0xec, 0xd8, 0x10, 0xd0, 0xd0, 0xb0, 0xb0, 0xa0, 0x60, 0x40, 0x40, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xe0, 0xff, 0xff, 0xff, 0xf, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf1, 0xe3, 0x7, 0xf, 0x7, 0x3, 0x00, 0x3, 0x3, 0x3, 0x3, 0xc1, 0x9d, 0x3c, 0x3c, 0x1e, 0xe, 0xee, 0xe0, 0xfd, 0x3, 0xfe, 0x00, 0xfc, 0x7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x80, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x7, 0xf, 0xf, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf, 0xf, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x3, 0xfc, 0x7, 0x40, 0x5f, 0x70, 0x67, 0x17, 0xb7, 0xb7, 0xd7, 0xd7, 0xdb, 0xdb, 0xbb, 0x7d, 0xfd, 0xfc, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc1, 0x83, 0x7, 0xe, 0xc, 0x8e, 0x87, 0xc3, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0x78, 0xbf, 0xdf, 0x61, 0x3e, 0x3, 0x00, 0x41, 0x5f, 0x5f, 0xdf, 0xee, 0xa0, 0x2f, 0x2f, 0x2f, 0xf7, 0x7, 0xe3, 0xf0, 0xfb, 0xfb, 0xfb, 0xfd, 0xfd, 0xfe, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3, 0xbd, 0xd0, 0xcf, 0xb9, 0x60, 0xc0, 0x80, 0x00, 0x00, 0xbf, 0x3f, 0x7f, 0xfa, 0xf6, 0xed, 0x83, 0x7f, 0xc0, 0xff, 0x80, 0x1f, 0x5f, 0x6f, 0xaf, 0xaf, 0xb7, 0xb7, 0x77, 0xf1, 0xee, 0xdf, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xbf, 0xc1, 0x7e, 0xd, 0x1b, 0x37, 0x67, 0x5b, 0xdc, 0xbd, 0x9d, 0xa3, 0x57, 0x67, 0x37, 0xf2, 0xb9, 0x9d, 0xa5, 0xb2, 0x7b, 0x79, 0x39, 0xa6, 0xde, 0x6f, 0x2e, 0x21, 0x27, 0x27, 0x2b, 0x2c, 0x2f, 0x2f, 0x2f, 0x2f, 0x36, 0x15, 0x13, 0x17, 0x17, 0x1b, 0x13, 0x11, 0x35, 0x2e, 0xee, 0x96, 0xba, 0xd9, 0xd9, 0xd3, 0xce, 0x98, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char dude[] PROGMEM = {
	0xff, 0xff, 0xff, 0x07, 0xf7, 0x07, 0x07, 0xff,
	0xfe, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00,
	0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
	0xff, 0xff, 0xff, 0x07, 0x07, 0xf7, 0x07, 0xff,
	0xfe, 0xfc, 0x00, 0x00, 0xff, 0xff, 0xff, 0xc7,
	0xd7, 0xd7, 0xc7, 0x07, 0x7f, 0x7f, 0x7f, 0x70,
	0x77, 0x74, 0x70, 0x7f, 0x3f, 0x1f, 0x00, 0x00,
	0x1f, 0x3f, 0x7f, 0x70, 0x77, 0x74, 0x70, 0x7f,
	0x3f, 0x1f, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x70,
	0x74, 0x77, 0x70, 0x7f, 0x3f, 0x1f, 0x00, 0x00,
	0x7f, 0x7f, 0x7f, 0x71, 0x75, 0x75, 0x71, 0x70,
};

const unsigned char ending_laughing_body[] PROGMEM = {
	0x01, 0x0e, 0xf0, 0x87, 0x3f, 0xdf, 0x6f, 0xb3, 
	0xdd, 0xde, 0xde, 0xbe, 0x7d, 0xfb, 0x77, 0xb7, 
	0xcf, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xfc, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xe7, 0x19, 0xde, 0x3f, 0x7f, 0x7e, 0x9d, 
	0xe1, 0xfb, 0xfa, 0xf6, 0xf4, 0xf4, 0x06, 0xfa, 
	0xfa, 0xfb, 0xa0, 0xb0, 0x98, 0xad, 0x76, 0xf8, 
	0xfb, 0xfb, 0xf7, 0xcf, 0x3f, 0x0f, 0x70, 0x3d, 
	0x3e, 0x3f, 0x3f, 0x3c, 0x03, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x38, 0x07, 0x3f, 
	0x02, 0x02, 0x02, 0x06, 0x05, 0x05, 0x05, 0x04, 
	0x05, 0x05, 0x05, 0x04
};

const unsigned char circuitman[] PROGMEM = { 0x30, 0x9f, 0xe1, 0x4d, 0x4d, 0xe1, 0x9f, 0x30 };

void setup() {
  a.begin();
  a.setFrameRate(frameRate);
}

void loop() {
  if(!a.nextFrame()) {
		return;
	}

  a.clear();

  //a.drawBitmap(8 - MAIN_OFFSET, 11, circuitdude, 48, 56, WHITE);

  //a.drawBitmap(55, 19, dude, 44, 16, WHITE);

  //a.drawBitmap(32, 36, ending_laughing_body, 58, 16, WHITE);

  a.drawBitmap(32, 36, circuitman, 8, 8, WHITE);

  a.display();
}
