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
  LEDS.setBrightness(255); 
  FastLED.setDither( 0 );
  plasmasetup();
  
  randomSeed(analogRead(0)); 
  pixArray.useAbsoluteIndexing();
  pixArray2.useAbsoluteIndexing();
  pix.setValue(CRGB::Black);
  reRand();
  startMillis=millis();
  lastSecondHand= (millis() / 1000) % 60;
  changePaletteRand();
  Serial.begin(115200);
  Serial.println("alive");
  

  
}

typedef void (*SimplePatternList[])();
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))


SimplePatternList allPatterns = {
  
  //while(1)showAndClear();showAndClear();
  //whiteDim,//works fine, kinda lame but maybey good transition
  //whiteRandDim,//again this is a cool transition, but kinda fleeting
 // whiteRandDimToGlow,//last part is fleeting,add delay
//  whiteRandDimToAllGlow,
  
  spinEvenlyInGroupsOf,//slow start, add sparkle at the end -- super cool. lots of ways to fuck with it. should try different colors as well as sudden direction change
  
 // spinArray, // 
 spinEvenly,//cool random patterns spinning with near sturation -- good mindfuck. we need to find a way to keep white out of some effects. it washes out the other colors.
  // spinEvenlySlowing,//looks cool -- draw out the slowdown longer towards the end. 
  spinEvenlyQuickening,//pretty spankin cool

  twirlArray,  //need to test on the real deal  
 // plasma,
  plasmaGamma,  
  octodemo,
  octodemo,
  octodemo,
  noiseDemo,  
 demo_reel_100,  
// cylon, //rainbow cycling through panels
 // colortemperature,  //rainbow effect. very pastelle. where is that gamma adjustment?
  chase,//purple and orange// looks cool Only 5sec
 // chase2,//purple and orange  //same as chase but each pixel is a random color
    ////////////////IM Here kinda
//  doubleSpin,//dim,delay   // 40 del is slow // 15 del is quick , prob looks cool
//  doubleSpinSaturated,//dim,delay, min LEDS per color //looks cool 10S green and blue opposing  
// perStrip,  //kinda boring, this is just the blue with white lines -- Randomize color selection? Like you said, find best color combos and select from those
// perStripAdditive,//odd flash every 16 but the color fade looks cool//fix colr choice? -- Cooler color choice. but also the flash of the color change is sorta bothersome
// perStripPersistentAdditive,//flash every 32, interesting but not amazing
 perStripPersistent,//not bad, colors are more striking b/c its not additive -- this one is the best of this bunch
 // colorWaveStatic(256),  //nice fade, doesnt move -- Seems broken. wont compile when this is the only effect. Also there was a semicolon instead of a comma.
 colorWaveMove,//pretty cool -- Is cool, Needs a version with more bold colors
 // harmonicWave,//cool -- cool, maybe try a little slower? not sure
 colorWaveChangeAll,//cool -- you can hear the generator swing as the colors change. cool effect though. we need to find a way to pick better colors across the board.
 colorWaveTemporal,//kinda cool -- a little hypnotic in a good way, but red green blue could be improved on
// blueWaveStatic,  
//  blueWaveTemporal,//cool
 blueWaveMovingTemporal,// this is the best of the blues for sure. lots to build on with this one
 //pulse, //freeze at the end isn't great unless it's transitioning to something appropriate. Needs a different color palette 
  pulseBrightest,
 // interpolateRedToCyan, //not bad. needs other colors.
loopPalette,//rand pallete  //looks fine, fix timing?
loopPalette,
  loopPalette,
  loopPalette,
  loopPalette,
  
//  fireworks,//looks cool -- needs a color shift
 // fireworksColor,
 fireworksClear,//kinda cool and flashy?
  
 sparkle,//better than fireworks. decay effect is great and we should use it other places. a little too slow at the end.
// strobeStrip,//can't use full bright white
// strobeColor,  //good "lightning" effect
// strobeColorQuickening,//really cool
// flashRand, //really works the generator
// flashRedFast, // named accurately
// flashRandWithRedFast, //LOL
// flashRedSuperFast, //LOL
// flashWarning,    //ROBOT VOICE - EMERGENCY EMERGENCY
    //flashAllVal(10,50,50,CRGB::Red);//flashes, timeon timeoff, val
    //delay(1000);  
    //flashAsIs(3,1000,300);//flashes, timeon timeoff
  

};


void loop() { 
    //while(1)showAndClear();showAndClear();
    //testEffect();
    randEffect();
    //demo_reel_100();
    //allEffects();
   Serial.println("hello");//
    //allPatterns[num]();


}

void randEffect(){
  int num=random(ARRAY_SIZE(allPatterns));
  allPatterns[num]();
}

void allEffects(){
  for (int num=0; num<ARRAY_SIZE(allPatterns); num++){
    allPatterns[num]();
  }
}


void testEffect() { 
  
  
  //while(1)showAndClear();showAndClear();
  //whiteDim();//works fine, kinda lame but maybey good transition
  //whiteRandDim();//again this is a cool transition, but kinda fleeting
  //whiteRandDimToGlow();//last part is fleeting,add delay
  //whiteRandDimToAllGlow();//stil broken, tries to do all at once...
  
  //spinEvenlyInGroupsOf(128,16);//slow start, add sparkle at the end
  
  //spinArray(500,1);//boring? make prop to NUM _LEDS//speed up?
  //spinEvenly(-1,20);//cool random patterns spinning with near sturation
  //spinEvenlySlowing(1,-1);//looks cool
  //spinEvenlyQuickening(1,180);//pretty spankin cool

  //twirlArray();  //need to test on the real deal
  
  //plasma();
  //plasmaGamma();
  
  //octodemo();



  //noiseDemo();
  
  //demo_reel_100();
  
  //cylon();

  //colortemperature();
  
  chase();//purple and orange// looks cool Only 5sec
  //chase2();//purple and orange  //same as chase but each pixel is a random color

  
    ////////////////IM Here kinda
  //doubleSpin(3,15);//dim,delay   // 40 del is slow // 15 del is quick , prob looks cool
  //doubleSpinSaturated(10,20,80);//dim,delay, min LEDS per color //looks cool 10S green and blue opposing
  
  //perStrip();  //kinda boring, this is just the blue with white lines
  //perStripAdditive();//odd flash every 16 but the color fade looks cool//fix colr choice?
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
  //pulseBrightest();

  //interpolate(CRGB::Red, CRGB::Cyan);
  
  
  //loopPalette();//rand pallete  //looks fine, fix timing?
  




  
  //fireworks(NUM_LEDS/2);//looks cool
  //fireworks(NUM_LEDS);//too saturated?
  //fireworksClear(NUM_LEDS);//kinda cool and flashy?
  //sparkle();reRand();
  
  //strobeStrip();//good
  //strobeColor();  //good
  //strobeColorQuickening();//really cool

  //flashRand();  
  //flashRedFast();
  //flashRandWithRedFast();
  //flashRedSuperFast();   
  //flashWarning();     
    //flashAllVal(10,50,50,CRGB::Red);//flashes, timeon timeoff, val
    //delay(1000);  
    //flashAsIs(3,1000,300);//flashes, timeon timeoff
  


}
