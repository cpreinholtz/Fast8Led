#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>
#include "pix.h"
// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

#define NUM_LEDS_PER_STRIP 16
#define NUM_STRIPS 8
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

unsigned long long startMillis=0;
CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
Pix pix(NUM_LEDS);

//Pix pixArray[NUM_STRIPS];
PixArray<100> pixArray;

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32); 
  randomSeed(analogRead(0)); 
  pix.randomValue();
  pixArray.randomValue();
  pixArray.randomIndex();
  startMillis=millis();
  
}





void loop() {
  



  
  pix.addToIndex(1);

  
 
  pixArray.applyTo(leds); 
  pix.applyTo(leds);  
  if (millis()-startMillis<10000) setNum();
  LEDS.show();
  clearAll();
  
  //delayMicroseconds(100000);
  delay(50);

  
}






void setNum(){
    // Set the first n leds on each strip to show which strip it is
  if (millis()-startMillis<10000) {
    for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j <= i; j++) {
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
      }
    }
  }
}

void clearAll(){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0,0,0);      
  }
}

