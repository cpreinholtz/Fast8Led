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

void setup() {
  LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  LEDS.setBrightness(32); 
  randomSeed(analogRead(0)); 
  pix.setValue(CRGB::Red);
  reRand();
  startMillis=millis();
  lastSecondHand= (millis() / 1000) % 60;
  
}





void loop() { 



  
  //pix.addToIndex(1);


  randEffect();
 

  //showAndClear();
  //delayMicroseconds(100000);
  //delay(50);

  
}















//////////////////////////////////////////////////
//Random Effects

void randEffect(){
  int num_effects=10;
  int effect = random(num_effects);
  switch (effect){
    case 0:
      spinArray(); pix.addToIndex(1);
      break;
    case 1:
      twirlArray(); pix.addToIndex(1);
      break;
    case 2:
      spinEvenly(); pix.addToIndex(1);
      break; 
    case 3: 
      spinEvenlySlowing(); pix.addToIndex(1);
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
  pixArray.setIndexToIndex();
  showAndClear(); delay(50);

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

void spinArray(){
  pixArray.setIndexToIndex();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for(int i=0; i<NUM_LEDS; i++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);
  }  
}

void spinEvenly(){
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  for(int i=0; i<NUM_LEDS; i++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(20);
  }  
}



void spinEvenlySlowing(){
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  
  for(int VARdelay=20; VARdelay<80; VARdelay++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(VARdelay);    
  }  
}

void spinEvenlySlowing(){
  pixArray.spreadEvenly();
  showAndClear(); delay(20);
  //20*128 = 2.5 sec
  
  for(int VARdelay=20; VARdelay<80; VARdelay++){
    pixArray.addToIndex(1);
    pixArray.applyTo(leds); 
    showAndClear(); delay(VARdelay);    
  }  
}












///////////////////////////////////////////////////////
//Utility
  
// Set the first n leds on each strip to show which strip it is
void setNum(){    
  int sec=3;
  if (millis()-startMillis<sec*1000) {
    for(int i = 0; i < NUM_STRIPS; i++) {
      for(int j = 0; j <= i; j++) {
        leds[(i*NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
      }
    }
  }
}

//sets all led values to 0, does not effect pix objects
void clearAll(){
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(0,0,0);      
  }
}




void showAndClear(){
  pix.applyTo(leds);  
  if (millis()-startMillis<10000) setNum();
  LEDS.show();
  clearAll();
}










