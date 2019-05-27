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
unsigned long long lastSecondHand=0;
CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
Pix pix(NUM_LEDS);


PixArray<NUM_LEDS> pixArray(NUM_LEDS);
PixArray<NUM_LEDS> pixArray2(NUM_LEDS);

void setup() {
  delay( 3000 ); // power-up safety delay
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32); 
  randomSeed(analogRead(0)); 
  pix.setValue(CRGB::Red);
  reRand();
  startMillis=millis();
  lastSecondHand= (millis() / 1000) % 60;
  changePaletteRand();


  
}





void loop() { 


  whiteDim();
  whiteRandDim();
  whiteRandDimToGlow();
  
  
  twirlArray(); 
  
  spinArray(8);
  spinEvenly(-1);
  spinEvenlySlowing(1,-1);
  
  doubleSpin();
  doubleSpinSaturated();

  fireworks(NUM_LEDS);
  
  for (int i=0; i<10;i++) loopPalette(); //many effects in 1 (like 9 effects so foar?)


  
  //randEffect();
 



  
}








//////////////////////////////////////////////////
//Random Effects

void randEffect(){
  int num_effects=10;
  int effect = random(num_effects);
  switch (effect){
    case 0:
      spinArray(8); pix.addToIndex(1);
      break;
    case 1:
      twirlArray(); pix.addToIndex(1);
      break;
    case 2:
      spinEvenly(-1); pix.addToIndex(1);
      break; 
    case 3: 
      spinEvenlySlowing(1,-1); pix.addToIndex(1);
      break; 
         
    default:
      reRand();
      break;      
  }
}


void reRand(){
  //pix.randomValue();
  pixArray.randomValue();
  pixArray.randomIndex();
  
}



//////////////////////////////////////////////////
//Base Effects

void twirlArray(){
  pixArray.setActivePIX(8);
  pixArray.setIndexToIndex(); 
  pixArray.applyTo(leds); 
  showAndClear(); delay(80);
 

  //for max=arraylen*2^i
  //8*2^4=8*16=128

  //30*80= 2.4sec
  for(int i=0; i<30; i++){
    pixArray.squareIndex();
    pixArray.applyTo(leds); 
    showAndClear(); delay(80);
  }

  //reRand();
  
}













