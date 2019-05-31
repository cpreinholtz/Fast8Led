#define USE_OCTOWS2811
#include <OctoWS2811.h>
#include <FastLED.h>
#include "pix_array.h"  //this also incusdes pix.h

// Pin layouts on the teensy 3:
// OctoWS2811: 2,14,7,8,6,20,21,5

#define NUM_LEDS_PER_STRIP 194
#define NUM_STRIPS 8
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

unsigned long long startMillis=0;
unsigned long long lastSecondHand=0;
CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
Pix pix(NUM_LEDS);


PixArray<NUM_LEDS> pixArray(NUM_LEDS);
PixArray<NUM_LEDS> pixArray2(NUM_LEDS);

void setup() {
  delay( 3000 ); // power-up safety delay
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(16); 
  FastLED.setDither( 0 );
  
  randomSeed(analogRead(0)); 
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  pix.setValue(CRGB::Black);
  reRand();
  startMillis=millis();
  lastSecondHand= (millis() / 1000) % 60;
  changePaletteRand();


  
}


void loop() { 
    //while(1)showAndClear();showAndClear();
    testEffect();
    //randEffect();
    //showEffect(0);


}


void testEffect() { 
  
  
  
  //whiteDim();//works fine, kinda lame but maybey good transition
  //whiteRandDim();//again this is a cool transition, but kinda fleeting
  //whiteRandDimToGlow();//last part is fleeting,add delay
  //whiteRandDimToAllGlow();//stil broken, tries to do all at once...
  
  //spinEvenlyInGroupsOf(128,16);//slow start, add sparkle at the end

  //spinArray(500,1);//boring? make prop to NUM _LEDS//speed up?
  //spinEvenly(-1,20);//cool random patterns spinning with near sturation
  //spinEvenlySlowing(1,-1);//looks cool
  //spinEvenlyQuickening(1,180);//pretty spankin cool

  //twirl();  //need to test on the real deal
  

  
  //chase();//purple and orange// looks cool Only 5sec
  //chase2();//purple and orange  //same as chase but each pixel is a random color

  
    ////////////////IM Here kinda
  //doubleSpin(3,15);//dim,delay   // 40 del is slow // 15 del is quick , prob looks cool
  //doubleSpinSaturated(10,20,80);//dim,delay, min LEDS per color //looks cool 10S green and blue opposing
  
  //perStrip();  //kinda boring, this is just the blue with white lines
  //perStripAdditive();//odd flash every 16 but the color fade looks cool
  //perStripPersistentAdditive();//flash every 32, interesting but not amazing
  //perStripPersistent();//not bad, colors are more striking b/c its not additive


  //colorWaveStatic(256);//nice fade, doesnt move
  //colorWaveMove();//pretty cool
  //harmonicWave(20);//cool
  //colorWaveChangeAll(1);//cool
  //colorWaveTemporal(16,10);//kinda cool
  //blueWaveStatic(16);
  
  //blueWaveTemporal(16,0);//cool
  //blueWaveMovingTemporal(16,1);
  
  //pulse();
  
  //loopPalette();//rand pallete  //looks fine, fix timing?
  




  
  //fireworks(NUM_LEDS/2);//looks cool
  //fireworks(NUM_LEDS);//too saturated?
  //fireworksClear(NUM_LEDS);//kinda cool and flashy?
  
  //strobeStrip();//good
  //strobeColor();  //good
  //strobeColorQuickening();//really cool

  //flashRand();  
  //flashRedFast();
  flashRandWithRedFast();
  //flashRedSuperFast();   
  //flashWarning();     
    //flashAllVal(10,50,50,CRGB::Red);//flashes, timeon timeoff, val
    //delay(1000);  
    //flashAsIs(3,1000,300);//flashes, timeon timeoff
  


}







