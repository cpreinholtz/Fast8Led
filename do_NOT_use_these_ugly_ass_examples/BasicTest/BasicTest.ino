#include "array.h"

//OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);
ledArray myArray;

void setup() {
  myArray.begin();
  myArray.show();
}

#define NONE   0x000000
#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF

// Less intense...
#define RED    0x160000
#define GREEN  0x001600
#define BLUE   0x000016
#define YELLOW 0x101400
#define PINK   0x120009
#define ORANGE 0x100400
#define WHITE  0x101010






void loop() {
  for (int i=0; i < myArray.numPixels(); i++) {
    clearAll();  
    myArray.setPixel(i, BLUE);
    myArray.show();
    delayMicroseconds(5000);
  }
  clearAll();
  delayMicroseconds(1000000);
  colorWipeAll();
}



void clearAll()
{
  for (int i=0; i < myArray.numPixels(); i++) {
    myArray.setPixel(i, NONE);
  }
}



void colorWipeAll(){
  int microsec = 500000 / myArray.numPixels();  // change them all in 2 seconds

  // uncomment for voltage controlled speed
  // millisec = analogRead(A9) / 40;

  colorWipe(RED, microsec);
  colorWipe(GREEN, microsec);
  colorWipe(BLUE, microsec);
  colorWipe(YELLOW, microsec);
  colorWipe(PINK, microsec);
  colorWipe(ORANGE, microsec);
  colorWipe(WHITE, microsec);
}


void colorWipe(int color, int wait)
{
  for (int i=0; i < myArray.numPixels(); i++) {
    myArray.setPixel(i, color);
    myArray.show();
    delayMicroseconds(wait);
  }
}

